#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cassert>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  ll i,j,k,l,m,n;
  ll r, t, res, tmp;
  int size, count = 0;
  double gs, dr, dt;

  scanf("%d",&size);
  while(size--){
//    fprintf(stderr, "progress %d\n", size);
    printf("Case #%d: ", ++count);

    scanf("%lld%lld",&r,&t);

    dr = 2*(double)r-1; dt = 8*(double)t;
    gs = (sqrt(dr*dr+dt) - dr)/4;

    k = (ll)(gs - 4000);
    if(k < 0) k = 0;

    res = k;
    t -= 2*k*k + (2*r-1)*k;
    r += 2 * k;

    for(;;){
      tmp = 2*r + 1;
      if(t < tmp) break;
      t -= tmp;
      res++;
      r += 2;
    }

    printf("%lld\n",res);
  }

  return 0;
}
