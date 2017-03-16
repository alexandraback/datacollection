#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)

#ifdef ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif

#define pb emplace_back
#define lb lower_bound
#define ul unsigned long
#define ull unsigned long long
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define fs first
#define sd second

#define ALL(c) (c).begin(),(c).end()

#define DBG0(x)    {if(DEBUG){ cout << #x << ": " << x << "\t"; }}
#define DBG(x)     {if(DEBUG){DBG0(x); cout << endl;}}
#define DBG2(x, y) {if(DEBUG){DBG0(x); DBG(y);}}
#define DBG3(x, y, z) {if(DEBUG){DBG0(x); DBG2(y, z);}}
#define DBG4(w, x, y, z) {if(DEBUG){DBG0(w); DBG3(x, y, z);}}

template <class T>
ostream& operator<<(ostream& os, vector<T> xs){ for(T x: xs) os << x << ' '; return os; }
template <class S, class T>
ostream& operator<<(ostream& os, pair<S,T> st){ os << "(" << st.first << "," << st.second <<")"; return os; }

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

vint solve(int n, vector<vint> vss) {
    rep (i, (1 << (2*n - 1))) {
        int r = __builtin_popcount(i);
        int c = (2*n - 1) - r;
        if (r != c + 1) continue;
        vector<vint> row;
        vector<vint> col;
        rep(j, 2*n - 1) {
            if ((1 << j) & i) 
                row.pb(vss[j]);
            else
                col.pb(vss[j]);
        }
        sort(ALL(row), [](vint a, vint b) { return a[0] < b[0]; });
        sort(ALL(col), [](vint a, vint b) { return a[0] < b[0]; });
        int skip = -1;
        bool ok = true;
        rep(x, n) {
            if (!ok) continue;
            if (skip == -1 && x == n - 1) {
                skip = n - 1;
                break;
            }
            int flg = (skip != -1) ? 1 : 0;
            rep(y, n) {
                if (row[y][x] != col[x - flg][y]) {
                    if (flg) {
                        ok = false;
                        break;
                    } else {
                        skip = x;
                        break;
                    }
                }
            }
        }
        if (ok) {
            vint ret;
            rep(j, n) {
                ret.pb(row[j][skip]);
            }
            return ret;
        }
    }
}

int main(void){
    int n;
    cin >> n;
    rep(i, n) {
        int N;
        cin >> N;
        vector<vector<int>> vss = vector<vint>(2*N - 1, vint(N));
        rep(j, 2*N - 1) {
            rep(k, N) {
                cin >> vss[j][k];
            }
        }
        vint ans = solve(N, vss);
        cout << "Case #" << i + 1 << ":";
        rep (j, N) 
            cout << " " << ans[j];
        cout << endl;

    }
    return 0;
}
