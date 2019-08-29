#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// assign a value to each element of a vector
void assign(int& num){
        static int val = 1;
        num = val++;
}

// print out each element
void print(int num){
        cout << num << " ";
}

void foo() {
        cout << "inside foo()\n";
}

void bar() {
        cout << "inside bar()\n";
}


int main(){
        vector<int> vec(10);

        // output initial value of each element
        for_each(vec.begin(), vec.end(), print);
        cout << endl;

        // assign a value to each element of a vector
        for_each(vec.begin(), vec.end(), assign);

        // output updated value of each element
        for_each(vec.begin(), vec.end(), print);


        /*********************************************************************/

        // output initial value of each element
        // for_each(vec.begin(), vec.end(), print); becomes ==>
        for_each(vec.begin(), vec.end(), [](int num) {
                cout << num << " ";
        });
        cout << endl;

        // assign a value to each element of a vector
        // notice '&' with num
        // for_each(vec.begin(), vec.end(), assign); becomes ==>
        for_each(vec.begin(), vec.end(), [](int& num) {
                static int val = 1; num = val++;
        });

        // output updated value of each element
        for_each(vec.begin(), vec.end(), [](int num) {
                cout << num << " ";
        });

        /*********************************************************************/

        // 1st lambda function
        auto func  = []() {
                             foo();
                             bar();
                     };

        // the lambda function does something here
        func();

        // 2nd lambda function
        vector<int> arr(5, 99);
        for_each(arr.begin(), arr.end(), [](int num ){
                cout << num << "\n";
        });

        /*********************************************************************/

        // (1)
        cout << [] (int a, int b){return a*b; } (4, 5) << endl; // 20

        // (2)
        auto func2 = [](int a, int b) {
                             return a*b;
                     };
        cout << func2(4, 5) << endl; // 20

        /*********************************************************************/

        /* case #1 - compiler deduces return type */
        cout << [] (int n) {return n*n;} (5) << endl;

        /* case #2 - explicit return type */
        cout << [] (int n)->int {return n*n;} (5);

        return 0;
}
