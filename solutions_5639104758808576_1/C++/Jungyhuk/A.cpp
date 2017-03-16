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

int test,smax,ttest;

int s[maxn];

void init()
 {
  scanf("%d",&smax);
  char c=getchar();while (!isdigit(c))c=getchar();
  s[0]=c-48;
  int i;
  for (i=1;i<=smax;i++){scanf("%c",&c);s[i]=c-48;}
 }

void work()
 {
    int ans=0,cnt=0,i;
    for (i=0;i<=smax;i++)
    {
        if (!s[i])continue;
        if (cnt<i){ans+=i-cnt;cnt=i;}
        cnt+=s[i];
    }
    printf("Case #%d: %d\n",ttest,ans);
 }

int main()
 {
     freopen("A.in","r",stdin);
     freopen("A.out","w",stdout);
     scanf("%d\n",&test);
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
