//
// Created by e5430 on 2016/5/1.
//

#include <vector>
#include <iostream>
#include <string>
#include <c++/cstring>
#include <math.h>
#include <stdlib.h>
using namespace std;

void fill(string& t, int i,  char c)
{
    for(int j = i;j < t.size(); ++j)
    {
        if(t[j] =='?')
            t[j] = c;
    }
}
void t(string& a, string& b, int i)
{

    if(a[i] == '?' && b[i] == '?') {

        string a1 = a, b1 = b;
        a1[i] = '1';
        b1[i] = '0';
        string a2 = a, b2 = b;
        a2[i] = '0';
        b2[i] = '1';
        string a3 = a, b3 = b;
        a3[i] = '0';
        b3[i] = '0';
        if (i < a.size() - 1) {
            t(a1, b1, i);
            t(a2, b2, i);
            t(a3, b3, i + 1);
        }
        int x1 = abs(atoi(a1.c_str()) - atoi(b1.c_str()));
        int x2 = abs(atoi(a2.c_str()) - atoi(b2.c_str()));
        int x3 = abs(atoi(a3.c_str()) - atoi(b3.c_str()));
        if (x1 < x3 && x1 < x2) {
            a = a1;
            b = b1;
        }
        else if (x2 < x3) {
            a = a2;
            b = b2;
        }
        else {
            a = a3;
            b = b3;
        }

    }
    else  if(a[i] =='?') {

        string a1 = a, b1 = b;
        a1[i] = b[i];
        if (b[i] == '0') {
            string a2 = a, b2 = b;
            a2[i] = b[i] + 1;
            if (i < a.size() - 1) {
                t(a2, b2, i);
                t(a1, b1, i + 1);
            }
            if (abs(atoi(a2.c_str()) - atoi(b2.c_str())) < abs(atoi(a1.c_str()) - atoi(b1.c_str()))) {
                a = a2;
                b = b2;
            }
            else {
                a = a1;
                b = b1;
            }

        }
        else if (b[i] == '9') {
            string a2 = a, b2 = b;
            a2[i] = b[i] - 1;
            if (i < a.size() - 1) {
                t(a2, b2, i);
                t(a1, b1, i + 1);
            }
            if (abs(atoi(a1.c_str()) - atoi(b1.c_str())) < abs(atoi(a2.c_str()) - atoi(b2.c_str()))) {
                a = a1;
                b = b1;
            }
            else {
                a = a2;
                b = b2;
            }
        }
        else {
            string a2=a, b2=b;
            string a3=a, b3=b;
            a2[i] = b[i] -1;
            a3[i] = b[i] +1;
            if(i < a.size() -1) {
                t(a1, b1, i + 1);
                t(a2, b2, i );
                t(a3, b3, i );
            }
            int x1 = abs(atoi(a1.c_str()) - atoi(b1.c_str()));
            int x2 = abs(atoi(a2.c_str()) - atoi(b2.c_str()));
            int x3 = abs(atoi(a3.c_str()) - atoi(b3.c_str()));
            if(x3 < x1 && x3 < x2) {
                a = a3;
                b = b3;
            }
            else if(x1 < x2) {
                a = a1;
                b = b1;
            }
            else {
                a = a2;
                b = b2;
            }
        }

    }
    else  if(b[i] =='?') {
        t(b, a, i);

    }
    else{
        if(a[i] < b[i])
        {
            fill(a, i, '9');
            fill (b, i, '0');
        }
        else if(a[i] ==b[i]) {
            if (i < a.size() - 1) {
                t(a, b, i + 1);

            }
        }
        else
        {
            fill(a, i, '0');
            fill( b, i, '9');
        }
    }
}
void solve() {
    string a, b;
    cin >> a >> b;

    t(a, b, 0);
    std::cout << a << " " << b << "\n";
}

int main() {
    int c;
    cin >> c;
    for(int i =0; i < c;++i)
    {
        std::cout << "Case #" << i +1 << ": ";
        solve();
    }
    return 0;
}