//Coder: Balajiganapathi
//#define TRACE
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

const int mx = 155;

int n, m;
int flights[mx][2];
vi g[mx];
int pin[mx], rank[mx], inv[mx];
int mat[mx][mx];
pi tmp[mx];


vi pos(vi v) {
    deque<int> q;
    q.pu(v[0]);

    re(i, 1, sz(v)) {
        int x = v[i];
        while(sz(q) && mat[q.back()][x] == 0) q.pop_back();

        if(sz(q) == 0) return vi(n, oo);
        q.pu(x);
    }

    vi ret;
    fr(i, sz(v)) ret.pu(rank[v[i]]);
    return ret;
}

vi solve(int s) {
    vi ret;
    vi vis(n);
    deque<int> q;
    q.pu(s);
    ret.pu(rank[s]);
    vis[s] = 1;
    
    while(sz(ret) < n) {
        int best = -1;
        int from = -1;
        fr(i, sz(q)) {
            int x = q[i];
            fr(i, sz(g[x])) {
                int y = g[x][i];
                if(vis[y]) continue;
                if(best == -1 || rank[y] <= rank[best]) {
                    best = y;
                    from = x;
                }
            }
        }
        
        if(best == -1) return vi(n, oo);
        vis[best] = 1;
        ret.pu(rank[best]);

        while(q.back() != from) q.pop_back();
        q.pu(best);
    }

    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small0.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases, kase;
    scanf("%d", &kases);
    for(kase = 1; kase <= kases; ++kase) {
        cin >> n >> m;
        fr(i, n) cin >> pin[i];
        fr(i, m) cin >> flights[i][0] >> flights[i][1];

        fr(i, n) g[i].clear();

        ini(mat, 0);
        fr(i, m) {
            fr(j, 2) --flights[i][j];
            g[flights[i][0]].pu(flights[i][1]);
            g[flights[i][1]].pu(flights[i][0]);

            mat[flights[i][0]][flights[i][1]] = 1;
            mat[flights[i][1]][flights[i][0]] = 1;
        }
        fr(i, n) tmp[i] = mp(pin[i], i);
        sort(tmp, tmp + n);
        fr(i, n) {
            rank[tmp[i].se] = i;
            inv[i] = tmp[i].se;
        }

        vi ans = solve(0);
        fr(i, n) ans = min(ans, solve(i));

        vi p;
        fr(i, n) p.pu(i);

        do {
            ans = min(ans, pos(p));
        } while(next_permutation(all(p)));

        printf("Case #%d: ", kase);
        fr(i, n) printf("%d", pin[inv[ans[i]]]);
        printf("\n");
    }
    
	return 0;
}
