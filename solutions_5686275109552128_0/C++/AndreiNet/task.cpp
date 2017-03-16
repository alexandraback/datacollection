#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void solve(int testNumber) {
    cout << "Case #" << testNumber << ": ";

    int N;
    cin >> N;
    vector<int> A(N);

    int maxval = 0;
    for (int& p: A) {
        cin >> p;
        maxval = max(maxval, p);
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= maxval; ++i) {
        int time = 0;
        for (int p: A)
            time += (p - 1) / i;
        ans = min(ans, time + i);
    }
    cout << ans << '\n';
}

int main() {
    //freopen("task.in", "r", stdin);
    //freopen("task.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        solve(test);
    }
}
