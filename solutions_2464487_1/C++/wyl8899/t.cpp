//#define FILE_IO

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;
#ifdef unix
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif 

typedef long double lf;

#define read(x) (scanf("%lf",&tR),x=tR)
double tR;

int main(){
#ifdef FILE_IO
  freopen("t.in","r",stdin);
  freopen("t.out","w",stdout);
#endif
  int T,Test=0;
  ll l,r,m;
  lf R,Lim,n,Tmp;
  scanf("%d",&T);
  while(T--){
    printf("Case #%d: ",++Test);
    read(R),read(Lim);
    for(l=1,r=(ll)sqrt(Lim);l<r;){
      n=m=(l+r+1)/2;
      Tmp=2*n*n+(2*R-1)*n;
      if(Tmp<=Lim)
        l=m;
      else
        r=m-1;
    }
    printf(LLD"\n",l);
  }
  return 0;
}
