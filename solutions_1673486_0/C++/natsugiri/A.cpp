#include<cstdio>
#include<algorithm>
using namespace std;

int A, B;
double p;

int main(){
  int T;

  scanf("%d", &T);
  for(int tc=1; tc<=T; tc++){
    scanf("%d %d", &A, &B);

    double x=1, ans=min(B+2, B+A+1);

    for(int i=A-1; i>=0; i--){
      scanf("%lf", &p);
      int t=B-A+2*i+1;
      x*=p;
      ans=min(ans, t*x+(t+B+1)*(1.0-x));
    }

    printf("Case #%d: %.6f\n", tc, ans);
  }
  return 0;
}
      
