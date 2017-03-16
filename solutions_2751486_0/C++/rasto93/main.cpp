#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#include <tuple>

#define INF 1023456789
#define SQR(x) ((x)*(x))
#define INIT(x,y) memset((x),(y),sizeof((x)))
#define SIZE(x) ((int)((x).size()))
#define REP(i, n) for (__typeof(n) i=0;i<(n);++i)
#define FOR(i, a, b) for (__typeof(a) i=(a);i<=(b);++i)
#define FORD(i, a, b) for (__typeof(a) i=(a);i>=(b);--i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define DEBUG
#ifdef DEBUG
#define DBG(x) cerr << #x << ": " << (x) << endl;
#else
#define DBG(x)
#endif

using namespace std;
 
typedef long long LL;
typedef pair<int,int> PI;
typedef tuple<int,int,int>trio;

char str[1000047];
const char vowel[5]={'a','e','i','o','u'};

inline bool IsConsonant(char c)
{
        REP(i,5) if (c==vowel[i]) return false;
        return true;
}

inline void solve(int t)
{
        LL N;
        scanf("%s%lld",str,&N);
        LL l=strlen(str),consecutive(0),last(l);
        LL res(0);
        REP(i,l)
        {
                if (IsConsonant(str[i])) consecutive++;
                else consecutive=0;
                if (consecutive>=N) last=i-N+1;
                if (last!=l) res+=last+1;
        }
        printf("Case #%d: %lld\n",t,res);
}

int main()
{
        int T;
        scanf("%d",&T);
        REP(i,T) solve(i+1);
        return 0;
}
