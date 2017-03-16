#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>
#include <functional>
#include <map>

#define LL(a) (a<<1)
#define RR(a) (a<<1|1)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FOE(i,a,b) for(i=a;i<=b;i++)
#define FOD(i,a,b) for(i=a;i>=b;i--)
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin();it != (v).end();++it)
#define fordown(it,v) for (__typeof((v).rbegin()) it = (v).rbegin();it != (v).rend();++it)
#define iter(c) __typeof((c).begin())
#define Clr(a,b) memset(a,b,sizeof(a))
#define Cpy(a,b) memcpy(a,b,sizeof(a))
#define TTI template <class T> inline
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;

const double eps = 1e-8;
const double pi  = acos(-1.0);
const double inf = 1e20;
const int INF = (~0u)>>2;
const i64 INF64 = (~0uLL)>>2;

inline bool eq(double x, double y) { return (x-y<-eps)?0:x-y<eps; }
TTI T sqr(T x) { return x * x; }
TTI T gcd(T a, T b) { return (b)?gcd(b, a%b): a; }
u64 rand64(){
	return u64(rand()) ^ (u64(rand())<<15) ^ (u64(rand())<<30) ^ (u64(rand())<<45) ^ (u64(rand())<<60);
}
inline bool isAlphabet(char a) {
    return ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}
inline bool isDigit(char a) {
    return '0' <= a && a <= '9';
}

int f[15][6];
int v[15];

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        {
        /*map<i64,int> mym;
        i64 e, r, n;
        scanf("%lld%lld", &e, &r);
        scanf("%lld", &n);
        for(int i=0; i<n; i++)
        {
            i64 v;
            scanf("%lld", &v);
            if(mym.find(v) != mym.end())
                ++ mym[v];
            else
                mym[v] = 1;
        }
        i64 cur = e;
        i64 ans = 0;
        for(int i=0; i<n; i++)
        {
            if(cur == e)
            {
                iter(mym) it = mym.end();
                --it;
                i64 tmp = it->first;

                if(it->second > 1) --(it->second);
                else mym.erase(it);

                ans += cur * tmp;
                cur = r;
                if(cur > e) cur = e;
            }
            else
            {
                if(i != n-1)
                {
                    iter(mym) it = mym.begin();
                    i64 tmp = it->first;

                    if(it->second > 1) --(it->second);
                    else mym.erase(it);

                    i64 cost = 0;
                    if(cur + r > e)
                        cost = cur + r - e;
                    if(cost > e) cost = e;
                    ans += tmp * cost;
                    cur = cur + r - cost;
                    if(cur > e) cur = e;
                }
                else
                {
                    iter(mym) it = mym.begin();
                    ans += cur * (it->first);
                }
            }*/
            }

        int e, r, n;
        scanf("%d%d", &e, &r);
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", v+i);
        memset(f, -1, sizeof(f));
        f[0][e] = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<=e; j++)
                if(~f[i][j])
                {
                    for(int c=0; c<=j; c++)
                    {
                        int t = j-c+r;
                        if(t > e) t = e;
                        f[i+1][t] = max(f[i+1][t], f[i][j] + c*v[i]);
                    }
                }

        printf("Case #%d: %lld\n", cas, f[n][min(r,e)]);
    }

    return 0;
}

