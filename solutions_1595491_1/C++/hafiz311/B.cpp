#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int sup[50];
int norm[50];

void pre()
{
    for(int i=0;i<=10;i++)
        for(int j=i;j<=10;j++)
            for(int k=j;k<=10;k++)
            {
                if(k-i>2) continue;
                if(k-i==2) sup[i+j+k]=max(sup[i+j+k],k);
                else norm[i+j+k]=max(norm[i+j+k],k);
            }
}


int N,S,P;
int sc[1000];

int vis[105][105];
int dp[105][105];
int True;

int back(int pos,int sp)
{
    if(vis[pos][sp]==True) return dp[pos][sp];
    dp[pos][sp]=-10000000;vis[pos][sp]=True;
    if(pos==N)
    {
        if(sp==0) dp[pos][sp]=0;
        return dp[pos][sp];
    }
    if(sup[sc[pos]]>=P&&sp>0)
    {
        dp[pos][sp]=max(dp[pos][sp],1+back(pos+1,sp-1));
    }
    else if(sp>0)
    {
        dp[pos][sp]=max(dp[pos][sp],back(pos+1,sp-1));
    }

    if(norm[sc[pos]]>=P)
    {
        dp[pos][sp]=max(dp[pos][sp],1+back(pos+1,sp));
    }
    else dp[pos][sp]=max(dp[pos][sp],back(pos+1,sp));
    return dp[pos][sp];
}


int main()
{
    freopen("B1.in","rt",stdin);
    freopen("B.out","wt",stdout);
    pre();
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++){
        scanf("%d%d%d",&N,&S,&P);
        for(int i=0;i<N;i++) scanf("%d",&sc[i]);
        True++;
        printf("Case #%d: %d\n",cas,back(0,S));
    }
    return 0;
}
