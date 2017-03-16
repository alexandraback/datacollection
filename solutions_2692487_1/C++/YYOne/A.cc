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

int A, N;

int a[150];
i64 f[110][110];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        scanf("%d%d", &A, &N);
        for(int i=0; i<N; i++)
            scanf("%d", &a[i]);
        sort(a, a+N);
        Clr(f, -1);
        f[0][0] = A;
        for(int i=0; i<N; i++)
            for(int j=0; j<=i; j++)
            if(f[i][j] != -1)
            {
                if(a[i] >= f[i][j])
                {
                    f[i+1][j+1] = max(f[i+1][j+1], f[i][j]);
                    int t = j;
                    while(f[i][t] <= a[i] && t <= 100)
                    {
                        f[i][t+1] = max(f[i][t+1], f[i][t]*2-1);
                        ++ t;
                    }
                    if(f[i][t] > a[i])
                    {
                        f[i+1][t] = max(f[i+1][t], f[i][t] + a[i]);
                    }
                }
                else
                {
                    f[i+1][j] = max(f[i+1][j], f[i][j] + a[i]);
                }
            }
        int ans = 0;
        for(int i=0; i<=N; i++)
        {
            if(f[N][i] != -1)
            {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
