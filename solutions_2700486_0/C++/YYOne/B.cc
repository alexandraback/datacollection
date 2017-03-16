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

int n, x, y;

i64 C[22][6];
void Init()
{
    C[0][0] = 1;
    for(int i=1; i<=20; i++)
	{
        C[i][0] = 1;
        for(int j=1; j<=6 && j<=i; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]);
    }
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    Init();
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d%d", &n, &x, &y);
        if(x < 0) x = -x;
        printf("Case #%d: ", cas);
        if((x+y)&1) {
            printf("0.0\n");
        }
        else if(n >= 15)
        {
            if(x+y <= 4) printf("1.0\n");
            else
            {
                int t = n - 15;
                if(x+y-4 > 2 || y+1 > t) printf("0.0\n");
                else
                {
                    if(y+1 <= 6)
                    {
                        double ans = 0;
                        if(t>=6+y+1) ans = 1.0;
                        else
                        {
                            int cc = 6;
                            while(t > cc) {
                                t-=2;
                                --y;
                                --cc;
                            }
                            for(int i=y+1; i<=t; i++)
                                ans += C[t][i]*pow(0.5, t);
                        }
                        printf("%.8f\n", ans);
                    }
                    else printf("0.0\n");
                }
            }
        }
        else if(n >= 6)
        {
            if(x+y <= 2) printf("1.0\n");
            else
            {
                int t = n - 6;
                if(x+y-2 > 2 || y+1 > t) printf("0.0\n");
                else
                {
                    if(y+1 <= 4)
                    {
                        double ans = 0;
                        if(t>=4+y+1) ans = 1.0;
                        else
                        {
                            int cc = 4;
                            while(t > cc) {
                                t-=2;
                                --y;
                                --cc;
                            }
                            for(int i=y+1; i<=t; i++)
                                ans += C[t][i]*pow(0.5, t);
                        }
                        printf("%.8f\n", ans);
                    }
                    else printf("0.0\n");
                }
            }
        }
        else if(n >= 1)
        {
            if(x+y <= 1) printf("1.0\n");
            else
            {
                int t = n - 1;
                if(x+y > 2 || y+1 > t) printf("0.0\n");
                else
                {
                    if(y+1 <= 2)
                    {
                        double ans = 0;
                        if(t>=2+y+1) ans = 1.0;
                        else
                        {
                            int cc = 2;
                            while(t > cc) {
                                t-=2;
                                --y;
                                --cc;
                            }
                            for(int i=y+1; i<=t; i++)
                                ans += C[t][i]*pow(0.5, t);
                        }
                        printf("%.8f\n", ans);
                    }
                    else printf("0.0\n");
                }
            }
        }
    }

    return 0;
}
