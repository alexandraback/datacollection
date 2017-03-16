#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#define maxn 10005

using namespace std;

int test,ttest;

int n,a[maxn],ans,b[maxn];

void init()
 {
  scanf("%d",&n);
  int i;
  for (i=1;i<=n;i++)scanf("%d",&a[i]);
 }

void work()
 {
    sort(a+1,a+n+1);
    int times=0,temp,i,l,r,t;bool flag;
    ans=a[n];
    int en;
    for (en=a[n]-1;en>=1;en--)
    {
     times=0;
     for (i=1;i<=n;i++)
     {
      t=a[i]/en;if (a[i]%en)t++;
      times+=t-1;
     }
     if (times+en<ans)ans=times+en;
    }
    printf("Case #%d: %d\n",ttest,ans);
 }

int main()
 {
     freopen("B.in","r",stdin);
     freopen("B.out","w",stdout);
     scanf("%d\n",&test);
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
