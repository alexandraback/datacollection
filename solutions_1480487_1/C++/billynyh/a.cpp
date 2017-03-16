#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-10; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-10; }

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
    	int n; scanf("%d", &n);
    	int a[n];
      double sum=0;
      double p[n];
    	for (int i=0;i<n;i++){
    		scanf("%d", &a[i]);
        sum += a[i];
        p[i]=1;
      }

      for (int i=0;i<n;i++){
        double l=0,r=1;
        while (fless(l, r)){
          double m = (l+r)/2;
          double score = a[i] + sum * m;
          double Y = m;

          for (int j=0;j<n;j++){
            if (i==j)continue;
            if (score < a[j]){
              continue;
            }else{
              Y += (score - a[j])/sum;
            }
          }
          //printf( "m %lf, s %lf, Y %lf\n",m, score, Y);
          if (Y>1){
            r = m;
            p[i] = m;
          }else{
            l = m;
          }
        }
        
      }

      printf("Case #%d:",ti);
      for (int i=0;i<n;i++){
        printf(" %.8lf", p[i]*100);
      }
      puts("");
    }
    return 0;
}
