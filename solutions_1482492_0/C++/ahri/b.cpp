#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for( c.begin()::typeid i=(c.begin());i!=(c).end();++i)
#define IN(_lower,_variable,_higher) (((_lower)<=(_variable)) && ((_variable)<=(_higher)))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORU(v,p,k) for(int v=p;v<k;++v)
#define FORD(v,p,k) for(int v=(p)-1;v>=k;--v)
#define FORLLU(v,p,k) for(LL v=p;v<k;++v)
#define FORLLD(v,p,k) for(LL v=(p)-1;v>=k;--v)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

vector<double> t, x;
int n, a;
double d;

double solveQuad(double v0, double s, double a) {
  return (sqrt(v0*v0+2*a*s)-v0)/a;
}


double solveSubcase(){
  double g;
  scanf("%lfd ", &g);
  double speed = 0;
  double ret;
  double currX = 0;
//  cout << sz(t) << endl;
  for (int i=1;i<sz(t);i++) {    
//    double dist = x[i]-x[i-1];
    double timespan = t[i]-t[i-1];
    double novo = timespan *(speed + g*timespan/2.0);
    if (novo+currX <= x[i]) {
      currX=novo+currX;
      speed = speed + g*timespan;
    } else {
      double tempS = x[i]-currX;
      double tempT = solveQuad(speed, tempS, g);
      speed +=g*tempT;
      currX=x[i];
    }
  }
  ret=t[sz(t)-1];
//  cout << "stanje: " << currX << " " << speed << " " <<ret << endl;
  if (currX<d) {
    double tempS = d-currX;
    double tempT = solveQuad(speed, tempS, g);
    ret+=tempT;
  }
  return ret;
}

vector<double> solve(){
  vector<double> ret;
  scanf("%lf %d %d ", &d, &n, &a);
  t.resize(n); x.resize(n);
  for (int i=0;i<n;i++){
    scanf("%lf %lf ", &t[i], &x[i]);
  }
  for (int i=0;i<sz(t);i++) {
    if (x[i]>d) {
      if (i==0) { x[i]=d; break; }
      t[i]=(t[i]-t[i-1])*1.0/(x[i]-x[i-1])*(d-x[i-1]) +t[i-1];
      x[i]=d;
      t.resize(i+1);
      x.resize(i+1);
      break;
    }
  }
  for (int i=0;i<a;i++) {
    ret.push_back(solveSubcase());
  }
  return ret;

}


int main() {

  int _n=0;
  scanf("%d ", &_n);
  vector<vector<double> > sols;
  
  for (int i=0;i<_n;i++) {
    sols.push_back(solve());
  }
  for (int i=0;i<sz(sols);i++) {
    printf("Case #%d:\n", i+1);
    for (int j=0;j<sz(sols[i]);j++) printf("%0.8lf\n", sols[i][j]);
  }

  return 0;

}