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

const int MAX_N = 1005;

void solve(int test_number) {
    int n, e[MAX_N];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> e[i];
        e[i]--;
    }
    int ans = 0, mx[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        int used[MAX_N] = {0}, ord = 1, j;
        for (j = i; used[j] == 0; j = e[j]) {
            used[j] = ord++;
        }
        if (ord - used[j] == 2 && e[e[i]] != i) {
            mx[j] = max(mx[j], ord - 3);
        }
        ans = max(ans, ord - used[j]);
    }
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (e[e[i]] == i) {
            ans2 += mx[i] + 1;
        }
    }
    cout << "Case #" << test_number + 1 << ": ";
    cout << max(ans, ans2) << endl;
}
