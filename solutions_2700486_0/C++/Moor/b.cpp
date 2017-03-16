#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#define DBLE 1e-8
#define PI 3.1415926535898
#define INF 1000000000
#define MAXN 1510
#define MP(x,y) (make_pair((x),(y)))
#define FI first
#define SE second
using namespace std;
double dp[MAXN][MAXN];
bool vi[MAXN][MAXN];
int num[MAXN],rela[MAXN],top;
double cal(int lef,int x,int y,int limit)
{
    double ans=0;
    for(int i=0;i<=lef;++i)
        for(int j=0;j<=i&&j<=limit;++j)
        {
            if(j==limit)
                dp[i-j+1][j]+=dp[i-j][j];
            else    if(i-j==limit)
                dp[i-j][j+1]+=dp[i-j][j];
            else
            {
                if(i-j+1<limit)
                    dp[i-j+1][j]+=dp[i-j][j]*0.5;
                if(j+1<limit)
                    dp[i-j][j+1]+=dp[i-j][j]*0.5;
                if(i-j+1==limit&&j+1<limit)
                    dp[limit][limit]+=dp[i-j][j];
            }
        }
    if(x==0)
        for(int i=y;i<=lef&&i<limit;++i)
            ans+=dp[lef-i][i];
    else
        for(int i=x;i<=lef&&i<limit;++i)
            ans+=dp[i][lef-i];
    if(lef==2*limit-1)
        ans+=dp[limit][limit];
    return ans;
}
int main()
{
    freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);
    num[0]=1;
    top=1;
    for(int i=1,j=3;;++i,j+=2)
    {
        num[i]=num[i-1]+2*j-1;
        rela[i]=j;
        ++top;
        if(num[i]>=1000000)
            break;
    }
    int ncase,n,x,y;
    double ans;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d%d%d",&n,&x,&y);
        int lel=(y+abs(x))/2;
        printf("Case #%d: ",h);
        if(lel>1&&num[lel-1]>=n)
            ans=0;
        else    if(num[lel]<=n)
            ans=1;
        else
        {
            int lef=n-num[lel-1];
            for(int i=0;i<=lef&&i<=rela[lel];++i)
                for(int j=0;j<=lef&&j<=rela[lel];++j)
                    dp[i][j]=0.0;
            memset(vi,0,sizeof(vi));
            dp[0][0]=1;
            if(x>0)
                ans=cal(lef,0,y+1,rela[lel]);
            else    ans=cal(lef,y+1,0,rela[lel]);
        }
        printf("%.7f\n",ans);
    }
    return 0;
}

