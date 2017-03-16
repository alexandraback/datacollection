#include <iostream>
#include <cstdio>
#include <math.h>
#include <memory.h>
using namespace std;
const int MAXN = 2100;

int N,A;
double D,t[MAXN],x[MAXN];

int main(){
  //    freopen("test.in","r",stdin);
  //    freopen("test.out","w",stdout);
      int T;scanf("%d",&T);
      for (int ca=1;ca<=T;ca++){
            scanf("%lf%d%d",&D,&N,&A);
            for (int i=0;i<N;i++)
                  scanf("%lf%lf",&t[i],&x[i]);
            while (x[N-2]>=D) N--;
            int i = N-2;
            double tt = t[i+1]-t[i];
            tt = tt *(D-x[i])/(x[i+1]-x[i]);
            t[i+1] = t[i]+tt;
            x[i+1] = D;
            printf("Case #%d:\n",ca);
            for (int kk=0;kk<A;kk++){
                  double a; scanf("%lf",&a);
                  double curv = 0,curt = 0,curd = 0,diffd = 0;
                  for (int i=0;i<N-1;i++){
                        double otherv = (x[i+1]-x[i])/(t[i+1]-t[i]);
                        diffd += x[i+1]-x[i];
                        double tt = t[i+1]-t[i];
                        if (curd + curv*tt+0.5*a*tt*tt >= x[i+1]){
                              curv = otherv;
                              curt = t[i+1];
                              curd = x[i+1];
                              diffd = 0;
                        } else {
                              curd = curd + curv*tt+0.5*a*tt*tt;
                              curv = curv+a*tt;
                              curt = curt + tt;
                              diffd = x[i+1]-curd;
                        }
                  }
                  if (curd != D){
                        curd = D - curd;
                        double delta = curv*curv+2*a*curd;
                        double tt = (sqrt(delta)-curv)/a;
                        curt += tt;
                  }
                  printf("%.6f\n",curt);
            }
      }
      return 0;
}
