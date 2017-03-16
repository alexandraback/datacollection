#include <cstdio>

using namespace std;

const double eps = 1e-9;
inline bool lt( double a, double b ){ return a+eps < b; }
inline bool gt( double a, double b ){ return lt(b,a); }
inline bool eq( double a, double b ){ return !lt(a,b) && !lt(b,a); }



const int mxn = 210;

int points[mxn];
int n;
int sum; //TODO

//true if contestant who can not be eliminated with p percent of audience votes
bool ok(double p, int who){
  double left = 1.0 - p;
  double myValue = points[who] + p * sum;

  for(int i = 0; i < n; i++){
    if(i == who) continue;

    left -= double(myValue-points[i]) / sum;
  }
  return !gt(left, 0.0);
}

double calc(int i){
  double lo = 0.0, hi = 1.0, mid;

  for(int it = 0; it < 100; it++){
    mid = (lo+hi)/2.0;

    if( ok(mid, i) ) hi = mid;
    else lo = mid;
  }

  return mid;
}

void solve(){
  sum = 0;

  scanf( "%d", &n );
  for(int i = 0; i < n; i++){
    scanf("%d", &points[i]);
    sum += points[i];
  }

  for(int i = 0; i < n; i++){
    printf("%lf", calc(i)*100.0);
    if(i != n-1) printf(" ");
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
