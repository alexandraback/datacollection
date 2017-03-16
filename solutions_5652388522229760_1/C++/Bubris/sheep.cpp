#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long countsheep(long long n) {
    bool digit[10];
    int seen = 0;
    long long m, k;
    int d, i;
    for (int i = 0; i < 10; i++) {
        digit[i] = false;
    }
    i = 0;
    while (seen < 10) {
        i++;
        m = n * i;
        while (m > 0) {
            d = m % 10;
            if (digit[d] == false) {
                digit[d] = true;
                seen++;
            }
            m = m / 10;
        }
    }

    return n * i;
}

int main () {
    int t;
    long long n;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> n;
        cout << "Case #" << i << ": ";
        if (n == 0) {
            cout << "INSOMNIA" << endl;
        } else {
            cout << countsheep(n) << endl;
        }
    }
    return 0;
}
