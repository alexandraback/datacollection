#include <iostream>
#include <algorithm>
using namespace std;
#define FILE_IN "A-small-attempt4.in"
#define FILE_OU "A-small-attempt4.ou"
#define MAXN 1000

void Solve() {
  double J[MAXN];
  double T[MAXN];
  double X=0,y,min_y;
  int n;
  scanf("%d",&n);
  for ( int i=0  ;i<n ; i++ ) {
    scanf("%lf",&J[i]);
    T[i] = J[i];
    X+=J[i];
  }
  double rest = X;
  sort(T,T+n);
  double average = X / n;
	
	double av;
	if (T[n-1] <= 2*average) {
		av = 2*average;
	}
	else {
		for (int i=1; i<n; i++) {
			double d = T[i] - T[i-1];

			if (rest >= d*i) {
				for (int j=0; j<i; j++)
					T[j] = T[i];
				rest -= d*i;
				av = T[0];
			}
			else {
				av = T[0] + rest/i;
				break;
			}
		}
	}
  
  for ( int i=0 ; i<n; i++ ) {
   
    
    if ( i ) printf(" ");
    double t =  (av - J[i])/X;
    if ( t<0 ) t = 0;
    printf("%.6lf",t*100);
  }
  printf("\n");
}

int main ( ) {
  freopen(FILE_IN,"r",stdin);
  freopen(FILE_OU,"w",stdout);
  int cases;
  scanf("%d",&cases);
  for ( int cur = 1 ; cur<=cases ; cur++ ) {
    printf("Case #%d: ",cur);
    Solve();
  }

  return 0;
}


