#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

int a[10];
long long tmp[100];
map<int,long long> mm;
int d[105][10];
int n,m,up,k,two,three,ok;
long long maxn;
int next[100];

bool Check()
{
    mm.clear();
    int nn=n-up,i,j;
    for (i=0;i<(1<<nn);i++)
    {
        int mul=1;
        for (j=0;j<nn;j++)
        {
            if ((i & (1<<j))!=0) mul*=next[j];
        }
        mm[mul]=1;
    }
    for (i=0;i<k;i++)
    {
        if (mm[tmp[i]]!=1) break;
    }
    if (i==k) return true;
    return false;
}

void DFS(int t,long long mul)
{
   // printf("%d\n",m);
    int tmp,kk,i,j,x;
    if (t==n-up)
    {
        for (i=0;i<t;i++)
        {
       //     printf("%d",next[i]);
        }
       // printf("\n");
        if (Check()==true) ok=1;
        return;
    }
    if (ok==1) return;
    tmp=2;
    if (t!=0) tmp=next[t-1];
    for (i=tmp;i<=m;i++)
    {
        if (i==5 || i==7) continue;
        if (two==0)
        {
            if (i==2 || i==4 || i==6 || i==8) continue;
        }
        if (three==0)
        {
            if (i==3 || i==6) continue;
        }
        next[t]=i;
        long long kk=mul*i;
     //   printf("%d ~ %d ",kk,n-up);
        for (j=t+1;j<n-up;j++)
        {
            kk*=8;
        }
     //   printf("%lld %d\n",kk,maxn);
        if (kk<maxn) continue;
        DFS(t+1,mul*i);
        if (ok==1) return;
    }
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int i,j,cnt=1,r,T,x,maa;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d:\n",cnt++);
        while(r--)
        {
            two=three=0;
            memset(d,0,sizeof(d));
            memset(a,0,sizeof(a));
            memset(next,0,sizeof(next));
            for (i=0;i<k;i++)
            {
                scanf("%lld",&tmp[i]);
                if (tmp[i]%2==0) two=1;
                if (tmp[i]%3==0) three=1;
            }
            for (i=0;i<k;i++)
            {
                x=tmp[i];
                for (j=2;j<8;j++)
                {
                    while(x%j==0)
                    {
                        x/=j;
                        d[i][j]++;
                    }
                }
            }
            up=0;
            maa=0;
            for (i=0;i<k;i++)
            {
                maa=max(maa,d[i][7]);
            }
            for (i=0;i<maa;i++) a[up++]=7;
            maa=0;
            for (i=0;i<k;i++)
            {
                maa=max(maa,d[i][5]);
            }
            for (i=0;i<maa;i++) a[up++]=5;
            maxn=0;
            for (i=0;i<k;i++)
            {
                while(tmp[i]%5==0) tmp[i]/=5;
                while(tmp[i]%7==0) tmp[i]/=7;
                maxn=max(maxn,tmp[i]);
            }
            ok=0;
            DFS(0,1);
            for (i=up;i<n;i++)
            {
                a[i]=next[i-up];
            }
            for (i=0;i<n;i++)
            {
                if (a[i]!=0) printf("%d",a[i]);
                else printf("%d",2);
            }
            printf("\n");
        }
    }
    return 0;
}
