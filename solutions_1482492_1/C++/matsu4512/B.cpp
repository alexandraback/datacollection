#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-10;
static const double PI = 3.141592653589;
typedef long long ll;

vector<double> solve(){
  double D;
  int N, A;
  cin >> D >> N >> A;
  long double t[2000], x[2000], a[250];
  for(int i = 0; i < N ; i++){
    cin >> t[i] >> x[i];
  }

  for(int i = 0; i < A; i++){
    cin >> a[i];
  }
  vector<double> result;
  for(int i = 0; i < A; i++){
    double res = 0.0;
    long double v1=0.0, v2=0.0, p1=0.0, p2=0.0, tt=0.0;
    for(int j = 0; j < N; j++){
      long double dt = t[j]-tt;
      if(dt == 0) v2 = 0;
      else v2 = (x[j]-p2)/dt;

      long double d= v1*dt + 0.5*a[i]*dt*dt;
      //cout << v1 << ", " << v2 << ", " << p1 << ", " << p2 << ", " << dt << ", " << (int)d << ", "<< res << endl;
      if(p1+d > D && x[j] > D){
	long double left = 0.0, right = 10000000.0, center;
	for(int k = 0; k < 500; k++){
	  center = (right+left)/2.0;
	  long double d =  v1*center + 0.5*a[i]*center*center;
	  if((D-p1) < d) right = center;
	  else left = center;
	}
	
	long double xx = p2+center*v2;
	if(xx > D) res += center;
	else{
	  res += (long double)(D-p2)/v2;
	}
	
	p1 = D;
	break;
      }
      else if(d+p1 < x[j]){
	p1 = d+p1;
	v1 = v1+a[i]*dt;
	res += dt;
      }
      else{
	p1 = x[j];
	v1 = v2;
	res += dt;
	//	cout << res << endl;
      }
      
      tt = t[j];
      p2 = x[j];
    }
    if(p1 < D){
      //cout << p1 << ", " << v1 << ", " << a[i]<< endl;
      long double left = 0.0, right = 10000000.0, center;
      for(int k = 0; k < 200; k++){
	center = (right+left)/2.0;
	long double d =  center*(v1 + 0.5*a[i]*center);
	if((D-p1) < d) right = center;
	else left = center;
      }
      res += center;
    }
    result.push_back(res);
  }
  return result;
}

int main(){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    vector<double> res = solve();
    cout << "Case #" << t << ":" << endl;
    for(int i = 0; i < (int)res.size(); i++){
      printf("%.10f\n", res[i]);
    }
  }
  return 0;
}
