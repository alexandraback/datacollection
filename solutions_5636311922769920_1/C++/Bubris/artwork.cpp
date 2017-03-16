#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    for (int i = 0; i < b; i++) {
        res = res * a;
    }
    return res;
}

void artwork(long long k, long long c, long long s) {
    long long block, check;
    if (s < (k + c - 1) / c) {
        cout << " IMPOSSIBLE";
        return;
    }

    check = 1;
    for (int i = 0; i < (k + c - 1) / c; i++) {
        block = 1;
        for(int j = 1; j <= c; j++) {
            block += (check - 1) * power(k, c-j);
            if (check < k) {
                check++;
            }
        }
        cout << " " << block;
    }
    return;

}

int main () {
    int t, k, c, s;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        cin >> k >> c >> s;
        cout << "Case #" << j << ":";
        artwork(k, c, s);
        cout << endl;
    }
    return 0;
}
