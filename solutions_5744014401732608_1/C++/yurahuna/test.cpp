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

        vector<vector<int>> a(B, vector<int>(B, 0));
        rep(i, B - 1) {
            rep2(j, i + 1, B - 1) {
                a[i][j] = 1;
            }
        }

        int temp = pow(2, B - 3);
        for (int i = B - 2; i >= 1; i--) {
            if (M >= temp) {
                M -= temp;
                a[i][B - 1] = 1;
            }
            temp /= 2;
        }

        if (M == 1) {
            M -= 1;
            a[0][B - 1] = 1;
        }

        cout << "Case #" << t + 1 << ": ";
        if (M == 0) {
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
