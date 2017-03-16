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

int num[15];

bool solve(int c, int d)
{
    if(d == 1) return true;
    if(d == c) return true;
    return false;
}

bool solve(int a, int b, int d)
{
    if(d == 1) return true;
    if(a == d) return true;
    if(b == d) return true;
    if(a * b == d) return true;
    return false;
}

bool solve(int a, int b, int c, int d)
{
    if(d == 1) return true;
    if(a == d) return true;
    if(b == d) return true;
    if(c == d) return true;
    if(a * b == d) return true;
    if(a * c == d) return true;
    if(b * c == d) return true;
    if(a * b * c == d) return true;
    return false;
}

int v1[10];
int v2[10];
int v3[10];

int main()
{
    freopen("C-small-1-attempt1.in", "r", stdin);
    freopen("C-small-1-attempt1.out", "w", stdout);


    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int r, n, m, k;
        scanf("%d%d%d%d", &r, &n, &m, &k);
        printf("Case #%d:\n", cas);
        for(int i=0; i<10; i++)
        v1[i] = v2[i] = v3[i] = i;
        random_shuffle(v1+2, v1+m+1);
        random_shuffle(v2+2, v2+m+1);
        random_shuffle(v3+2, v3+m+1);

        while(r--)
        {
            for(int i=0; i<k; i++)
                scanf("%d", &num[i]);
            if(n == 3)
            {
                for(int i=2; i<=m; i++)
                for(int j=2; j<=m; j++)
                for(int k=2; k<=m; k++)
                {
                    bool can = true;
                    for(int t=0; t<k; t++)
                        if(!solve(v1[i], v2[j], v3[k], num[t]))
                        {
                            can = false;
                            break;
                        }
                    if(can)
                    {
                        printf("%d%d%d\n", v1[i], v2[j], v3[k]);
                        goto sss;
                    }
                }
                sss:;
            }
            else
            if(n == 2)
            {
                for(int i=2; i<=m; i++)
                for(int j=2; j<=m; j++)
                {
                    bool can = true;
                    for(int t=0; t<k; t++)
                        if(!solve(v1[i], v2[j], num[t]))
                        {
                            can = false;
                            break;
                        }
                    if(can)
                    {
                        printf("%d%d", v1[i], v2[j]);
                        goto ss;
                    }
                }
                ss:;
            }
            else
            {
                for(int i=2; i<=m; i++)
                {
                    bool can = true;
                    for(int t=0; t<k; t++)
                        if(!solve(v1[i], num[t]))
                        {
                            can = false;
                            break;
                        }
                    if(can)
                    {
                        printf("%d\n", v2[i]);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

