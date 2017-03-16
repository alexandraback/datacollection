
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long integer;

double INF = 1e10;
double EPS = 5e-7;
struct Car {
  double p;
  double v;
};

inline double calcPos(const Car& c, double t) {
  return c.p + c.v * t;
}

int n;
vector<double> ts;
vector<Car> cars;
double memo[1<<6][1000];
double solve(int lane, int ti) {
  double& res = memo[lane][ti];
  if(res < 0){
    double t = ts[ti];
    if(t == INF){
      res = INF;
    }else{
      res = t;
      vector<bool> canSwap(n, true);
      bool hoge = true;
      REP(i, n){
	double pi = calcPos(cars[i], t);
	//     cerr << pi << endl;
	REP(j, i){
	  double pj = calcPos(cars[j], t);
	  //       if(pi < pj && pj < pi + 5 || pi < pj + 5 && pj + 5 < pi + 5){
	  if(!(pi + 5 <= pj || pj + 5 <= pi)){
	    if(((lane >> i) & 1) == ((lane >> j) & 1)){
	      res = t;
	      hoge = false;
	    }else{
	      canSwap[i] = false;
	      canSwap[j] = false;
	    }
	  }
	}
      }
      
      if(hoge){
	REP(pat, 1 << n){
	  bool ok = true;
	  REP(i, n){
	    if(canSwap[i] || (lane & (1 << i)) == (pat & (1 << i))){
	    }else{
	      ok = false;
	      break;
	    }
	  }
	  if(ok)
	    res = max(res, solve(pat, ti+1));
	}
      }
    }
  }
  return res;
}

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    cerr << endl;
    cin >> n;
    cars = vector<Car>(n);
    int lane = 0;
    REP(i, n){
      string s;
      cin >> s >> cars[i].v >> cars[i].p;
      if(s[0] == 'L')
	lane |= 1 << i;
    }
    
    ts = vector<double>(1, 0.0);
    ts.push_back(INF);
    REP(i, n){
      REP(j, n){
	if(i == j) continue;
	if(cars[i].v == cars[j].v) continue;
	double t = (cars[i].p + 5 - cars[j].p) / (cars[j].v - cars[i].v);
// 	cerr << ">>" << t << endl;
	if(t >= 0)
	  ts.push_back(t);
	if(t-EPS >= 0)
	  ts.push_back(t-EPS);
	if(t+EPS >= 0)
	  ts.push_back(t+EPS);
      }
    }
    sort(ts.begin(), ts.end());
    ts.erase(unique(ts.begin(), ts.end()), ts.end());
    REP(i, ts.size())
      fprintf(stderr, "> %.10f\n", ts[i]);
//       cerr << ">" << ts[i] << endl;
    
    REP(i, 1 << 6) REP(j, 1000)
      memo[i][j] = -1;

    double res = solve(lane, 0);
    
  OUTPUT:
    if(res >= INF){
      printf("Case #%d: Possible\n", iCase+1);
    }else{
      printf("Case #%d: %.10f\n", iCase+1, res);
    }
  }
  
  return 0;
}
