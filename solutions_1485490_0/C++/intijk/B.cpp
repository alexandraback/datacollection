#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int a,b,c,d,e,f;
unsigned long long dp[105][105];
unsigned long long best;
int n,m;
struct djk{
       unsigned long long bh,num;
       };
djk A[105],B[105];
int t;
int nn,mm;
unsigned long long dfs(int i,int j,unsigned long long n1,unsigned long long n2,unsigned long long zong)
{
     int a,b;
     int judge;
     unsigned long long yao=0;
     if (n1==A[i].num && n2==B[j].num) judge=1;
     if (n1==A[i].num && n2==B[j].num && dp[i][j]!=-1) return dp[i][j];
     //printf("%d %d %lld %lld %lld\n",i,j,n1,n2,zong);
     best=max(best,zong);
     if (i==nn+1) return 0;
     if (j==mm+1) return 0;
     if (n1==0) 
     {
        yao=dfs(i+1,j,A[i+1].num,n2,zong); return yao;
        if (judge==1) dp[i][j]=yao;
     }
     if (n2==0) 
     {
        yao=dfs(i,j+1,n1,B[j+1].num,zong); return yao;
        if (judge==1) dp[i][j]=yao;
     }
     if (A[i].bh!=B[j].bh)
     {
        yao=dfs(i+1,j,A[i+1].num,n2,zong);
        yao=dfs(i,j+1,n1,B[j+1].num,zong);
        if (judge==1) dp[i][j]=yao;
        return yao;
     }
     unsigned long long now=min(n1,n2);
     yao=dfs(i,j,n1-now,n2-now,zong+now);
     if (judge==1) dp[i][j]=yao;
     return yao;
}

int main()
{
  //  freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout);
    cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
          best=0;
          nn=0; mm=0;
          cin>>n>>m;
          unsigned long long t1,t2;
          memset(dp,-1,sizeof(dp));
          for (a=1;a<=n;a++)
          {
              cin>>t1>>t2;
              if (A[nn].bh==t2) A[nn].num+=t1;
              else {nn++; A[nn].bh=t2; A[nn].num=t1;}
          }
          for (a=1;a<=m;a++)
          {
              cin>>t1>>t2;
              if (B[mm].bh==t2) B[mm].num+=t1;
              else {mm++; B[mm].bh=t2; B[mm].num=t1;}
          }
          dfs(1,1,A[1].num,B[1].num,0);
          printf("Case #%d: %lld\n",cas,best);
    }
}
