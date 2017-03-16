#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define maxn 111
#define INF 99999999
vector<int>vecb;
vector<int>veca;
vector<int>vec[110];
char str[110][110];
int dp[110][110];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,t,i,j,n,k,a,b,c;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ans=0;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if(c>(i&j))ans++;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
