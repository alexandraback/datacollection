#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 25

using namespace std;

int test,ttest,r,c,w,ans,cnt,p;

bool flag[maxn];

void init()
 {
     scanf("%d%d%d",&r,&c,&w);
 }

void work()
 {
    printf("Case #%d: ",ttest);
    ans=r*(c/w)+w-1;
    int i;
    memset(flag,0,sizeof(flag));
    for (i=w;i<=c;i+=w)flag[i]=true;
    cnt=0;
    p=c/w*w;
    for (i=p-1;i>=1 && flag[i] == false;i--)++cnt;
    for (i=p+1;i<=c && flag[i]==false;i++)++cnt;
    if (cnt>=w)++ans;
    printf("%d\n",ans);
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
