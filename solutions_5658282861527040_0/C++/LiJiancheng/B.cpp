#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define N 102
int t,tt,a,b,k,s;

int main(){
  int i,j;
  freopen("1.txt","r",stdin);
  freopen("2.txt","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;++tt){
    scanf("%d%d%d",&a,&b,&k);
    printf("Case #%d: ",tt);
    s=0;
    for (i=0;i<a;++i)
      for (j=0;j<b;++j)
        if ((i&j)<k) ++s;
    printf("%d\n",s);
  }
  return 0;
}