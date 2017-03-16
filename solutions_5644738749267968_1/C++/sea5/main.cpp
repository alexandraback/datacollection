#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <iomanip>
inline int Max(int a,int b)
{
    return a>b?a:b;
}
inline int Min(int a,int b)
{
    return a<b?a:b;
}
const double pi=3.1415926;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> ii;
const long double inf=1000000007;
const long double eps=1e-6;
const int maxn=1005;
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
double g[1005],v[1005];
int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int cas,c=1;
    scanf("%d",&cas);
    while(cas--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&g[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&v[i]);
        }
        sort(g+1,g+n+1);
        sort(v+1,v+n+1);
        int ghead=1,vhead=1,vtail=n;
        int win=0;
        while(ghead<=n)
        {
            if(g[ghead]>v[vhead])
            {
                ghead++;
                vhead++;
                win++;
            }
            else
            {
                ghead++;
                vtail--;
            }
        }
        ghead=1;vhead=1;vtail=n;
        int lose=0;
        while(ghead<=n)
        {
            if(v[ghead]>g[vhead])
            {
                ghead++;
                vhead++;
                lose++;
            }
            else
            {
                ghead++;
                vtail--;
            }
        }
        printf("Case #%d: %d ",c++,win);
        printf("%d\n",n-lose);
    }
    return 0;
}
