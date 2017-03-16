#include<cstdio>
#include<vector>
#include<cmath>
#define forn(i, n ) for(int i = 0;i < (int)(n);i++)

using namespace std;

int main(){
  int _;
  scanf("%d",&_);
  forn(__,_){
    printf("Case #%d: ",__ + 1);
    int n;
    double sum = 0;
    scanf("%d",&n);
    vector<double> x(n);
    forn(i, n){
      scanf("%lf",&x[i]);
      sum += x[i];
    }
    forn(i,n){
      double l = 0,r = 1;
      while(fabs(l-r) > 1e-9){
        double m = (l + r)/2;
        double s = 0;
        forn(j, n){
          if( i == j)
            continue;
          s += max((x[i] - x[j])/sum + m, 0.);
        }
        //printf("m = %lf s = %lf\n",m,s);
        if(s + m > 1)
          r = m;
        else
          l = m;  
      }
      printf("%.6lf ",r*100);
    }
    puts("");
  }
}
