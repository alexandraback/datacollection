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

int x,r,c,test,ttest;

void init()
 {
  scanf("%d%d%d",&x,&r,&c);
  if (r>c)swap(r,c);
 }

void work()
 {
    if (c<x){printf("Case #%d: RICHARD\n",ttest);return;}
    if (r*c%x){printf("Case #%d: RICHARD\n",ttest);return;}
    if (x==1){printf("Case #%d: GABRIEL\n",ttest);return;}
    if (x==2)
    {
        if ((r*c)&1)printf("Case #%d: RICHARD\n",ttest);
         else printf("Case #%d: GABRIEL\n",ttest);
        return;
    }
    if (x==3)
    {
      if (r==1)printf("Case #%d: RICHARD\n",ttest);
       else printf("Case #%d: GABRIEL\n",ttest);
        return;
    }
    if (x==4)
    {
     if (r<=2)printf("Case #%d: RICHARD\n",ttest);
       else printf("Case #%d: GABRIEL\n",ttest);
        return;
    }
 }

int main()
 {
     freopen("D.in","r",stdin);
     freopen("D.out","w",stdout);
     scanf("%d\n",&test);
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
