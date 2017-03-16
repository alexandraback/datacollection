#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double tm[2001], x[2001];

int main () {
  int T,t;
  cin>>T;
  for(t=0;t<T;t++) {
    int N,A,i;
    double d,a,tm1,tm2;
    cout<<"Case #"<<t+1<<":\n";
    cin>>d>>N>>A;
    for(i=0;i<N;i++) 
      cin>>tm[i]>>x[i];
    tm1 = tm[1]*((d-x[0])/(x[1]-x[0]));
    for(i=0;i<A;i++) {
      cin>>a;
      tm2 = sqrt(2*(d/a));
      if((x[0]>=d) || tm2>tm1) 
	printf("%lf\n", tm2);
      else 
	printf("%lf\n", tm1);
    }
  }
  return 0;
}
