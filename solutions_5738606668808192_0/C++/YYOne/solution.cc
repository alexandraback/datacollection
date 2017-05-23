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

    template<class T> inline T chmod(T n, T m) {
        return (n % m + m) % m;
    }

    template<class T> inline T __extgcd(T a, T b, T & x, T & y) { //gcd(a,b) == a*x + b*y
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

    template<class T> T lcm(T a, T b) {
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

    struct Int128 {
        unsigned int a[8];
        bool neg;
        Int128(ll x) {
            neg = false;
            if(x < 0) {
                neg = true;
                x = -x;
            }
            for(int i=0; i<8; ++i) {
                a[i] = x & 0xffff;
                x >>= 16;
            }
        }
        const bool operator == (const Int128 & y) const {
            if(neg ^ y.neg) return false;
            for(int i=0; i<8; ++i) {
                if(a[i] != y.a[i]) {
                    return false;
                }
            }
            return true;
        }
        const bool operator < (const Int128 & y) const {
            if(neg ^ y.neg) return neg;
            for(int i=7; i>=0; --i) {
                if(a[i] != y.a[i]) {
                    return a[i] < y.a[i];
                }
            }
            return false;
        }
        const bool operator <= (const Int128 & y) const {
            return *this < y || *this == y;
        }
        const Int128 operator * (const Int128 & y) const {
            Int128 x(0);
            for(int i=0; i<8; ++i) {
                for(int j=0; i+j<8; ++j) {
                    x.a[i+j] += a[i] * y.a[j];
                }
            }
            for(int i=0, t=0; i<8; ++i) {
                x.a[i] += t;
                t = x.a[i] >> 16;
                x.a[i] &= 0xffff;
            }
            x.neg = neg ^ y.neg;
            return x;
        }
        ll toll() {
            ll ret = 0;
            for(int i=7; i>=0; --i) {
                ret <<= 16;
                ret |= a[i];
            }
            return ret;
        }
    };

    TTI void checkmax(T & a, T b) { if(b>a) a=b; }
    TTI void checkmin(T & a, T b) { if(b<a) a=b; }
    TTI T sqr(T x) { return x*x; }
    inline int sgn(double x) { if(x < -eps) return -1; if(x > eps) return 1; return 0; }

    const int cx[] = {-1, 0, 1, 0};
    const int cy[] = {0, 1, 0, -1};
}
using namespace Orz;
const int N = 100100;

ll v[10];

void output(int x) {
    vector<int> ret;
    while(x) {
        ret.pb(x&1);
        x >>= 1;
    }
    reverse(ret.begin(), ret.end());
    for(int i : ret) printf("%d", i);
}

ll change(int x, int b) {
    ll ret = 0;
    ll bas = 1;
    while(x) {
        ret += (x & 1) * bas;
        bas *= b;
        x >>= 1;
    }
    return ret;
}

void gao() {
    int n, m;
    scanf("%d%d", &n, &m);
    int tot = 0;
    for(int i=1<<(n-1); i<(1<<n); ++i) {
        if(i & 1) {
            bool yes = true;
            for(int j=2; j<=10; ++j) {
                ll x = change(i, j);
                ll tmp = -1;
                for(ll k=2; k*k<=x; ++k) {
                    if(x % k == 0) {
                        tmp = k;
                        break;
                    }
                }
                if(tmp == -1) {
                    yes = false;
                    break;
                }
                v[j-2] = tmp;
            }
            if(yes) {
                output(i);
                for(int j=0; j<9; ++j) printf(" %lld", v[j]);
                puts("");
//                for(int j=0; j<9; ++j) printf(" %d", change(i, j + 2));
//                puts("");
                ++ tot;
                if(tot == m) break;
            }
        }
    }
}

void check() {
    freopen("C-small-attempt0.out", "r", stdin);
    char str[100];
    gets(str);
    for(int i=0; i<50; ++i) {
        scanf("%s", str);
        puts(str);
        for(int j=0; j<9; ++j) {
            scanf("%d", &v[j]);
        }
        string s = str;
        for(int j=2; j<=10; ++j) {
            if(stoll(s, nullptr, j) % v[j-2]) {
                printf("ERROR case %d\n", i);
                return;
            }
        }
    }
}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);

    int T, cas = 0;
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d:\n", ++cas);
        gao();
    }

//    check();

    return 0;
}





















