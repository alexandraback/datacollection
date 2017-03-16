#include <bits/stdc++.h>
using namespace std;
#define GET4(_1,_2,_3,_4,...) _4
#define rep_(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) GET4(__VA_ARGS__,repi,rep_,)(__VA_ARGS__)
#define all(c) begin(c),end(c)
template<class C>inline void uniq(C&c){c.erase(unique(all(c)),end(c));}
template<class T>inline bool chmin(T&a,const T&b){return a>b&&(a=b,1);}
template<class T>inline bool chmax(T&a,const T&b){return a<b&&(a=b,1);}

const int N = 128;
const int M = 2 * N;
int n, m;
vector<int> a[M];

void input()
{
    cin >> n;
    m = 2 * n - 1;
    rep(i, m) {
        a[i].resize(n);
        rep(j, n) cin >> a[i][j];
    }
}

const int inf = 10000;
bool used[N];
int table[M];

void solve()
{
    memset(used, 0, sizeof(used));
    memset(table, 0, sizeof(table));

    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mn = inf, mx = -1;
        rep(i, m) if (not used[i]) {
            chmin(mn, a[i][lo]);
            chmax(mx, a[i][hi]);
        }
        int cn = 0, cx = 0;
        rep(i, m) if (not used[i]) {
            cn += a[i][lo] == mn;
            cx += a[i][hi] == mx;
        }
        if (cn == 2) {
            rep(i, m) if (not used[i]) {
                if (a[i][lo] == mn) {
                    used[i] = true;
                    rep(j, n) table[lo + j] ^= a[i][j];
                }
            }
            ++lo;
        } else if (cx == 2) {
            rep(i, m) if (not used[i]) {
                if (a[i][hi] == mx) {
                    used[i] = true;
                    rep(j, n) table[hi + j] ^= a[i][j];
                }
            }
            --hi;
        } else {
            if (lo != hi) {
                cout << cn << ' ' << cx << " -> " << lo << ' ' << hi << endl;
            }
            assert(lo == hi);
            rep(i, m) if (not used[i]) {
                if (a[i][lo] == mn) {
                    used[i] = true;
                    rep(j, n) table[lo + j] ^= a[i][j];
                }
            }
            rep(i, n) cout << table[lo + i] << (i < n-1 ? " " : "\n");
            return;
        }
    }
}

int main()
{
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": ";
        solve();
    }
}
