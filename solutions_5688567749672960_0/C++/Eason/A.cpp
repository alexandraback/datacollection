#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int T;
ull N;

ull rever(int n) {
    ull res = 0;
    while (n > 0) {
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve() {
    ull tmp = N, res = 1, tmp2;
    while (N != 1) {
        tmp = rever(N);
        tmp2 = rever(tmp);
        if (N > tmp && tmp2 == N) {
            N = tmp;
        } else {
            --N;
        }
        ++res;
    }
    cout << res << endl;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> T;
    for (int caseID = 1; caseID <= T; ++caseID) {
        cin >> N;
        cout << "Case #" << caseID << ": ";
        solve();
    }
    return 0;
}
