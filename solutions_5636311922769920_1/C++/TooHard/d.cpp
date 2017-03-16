#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)(x).size())
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define x first
#define y second
#define INF (0x3f3f3f3f)

typedef long long LL;
typedef pair<int, int> P2;
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}

const int MAXN = 105;
LL K, C, S;

// string print(string s, int lvl) {
//     string ans = s;
//     REP(i, lvl - 1) {
//         string temp = "";
//         REP(j, SZ(ans)) {
//             if (ans[j] == '1') {
//                 temp += "1111";
//             } else {
//                 temp += s;
//             }
//             if (SZ(temp) > 200) break;
//         }
//         ans = temp;
//     }
//     return ans;
// }

// int cal(vector<string> &xx) {
//     int ret = 0;
//     REP(i, SZ(xx[0])) {
//         int cnt = 0;
//         REP(j, SZ(xx)) {
//             cnt += xx[j][i] == '1';
//         }
//         maxa(ret, cnt);
//     }
//     return ret;
// }

// void try_solve_hard() {
//     string s = "0000";
//     {
//         vector<string> xx;
//         REP(i, 4) {
//             s[i] = '1';
//             xx.PB(print(s, 2));
//             s[i] = '0';
//         }
//         cout << cal(xx) << endl;
//         REP(i, 4) cout << xx[i] << endl;
//     }
//     {
//         vector<string> xx;
//         REP(i, 4) {
//             s[i] = '1';
//             xx.PB(print(s, 3));
//             s[i] = '0';
//         }
//         cout << cal(xx) << endl;
//         REP(i, 4) cout << xx[i] << endl;
//     }
//     {
//         vector<string> xx;
//         REP(i, 4) {
//             s[i] = '1';
//             xx.PB(print(s, 4));
//             s[i] = '0';
//         }
//         cout << cal(xx) << endl;
//         REP(i, 4) cout << xx[i] << endl;
//     }
//     {
//         vector<string> xx;
//         REP(i, 4) {
//             s[i] = '1';
//             xx.PB(print(s, 5));
//             s[i] = '0';
//         }
//         cout << cal(xx) << endl;
//         REP(i, 4) cout << xx[i] << endl;
//     }
//     // {
//     //     vector<string> xx;
//     //     REP(i, 5) {
//     //         s[i] = '1';
//     //         xx.PB(print(s, 5));
//     //         s[i] = '0';
//     //     }
//     //     cout << cal(xx) << endl;
//     //     REP(i, 5) cout << xx[i] << endl;
//     // }
// }

LL dp[MAXN][MAXN];
void solve_hard() {

    int know = 0;
    if (C >= K) know = K;
    else know = C;
    if ((K + know - 1) / know > S) {
        printf(" IMPOSSIBLE");
    } else {
        dp[2][2] = 2;
        for (int i = 3; i < MAXN; i++) {
            dp[2][i] = i + K * (i - 2);
        }
        LL temp = K;
        for (int i = 3; i < MAXN; i++) {
            temp *= K;
            for (int j = i; j < MAXN; j++) {
                dp[i][j] = temp * (j - i) + dp[i - 1][j];
            }
        }
        int cur = know;
        while (true) {
            cout << " " << dp[know][cur];
            if (cur == K) break;
            cur = min((int)K, cur + know);
        }
    }
}

void solve() {

    cin >> K >> C >> S;
    if (S == K) {
        REP(i, K) {
            LL cur = i;
            REP(j, C - 1) {
                cur *= K;
                cur += i;
            }
            cout << " " << cur + 1;
        }
    } else if (C == 1) {
        printf(" IMPOSSIBLE");
    } else {
     //   try_solve_hard();
        solve_hard();
    }
    cout << endl;
}

int main() {
    int test;
    cin >> test;
    REP(tt, test) {
        printf("Case #%d:", tt + 1);
        solve();
    }

    return 0;
}
