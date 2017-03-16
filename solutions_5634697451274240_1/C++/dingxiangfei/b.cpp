//
//  b.cpp
//  
//
//  Created by Xiang Fei Ding on 4/9/16.
//
//

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int a[100];

int main() {
    int t;
    cin>>t;
    for (int i = 0, len; i < t; ++i) {
        unsigned int c = 0;
        string s;
        cin>>s;
        len = s.length();
        for (int j = 0; j < len; ++j)
            a[j] = s[j] == '+';
        int back = len - 1;
        while (true) {
            while (back >= 0 && a[back])
                --back;
            if (back < 0)
                break;
            if (a[0]) {
                ++c;
                for (int front = 0; a[front] && front <= back; ++front)
                    a[front] = !a[front];
            }
            ++c;
            int p = 0, q = back;
            while (p <= q) {
                int x = !a[p], y = !a[q];
                a[p] = y; a[q] = x;
                ++p; --q;
            }
        }
        cout<<"Case #"<<i + 1<<": "<<c<<endl;
    }
    return 0;
}