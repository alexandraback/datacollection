#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int N, T;
double a[500];

int okay(int s, double p) {
  double o=a[s]+p*T/100.0;
  double R=T-p*T/100.0;
  REP(i, N) if(i!=s) {
    if(a[i]<o) {
      R-=(o-a[i]);
    }
  }
  return (R<=0);
}

double play(int p) {
  double lo, hi, mi;
  lo=0; hi=100;
  while(hi - lo > 1e-7) {
    mi = (lo+hi)/2;
    if(okay(p, mi)) hi=mi; else lo=mi;
  }
  return hi;
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cout << "Case #" << cs << ":";
    cin>>N; REP(i,N) cin>>a[i];
    T=0; REP(i,N) T+=a[i];
    REP(i,N) cout << " " << play(i);
    cout<<endl;
  }
  return 0;
}
