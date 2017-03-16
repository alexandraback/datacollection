#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define EPS 1e-7

int C=1,T;
int a,b;
double v[100050],acum[100050],prob,kt,er,di,resto,res;

int cmpf(double a, double b){
  if(fabs(a-b)<=EPS) return 0;
  return a<b?-1:1;
}

int main(){

  scanf("%d",&T);
  while(T--){
    printf("Case #%d: ",C++);
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++) scanf("%lf",v+i);
    res=10.0*b;

    // prob all right
    prob=1.0;
    for(int i=0;i<a;i++){
      prob*=v[i];
      acum[i]=prob;
    }

    // keep typing
    kt = prob*(b-a+1) + (1.0-prob)*(b-a+1+b+1);
    if(cmpf(kt,res)<0) res=kt;

    // enter right away
    er = 1.0+b+1.0;
    if(cmpf(er,res)<0) res=er;

    // delete i characters
    for(int k=1;k<=a;k++){
      // % of time that delete k characters works
      if(a-1-k<0) prob=1.0;
      else prob = acum[a-1-k];
      resto=(double)(b-(a-k));
      di = prob*(k+resto+1.0) + (1.0-prob)*(k+resto+1.0+b+1.0);
      if(cmpf(di,res)<0) res=di;
    }

    printf("%.6lf\n",res);
  }

  return 0;
}
