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

int test,ttest,n;

int s[maxn],l,x,f[maxn];

void init()
 {
  int i;
  scanf("%d%d\n",&l,&x);
  char c;
  for (i=1;i<=l;i++)
  {
      c=getchar();
      if (c=='i')s[i]=1;
       else if (c=='j')s[i]=2;
        else s[i]=3;
  }
 }

int calc(int x,int y)
{
    int sign=1;
    if (x<0){x=-x;sign*=-1;}if (y<0){y=-y;sign*=-1;}
    if (x==4)return sign*y;
    if (y==4)return sign*x;
    if (x==y)return -sign*4;
    if (x==1)
    {
        if (y==2)return sign*3;
        if (y==3)return -sign*2;
    }
    if (x==2)
    {
        if (y==1)return -sign*3;
        if (y==3)return sign*1;
    }
    if (x==3)
    {
        if (y==1)return sign*2;
        if (y==2)return -sign*1;
    }
}

int pd(int l,int r)
{
    int i,now;
    if (l==r)return s[l];
    now=calc(s[l],s[l+1]);
    for (i=l+2;i<=r;i++)now=calc(now,s[i]);
    return now;
}

void work()
 {
    int i,j,a,b,c;
    for (i=1;i<=l;i++)
    {
        for (j=1;j<x;j++)s[i+j*l]=s[i];
    }
    a=s[1];
    n=l*x;
    for (i=1;i<=n;i++)f[i]=pd(i,n);
    for (i=2;i<n;i++)
    {
     if (a==1)
     {
        b=s[i];
        for (j=i;j<n;j++)
        {
         if (b==2 && f[j+1]==3)
          {
            printf("Case #%d: YES\n",ttest);
            return;
          }
         b=calc(b,s[j+1]);
     }
    }
     a=calc(a,s[i]);
    }
   printf("Case #%d: NO\n",ttest);
 }

int main()
 {
     freopen("C.in","r",stdin);
     freopen("C.out","w",stdout);
     scanf("%d\n",&test);
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
