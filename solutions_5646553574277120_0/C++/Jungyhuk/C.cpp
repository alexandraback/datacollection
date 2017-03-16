#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#define maxn 1005

using namespace std;

int f[maxn],n,a[maxn],c,d,v,tpow[maxn],ans,test,ttest;

bool flag[maxn];

void getpow()
{
    int i,j=1;
    tpow[0]=0;
    while (j<=200)
    {
        tpow[++tpow[0]]=j;
        j*=2;
    }
}

void init()
 {
     scanf("%d%d%d",&c,&n,&v);
     int i;
     memset(flag,false,sizeof(flag));
     for (i=1;i<=n;i++){scanf("%d",&a[i]);flag[a[i]]=true;}
 }

void work()
 {
    printf("Case #%d: ",ttest);ans=0;
    int i,j,k;
    memset(f,0,sizeof(f));
    f[0]=1;
    for (i=1;i<=n;i++)
        for (j=v;j>=a[i];j--)if (f[j] || f[j-a[i]])f[j]=1;
    j=1;ans=0;
    for (i=1;i<=v;i++)if (!f[i])
    {
        ans++;
        for (k=v;k>=i;k--)if (f[k] || f[k-i])f[k]=1;
    }
    printf("%d\n",ans);
 }

int main()
 {
     freopen("C.in","r",stdin);
     freopen("C.out","w",stdout);
     scanf("%d\n",&test);
     getpow();
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
