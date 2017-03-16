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

    #define foreach(i,a) for(auto i=begin(a); i!=end(a); ++i)
    #define TTI template <class T> inline

    #define mt make_tuple
    #define pb push_back
    #define eb emplace_back

    #define rbmap(T) tree<T, T, less<T>, rb_tree_tag, tree_order_statistics_node_update>
    #define rbset(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
    #define pairheap(T) __gnu_pbds::priority_queue<T, less<T>, pairing_heap_tag>
    //tree:find_by_order order_of_key heap:modify,join

    #define fastcin ios::sync_with_stdio(0);cin.tie(0);
    #define error(args...) {auto _v = split(#args, ','); err(begin(_v), args); }

    using namespace std;
    using namespace __gnu_cxx;
    using namespace __gnu_pbds;

    vector<string> split(const string& s, char c) {
        vector<string> v;
        stringstream ss(s);
        string x;
        while(getline(ss,x,c)) v.pb(x);
        return move(v);
    }

    void err(vector<string>::iterator it) {}

    template<typename T, typename... Args>
    void err(vector<string>::iterator it, T a, Args... args) {
        cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
        err(++it, args...);
    }

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
    TTI void read(T &x) {
        while((cread=getchar())<'0'); x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
    }

    TTI void getInt(T & x) {
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

    TTI T chmod(T n, T m) {
        return (n % m + m) % m;
    }

    TTI T __extgcd(T a, T b, T & x, T & y) { //gcd(a,b) == a*x + b*y
        if(b == 0) {
            x = 1; y = 0; return a;
        } else {
            T d = __extgcd(b, a % b, x, y);
            T t = x;
            x = y;
            y = t - (a / b) * y;
            return d;
        }
    }

    template<class T> struct CRT {
        T m, r;
        CRT(T m = 1, T r = 0) : m(m), r(r) {}

        CRT crtMerge(CRT b) {
            CRT ret, a = *this;
            T g, x, y;
            g = __extgcd(a.m, b.m, x, y);
            a.r %= a.m;
            b.r %= b.m;
            if((b.r - a.r) % g) return CRT(-1, -1);
            ret.m = a.m / g * b.m;
            x = chmod((b.r - a.r) / g * x, b.m / g);
            ret.r = chmod(a.m * x + a.r, ret.m);
            return ret;
        }
    };

    TTI T lcm(T a, T b) {
        return a / __gcd(a, b) * b;
    }

    struct date {
        int year, month, day;
    };

    int days(date x) {
        static int month_day[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        month_day[1] = 28;
        int year = x.year-1;
        int days = year * 365 + year/4 - year/100 + year/400;
        if((x.year%4==0 && x.year%100!=0) || x.year%400==0) month_day[1]++;
        for(int i=0; i<x.month-1; i++)
            days += month_day[i];
        days += x.day-1;
        return days;
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

bool check(const vector<pair<int,int>> & v, int sum) {
    for(int i=0; i<v.size(); ++i) {
        if(sum & 1) {
            if(v[i].first >= sum / 2) {
                return false;
            }
        } else {
            if(v[i].first > sum / 2) {
                return false;
            }
        }
    }
    return true;
}

int mat[55][55];

void full(int x, int b) {
    rep(i, 0, x+1) {
        rep(j, i+1, x+1) {
            mat[i][j] = 1;
        }
    }
    rep(i, 0, x + 1) {
        mat[i][b-1] = 1;
    }
}

void gao() {
    int b;
    ll m;
    scanf("%d%lld", &b, &m);
    if(m > (1ll << (b - 2))) {
        puts(" IMPOSSIBLE");
        return;
    }
    puts(" POSSIBLE");
    clr(mat, 0);
    for(int x=0; x<b; ++x) {
        if((1ll<<x) >= m) {
            if((1ll<<x) == m) {
                full(x, b);
            } else {
                full(x-1, b);
                mat[b-2][b-1] = 1;
                for(int i=0; i<x-1; ++i) {
                    if(m & (1ll<<i)) {
                        mat[i+1][b-2] = 1;
                    }
                }
            }
            rep(i, 0, b) {
                rep(j, 0, b) {
                    printf("%d", mat[i][j]);
                }
                puts("");
            }
            return;
        }
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int T, cas = 0;
    read(T);
    while(T--) {
        printf("Case #%d:", ++cas);
        gao();
    }

    return 0;
}






















