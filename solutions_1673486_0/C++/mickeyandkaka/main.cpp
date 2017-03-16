#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define clr(a,b)    (memset(a,b,sizeof(a)))
#define PB push_back
#define MP make_pair
#define SZ(v) (int)v.size()
#define ALL(c) c.begin(),c.end()
#define forn(i,s,t)   for(int i=s; i<=t; i++)
#define repv(i,v)   for(int i=0;i<(int)v.size();i++)
#define repi(it,c)  for(typeof(c.begin()) it=c.begin();it!=c.end();++it)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

int T;

double p[100010];
double plen[100010];
int a,b;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);


    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        clr(p,0),clr(plen,0);
        plen[0] = 1.0;

        scanf("%d%d",&a,&b);
        for(int i=1; i<=a; i++)
        {
            scanf("%lf",&p[i]);
            plen[i] = plen[i-1]*p[i];
        }

        double r1 = (b+2)*1.0;
        double r2 = (b-a+1) + (1-plen[a])*(b+1);
        double ans = min(r1,r2);

        for(int i=1; i<=a; i++)
        {
            int t1,t2;
            double p1,p2;

            t1 = i+b-(a-i)+1;
            t2 = t1+(b+1);
            p1 = plen[a-i];
            p2 = 1-plen[a-i];

            double tmp = p1*t1+p2*t2;
            ans = min(tmp,ans);
        }
        printf("Case #%d: %.6lf\n",cas,ans);
    }

    return 0;
}
