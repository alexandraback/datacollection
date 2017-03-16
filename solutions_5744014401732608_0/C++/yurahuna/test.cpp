#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    cin >> T;
    rep(t, T) {
        int B, M;
        cin >> B >> M;

        int N = B * (B - 1) / 2;    // num of edge
        bool flag = false;
        vector<vector<int>> a;
        rep(s, 1 << N) {
            a.resize(B, vector<int>(B, 0));
            int h = 0;
            int w = 1;
            rep(i, N) {
                a[h][w] = (s >> i) & 1;
                w++;
                if (w == B) {
                    h++;
                    w = h + 1;
                }
            }

            vector<int> dp(B, 0);
            dp[0] = 1;
            rep(i, B) {
                rep2(j, i + 1, B) {
                    if (a[i][j]) {
                        dp[j] += dp[i];
                    }
                }
            }

            if (dp[B - 1] == M) {
                flag = true;
                break;
            }

            // rep(i, B) {
            //     rep(j, B) {
            //         cout << a[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }

        cout << "Case #" << t + 1 << ": ";
        if (flag) {
            cout << "POSSIBLE" << endl;
            rep(i, B) {
                rep(j, B) {
                    cout << a[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

}
