#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

#define TASKNAME ""

void solve(int test_number);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i);
    }
}

void solve(int test_number) {
    cout << "Case #" << test_number + 1 << ": ";
    int n;
    cin >> n;
    if (n == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }
    int used[10] = {0}, cnt = 0;
    int i;
    for (i = n; cnt < 10; i += n) {
        int tmp = i;
        while (tmp) {
            if (!used[tmp % 10]) {
                cnt++;
                used[tmp % 10] = 1;
            }
            tmp /= 10;
        }
    }
    cout << i - n << endl;
}
