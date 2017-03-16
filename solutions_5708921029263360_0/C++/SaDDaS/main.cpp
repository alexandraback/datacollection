//    In the name of God
#include <bits/stdc++.h>
#define For(i,x,y) for(__typeof(y)i=(x)-((x)>(y));i!=(y)-((x)>(y));i+=1-2*((x)>(y)))
#define rep(i , n) for(int (i) = (0); (i) < (n); ++(i))
inline int in() { int x; scanf("%d", &x); return x; }
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define all(x) x.begin() , x.end()
#define REP(i , c) for(auto i : c)
#define sz(x) (((int)x.size()))
#define mp make_pair
#define pb push_back
#define pp pop_back
#define S second
#define F first
//#define cerr if(0)cerr
//#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long double dd;
typedef long long ll;
/*#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OS;*/
constexpr int inf = 1e9 + 7, base = 541;
constexpr int mod = 1e9+7, N = 1e6 + 7;


int32_t main(){ _
    int T; cin >> T;
    for(int tt = 1; tt <= T; tt++) {
        int a, b, c, k;
        vector<pair<pii, int> > v;
        cin >> a >> b >> c >> k;
        for(int i = 1; i <= a; i++)
            for(int j = 1; j <= b; j++)
                for(int l = 1; l <= c; l++)
                    v.push_back({{i, j}, l});
        int mx = 0, ans = 0;
        for (int i = (1<<(sz(v)))-1; i >= 0; --i) if(mx < __builtin_popcount(i)){
            int o[10][10][10] = {};
            int p = 0, x = i, bul = 1;
            while (x) {
                if ((x & 1)) {
                    int q = v[p].F.F, w = v[p].F.S, e = v[p].S;
                    if(++o[0][w][e] > k) {
                        bul = 0;
                        break;
                    }
                    if(++o[q][w][0] > k) {
                        bul = 0;
                        break;
                    }
                    if(++o[q][0][e] > k) {
                        bul = 0;
                        break;
                    }
                }
                x>>=1; p++;
            }
            int blt =  __builtin_popcount(i);
            if(bul && blt)
                mx = blt, ans = i;
        }
        cout <<  "Case #" << tt << ": " << mx << endl;
        int p = 0, x = ans;
        while (x) {
            if ((x & 1)) {
                int q = v[p].F.F, w = v[p].F.S, e = v[p].S;
                cout << q << ' ' << w << ' ' << e << endl;
            }
            x>>=1; p++;
        }
    }
}