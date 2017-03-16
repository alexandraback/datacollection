#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/rope>
namespace Orz {
    #define clr(a,b) memset(a, b, sizeof(a))
    #define cpy(a,b) memcpy(a, b, sizeof(a))
    #define rep(i,a,b) for(int i=a; i<b; i++)
    #define per(i,a,b) for(int i=b-1; i>=a; i--)
    #define foreach(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)
    #define iter(c) __typeof((c).begin())
    #define TTI template <class T> inline
    #define pb(a) push_back(a)
    #define mp(a,b) make_pair(a,b)
    #define rbmap(T) tree<T, T, less<T>, rb_tree_tag, tree_order_statistics_node_update>
    #define rbset(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
    #define pairheap(T) __gnu_pbds::priority_queue<T, less<T>, pairing_heap_tag>
    //tree:find_by_order order_of_key heap:modify,join
    #define fastcin ios::sync_with_stdio(0);cin.tie(0);

    using namespace std;
    using namespace __gnu_cxx;
    using namespace __gnu_pbds;

    typedef long long ll;
    typedef unsigned long long uu;
    typedef pair<int,int> pii;

    const int INF = 0x3f3f3f3f;
    int MOD = 1e9+7;

    const double eps = 1e-8;
    const double inf = 1e20;
    const double pi = acos(-1.0);

    char cread;
    bool cfushu;
    inline void read(int &x) {
        while((cread=getchar())<'0'); x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
    }
    inline void read(ll &x) {
        while((cread=getchar())<'0'); x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
    }
    inline void read(char *x) {
        while((cread=getchar())<'a'); (*x++) = cread;
        while((cread=getchar())>='a') (*x++) = cread;
        *x = 0;
    }
    inline void getInt(int & x) {
        while((cread=getchar())<'-');
        if(cread == '-') cfushu = true, x = 0;
        else cfushu = false, x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
        if(cfushu) x = -x;
    }
    inline void getInt(ll & x) {
        while((cread=getchar())<'-');
        if(cread == '-') cfushu = true, x = 0;
        else cfushu = false, x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
        if(cfushu) x = -x;
    }

    inline int add(int a, int b) { a += b; if(a >= MOD) a -= MOD; return a; }
    inline int mul(int a, int b) { return ll(a) * ll(b) % MOD; }
    inline int powmod(int x, int y) {
        int ret = 1;
        while(y) {
            if(y & 1) ret = mul(ret, x);
            x = mul(x, x);
            y >>= 1;
        }
        return ret;
    }
    inline int __extgcd(int a, int b, int &x, int &y) { //gcd(a,b) == a*x + b*y
        if(b == 0) {
            x = 1; y = 0; return a;
        } else {
            int ret = __extgcd(b, a%b, x, y);
            int temp = x;
            x = y;
            y = temp - a/b*y;
            return ret;
        }
    }

    TTI void checkmax(T & a, T b) { if(b>a) a=b; }
    TTI void checkmin(T & a, T b) { if(b<a) a=b; }
    TTI T sqr(T x) { return x*x; }
    inline int sgn(double x) { if(x < -eps) return -1; if(x > eps) return 1; return 0; }

    const int cx[] = {-1, 0, 1, 0};
    const int cy[] = {0, 1, 0, -1};
}
using namespace Orz;
const int N = 100100;

int c, d, v;
int a[N];
vector<int> vvv;

bool dfs(int x, int n, set<int> s) {
    if(x == n) {
        rep(i, 1, v + 1) if(!s.count(i)) {
            return false;
        }
        return true;
    }
    rep(i, 0, vvv.size()) {
        set<int> ns = s;
        for(auto & it : s) {
            rep(j, 1, c + 1) {
                if(it + j * vvv[i] <= v) ns.insert(it + j * vvv[i]);
            }
        }
        if(dfs(x + 1, n, ns)) return true;
    }
    return false;
}

void gao() {
    scanf("%d%d%d", &c, &d, &v);
    set<int> s;
    rep(i, 0, d) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    vvv.clear();
    rep(i, 1, v + 1) {
        if(!s.count(i)) {
            vvv.pb(i);
        }
    }
    set<int> ss;
    ss.insert(0);
    rep(i, 0, d) {
        set<int> ns = ss;
        for(auto & it : ss) {
            rep(j, 1, c + 1) {
                if(it + j * a[i] <= v)
                    ns.insert(it + j * a[i]);
            }
        }
        ss = ns;
    }
    rep(i, 0, v + 1) {
        if(dfs(0, i, ss)) {
            printf("%d\n", i);
            return;
        }
    }
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int T, cas(0);
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d: ", ++cas);

        gao();
    }

    return 0;
}
























