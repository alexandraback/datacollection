#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

int solve(int Smax, const string& s) {
    vector<int> num(Smax+1);
    for (int i = 0; i <= Smax; i++) num[i] = s[i]-'0';
    int ret = 0;
    int sum = num[0];
    for (int i = 1; i <= Smax; i++) {
        ret = max(ret, max(0, i-sum));
        sum += num[i];
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int Smax;
        string s;
        cin >> Smax >> s;
        printf("Case #%d: %d\n", t, solve(Smax, s));
    }
    return 0;
}
