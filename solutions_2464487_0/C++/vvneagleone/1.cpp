#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
 int T, r, t, x, i, j, ct;
 uint64_t a, b;
 scanf("%d",&T);
 for(x=1;x<=T;++x)
 {
  scanf("%d %d",&r,&t);
  ct=0;
  a=(uint64_t)r;
  while(t>=0)
  {
   b=a+1;
   b = b*b - a*a;
   t-= b;
   a+=2;
   ++ct;
  }
  printf("Case #%d: %d\n",x,ct-1);
 }
 return 0;    
}
