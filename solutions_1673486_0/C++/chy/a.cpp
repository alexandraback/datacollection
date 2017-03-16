#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
double dp[11111][2];
double s[11111][2];
double p[11111];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,i,j,k,cas,a,b;
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&a,&b);
        for(i=1;i<=a;i++){scanf("%lf",&p[i]);p[i]=1-p[i];}
        dp[0][0]=1;
        for(i=1;i<=a;i++)
        {
            dp[i][0]=dp[i-1][0]*(1-p[i]);
            dp[i][1]=(1-dp[i][0]);
        }
        double ans=INF*1.0;
        double now=0;
        now+=dp[a][0]*(b-a+1);
        now+=dp[a][1]*(b-a+1+b+1);
        ans=min(ans,now);
        now=0;
        now+=(1+b+1);
        ans=min(ans,now);
        for(i=1;i<=a;i++)
        {
            now=0;
            now+=dp[a-i][0]*(i+1+b-(a-i));
            now+=dp[a-i][1]*(i+1+b-(a-i)+b+1);
            ans=min(ans,now);
        }
        printf("Case #%d: %.6lf\n",cas,ans);
    }
    return 0;
}
