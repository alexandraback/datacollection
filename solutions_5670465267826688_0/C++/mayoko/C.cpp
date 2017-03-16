#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

const int MAXL = 10010;
// 1つ目が符号(0が+,1が-),2つ目が記号(1,i,j,kの順)

bool solve(int L, int X, const string& s) {
    vector<pair<int, int> > dp(X*L+1);
    vector<bool> isK(X*L+1, false);
    string t;
    for (int i = 0; i < X; i++) t += s;
    dp[0] = make_pair(0, 0);
    for (int i = 1; i <= X*L; i++) {
        int sign = dp[i-1].first;
        int mark = dp[i-1].second;
        switch (t[i-1]) {
            case 'i':
                // 左がiかjなら符号反転
                if (mark == 1 || mark == 2) dp[i].first = 1-sign;
                else dp[i].first = sign;
                // 符号の変換
                switch (mark) {
                    case 0:
                        dp[i].second = 1;
                        break;
                    case 1:
                        dp[i].second = 0;
                        break;
                    case 2:
                        dp[i].second = 3;
                        break;
                    case 3:
                        dp[i].second = 2;
                        break;
                }
                break;
            case 'j':
                // 左がjかkなら符号反転
                if (mark == 2 || mark == 3) dp[i].first = 1-sign;
                else dp[i].first = sign;
                // 符号の変換
                switch (mark) {
                    case 0:
                        dp[i].second = 2;
                        break;
                    case 1:
                        dp[i].second = 3;
                        break;
                    case 2:
                        dp[i].second = 0;
                        break;
                    case 3:
                        dp[i].second = 1;
                        break;
                }
                break;
            case 'k':
                // 左がiかkなら符号反転
                if (mark == 1 || mark == 3) dp[i].first = 1-sign;
                else dp[i].first = sign;
                // 符号の変換
                switch (mark) {
                    case 0:
                        dp[i].second = 3;
                        break;
                    case 1:
                        dp[i].second = 2;
                        break;
                    case 2:
                        dp[i].second = 1;
                        break;
                    case 3:
                        dp[i].second = 0;
                        break;
                }
                break;
            default:
                dp[i] = dp[i-1];
                break;
        }
    }
    if (dp[X*L].first != 1 || dp[X*L].second != 0) return false;
//    for (int i = 0; i < X*L+1; i++) cout << dp[i].first << "  " << dp[i].second << endl;
    for (int i = X*L-1; i > 0; i--) {
        isK[i] = isK[i+1];
        if (dp[i].first == 0 && dp[i].second == 3) {
            isK[i] = true;
        }
    }
    for (int i = 1; i < X*L; i++) {
        if (dp[i].first == 0 && dp[i].second == 1) {
            if (isK[i]) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int L, X;
        cin >> L >> X;
        string s;
        cin >> s;
        if (solve(L, X, s)) printf("Case #%d: YES\n", t);
        else printf("Case #%d: NO\n", t);
    }
    return 0;
}
