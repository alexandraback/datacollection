#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int T, cnt = 0;
  double C, F, X;

  int i, j, k;
  double res, tmp, speed, elapsed;

  scanf("%d",&T);
  while(T--){
    scanf("%lf%lf%lf",&C,&F,&X);

    res = X / 2;
    speed = 2;
    elapsed = 0;

    for(;;){
      elapsed += C / speed;
      speed += F;
      tmp = X / speed + elapsed;
      if(tmp > res) break;
      res = tmp;
    }
    
    printf("Case #%d: %.9f\n",++cnt,res);
  }

  return 0;
}
