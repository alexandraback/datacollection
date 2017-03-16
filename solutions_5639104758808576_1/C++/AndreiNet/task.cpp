#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

//Submited wrong source for Small Input. Sorry :((

void solve(int testNumber) {
    cout << "Case #" << testNumber << ": ";

    int N;
    string S;
    cin >> N >> S;

    int s = 0, ans = 0;
    for (int i = 0; i <= N; ++i) {
        int x = S[i] - '0';
        if (s < i) {
            ans += i - s;
            s = i;
        }
        s += x;
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
