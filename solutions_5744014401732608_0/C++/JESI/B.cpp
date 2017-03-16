#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010


int main() {
//    #if defined JESI
        freopen("B-small-attempt0.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

//    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
//        cout << ">> " << cs + 1 << endl;
        ll b, m;
        cin >> b >> m;

        ll mx = (1LL << (b - 2LL));

        cout << "Case #" << cs + 1 << ":" << ' ' << (m <= mx? "POSSIBLE": "IMPOSSIBLE") << endl;

        if (mx >= m) {
            vector < vector <int> > grid (b, vector <int> (b, 0));

            for (int i = 0; i < b; i++) {
                for (int j = i + 1; j < b; j++) {
                    grid[i][j] = 1;
                }
            }

            vector <ll> ways(b);
            ways[b - 1] = 1;

            ll two = 1LL;
            for (int i = b - 2; i >= 0; i--) {
                ways[i] = two;
                two *= 2LL;
            }

            ll extra = mx - m;

            for (int i = 1; i < b; i++) {
                if (extra - ways[i] >= 0) {
                    extra -= ways[i];
                    grid[0][i] = 0;
                }
            }

            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    cout << grid[i][j];
                }
                cout << endl;
            }
        }
    }


    return 0;
}






