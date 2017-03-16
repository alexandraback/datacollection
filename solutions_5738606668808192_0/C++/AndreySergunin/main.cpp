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
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    long long m = 1 << (n / 2 - 1);
    for (; k > 0; ++m) {
        if (m % 2 == 0)
            continue;
        vector<long long> a;
        long long m1 = m;
        for (int i = 0; i < n / 2; ++i) {
            a.push_back(m1 & 1);
            m1 /= 2;
        }
        for (int i = 0; i < n / 2; ++i)
            cout << a[i];
        for (int i = 0; i < n / 2; ++i)
            cout << a[i];
        cout << " ";
        for (int i = 2; i <= 10; ++i) {
            long long cur = 0;
            long long s = 1;
            for (int j = n / 2 - 1; j >= 0; --j) {
                cur += s * a[j];
                s *= i;
            }
            cout << cur << " ";
        }
        --k;
        cout << endl;
    }
    return 0;
}