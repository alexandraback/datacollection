#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;
    for (int t = 0; t < test; ++t) {
        cout << "Case #" << t + 1 << ": ";
        vector<int> a(10);
        long long n;
        cin >> n;
        if (n == 0) {
            cout << "INSOMNIA\n";
            continue;
        }
        long long k = 1;
        for (; ; ++k) {
            long long m = k * n;
            while (m > 0) {
                a[m % 10] = 1;
                m /= 10;
            }
            bool f = true;
            for (int i = 0; i < 10; ++i)
                if (a[i] == 0)
                    f = false;
            if (f)
                break;
        }
        cout << k * n << endl;
    }
    return 0;
}