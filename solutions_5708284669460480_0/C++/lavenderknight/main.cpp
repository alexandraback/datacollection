#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char s[107],st[107];
int cnt[29],f[107];
int zy[107][28];
double dp[106][106],p[27];
int ma;
void getF(int L)
{
    f[0]=0;f[1]=0;
    for(int i=1;i<L;i++)
    {
        int j=f[i];
        while(j&&st[i]!=st[j]) j=f[j];
        f[i+1]=st[i]==st[j]?j+1:0;
    }
    zy[0][st[0]-'A']=1;
    for(int i=1;i<=L;i++)
    {

        for(int j=0;j<26;j++)
        {
            int k=f[i];
            if(st[i]==j+'A') {zy[i][j]=i+1;continue;}
            while(k&&st[k]!=j+'A') k=f[k];
            if(st[k]==j+'A') {zy[i][j]=k+1;continue;}
        }
    }
}
main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        int K,L,S;
        memset(cnt,0,sizeof(cnt));
        memset(zy,0,sizeof(zy));
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
        scanf("%d%d%d",&K,&L,&S);
        scanf("%s",s);
        ma=0;
        for(int i=0;i<K;i++) cnt[s[i]-'A']++;
        for(int i=0;i<26;i++) p[i]=cnt[i]*1.0/K;
        scanf("%s",st);
        getF(L);
        int uu=L-f[L];
        ma=(S-f[L])/uu;
        for(int i=0;i<L;i++) if(cnt[st[i]-'A']==0) ma=0;
        dp[0][0]=1;
        double ans=0;
        for(int i=0;i<S;i++)
        {
            for(int j=0;j<=L;j++)
            {
                for(int k=0;k<26;k++)
                dp[i+1][zy[j][k]]+=p[k]*dp[i][j];
            }
        }
       // for(int i=0;i<5;i++)
       // cout<<i<<"--"<<p[i]<<endl;
       // for(int i=0;i<=L;i++)
       // for(int j=0;j<5;j++)
       // printf("zy[%d][%d]=%d\n",i,j,zy[i][j]);
        //for(int i=0;i<=S;i++)
        //for(int j=0;j<=L;j++)
        //printf("dp[%d][%d]=%.6f\n",i,j,dp[i][j]);
        for(int i=1;i<=S;i++)
        ans+=dp[i][L];
        printf("Case #%d: %.9f\n",++cas,ma-ans);
    }
}
