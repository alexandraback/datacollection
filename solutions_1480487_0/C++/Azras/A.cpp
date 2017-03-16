#include <cstdio>
#include <algorithm>
#include <math.h>
#define EPS 0.0000001
using namespace std;
int points[200];
int main(){
  int tests,n;
  double sum;
  scanf("%d",&tests);
  for(int t=0;t<tests;t++){
    scanf("%d",&n);
    sum=0;
    for(int i=0;i<n;i++){
      scanf("%d",&points[i]);
      sum+=points[i];
    }
    printf("Case #%d: ",t+1);
    for(int i=0;i<n;i++){
      double left=0;
      double right=100;
      while(fabs(left-right)>EPS){
        double midd=(left+right)/2.0;
        bool can=true;
        //-------
        double me=points[i];
        double still=100.0-midd;
        me+=(sum*midd)/100.0;
        for(int j=0;j<n;j++){
          if(i==j) continue;
         //if((double)points[j]>me) continue;
          double x=(me-(double)points[j])*100.0;
          x/=sum;
          if(x>0.0) still-=x;
        }
        if(still>0.0) can=false;
        else can=true;
        if(can) right=midd;
        else left=midd;
      }
      printf("%.6lf ",left);
    }
    printf("\n");
  }
  return 0;
}




