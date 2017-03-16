#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
    freopen("1A1.in", "r", stdin);
    freopen("1A1.out", "w", stdout);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        string s;
        cin >> s;
        int i = 0;
        long long a = 0;
        long long b = 0;
        while (s[i] != '/') {
            a = a * 10 + s[i] - '0';
            i++;
        }
        i++;
        while (i < s.length()) {
            b= b * 10 + s[i] - '0';
            i++;
        }
        long long a1 = a;
        long long b1 = b;
        while (a1 != 0 && b1 != 0) {
            if (a1 < b1)
                b1 = b1 % a1;
            else
                a1 = a1 % b1;

        }
        long long nod = 0;
        if (a1 == 0)
            nod = b1;
        else
            nod = a1;
        if (nod != 1) {
            a = a / nod;
            b = b / nod;
        }
        long long c = 1;
        int k = 0;
        while (c < b) {
            c *= 2;
            k++;
        }
        long long c2 = 1;
        int k1 = 0;
        while (c2 < a) {
            c2 *= 2;
            k1++;
        }
        //k1--;
        if (a == 1)
            k1 = 1;
        if (c != b) {
            cout << "Case #" << q + 1 << ": " << "impossible" << endl;

        }
        else
        if (a >= (b / 2))
            cout << "Case #" << q + 1 << ": " << 1 << endl;
        else
            cout << "Case #" << q + 1 << ": " << k - k1 + 1 << endl;
    }

}
