#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int a,b,c,d,e,f;
unsigned long long ff[105][105];
unsigned long long best;
int n,m;
struct djk{
       unsigned long long bh,num;
       };
djk A[105],B[105];
int t;
int nn,mm;
int zz,zu;
unsigned long long dfs(int i,int j,unsigned long long n1,unsigned long long n2)
{
     int a,b;
     int judge;
     unsigned long long yao=0;
     if (n1==A[i].num && n2==B[j].num) judge=1; else judge=0;
     if (judge==1 && ff[i][j]!=-1) return ff[i][j];
     //printf("%d %d %lld %lld %lld\n",i,j,n1,n2,zong);
     if (i==nn+1) return 0;
     if (j==mm+1) return 0;
     if (n1==0 && n2==0)
     {
        yao=dfs(i+1,j+1,A[i+1].num,B[j+1].num);
        if (judge==1) ff[i][j]=yao;
        return yao;
     }
     if (n1==0) 
     {
        yao=dfs(i+1,j,A[i+1].num,n2);
        if (judge==1) ff[i][j]=yao;
        return yao;
     }
     if (n2==0) 
     {
        yao=dfs(i,j+1,n1,B[j+1].num);
        if (judge==1) ff[i][j]=yao;
        return yao;
     }
     if (A[i].bh!=B[j].bh)
     {
        yao=max(dfs(i+1,j,A[i+1].num,n2),dfs(i,j+1,n1,B[j+1].num));
        if (judge==1) ff[i][j]=yao;
        return yao;
     }
     unsigned long long now=min(n1,n2);
     yao=dfs(i,j,n1-now,n2-now)+now;
     if (judge==1) ff[i][j]=yao;
     return yao;
}

unsigned long long dfs1(int i,int j,unsigned long long n1,unsigned long long n2,unsigned long long zong)
{
     int a,b;
     int jud;
     unsigned long long yao=zong;
     if (n1==A[i].num && n2==B[j].num) jud=1;
     //if (n1==A[i].num && n2==B[j].num && ff[i][j]!=-1) return ff[i][j];
     //printf("%d %d %lld %lld %lld\n",i,j,n1,n2,zong);
     best=max(best,zong);
     if (i==nn+1) return 0;
     if (j==mm+1) return 0;
     if (n1==0) 
     {
        yao=dfs1(i+1,j,A[i+1].num,n2,zong); return yao;
     }
     if (n2==0) 
     {
        yao=dfs1(i,j+1,n1,B[j+1].num,zong); return yao;
     }
     if (A[i].bh!=B[j].bh)
     {
        yao=max(dfs1(i+1,j,A[i+1].num,n2,zong),dfs1(i,j+1,n1,B[j+1].num,zong));
        return yao;
     }
     unsigned long long now=min(n1,n2);
     yao=dfs1(i,j,n1-now,n2-now,zong+now);
     return yao;
}

int main()
{
    freopen("ti.in","r",stdin);
    freopen("ti.out","w",stdout);
    cin>>zu;
    for (int zz=1;zz<=zu;zz++)
    {
          best=0;
          nn=0; mm=0;
          cin>>n>>m;
          unsigned long long t1,t2;
          memset(ff,-1,sizeof(ff));
          nn=n; mm=m;
          for (a=1;a<=nn;a++)
          {
              cin>>A[a].num>>A[a].bh;
          }
          for (a=1;a<=mm;a++)
          {
              cin>>B[a].num>>B[a].bh;
          }
          /*
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
          }*/
          //dfs1(1,1,A[1].num,B[1].num,0);
          //printf("Case #%d: %lld\n",cas,best);
          dfs(1,1,A[1].num,B[1].num);
          printf("Case #%d: %lld\n",zz,ff[1][1]);
    }
}
