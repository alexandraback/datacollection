#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int T;
double C,F,X;
double cps;
double ans;
int main(void){
  cin >> T;
  for(int t = 1; t <= T; t++){
    scanf("%lf %lf %lf",&C,&F,&X);
    cps = 2;
    ans = 0;
    while(1){
      if(X/cps > C/cps + X/(cps+F)){
	ans += C/cps;
	cps += F;
      }else{
	ans += X/cps;
	break;
      }
    }
    printf("Case #%d: %.7f\n",t,ans);
  }
}
