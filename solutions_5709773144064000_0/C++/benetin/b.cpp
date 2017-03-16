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

double C, F, X, ans, T, V;

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>C>>F>>X;
    ans = 1000000.0;
    T = 0; V = 2.0;
    while(T+(1e-9) < ans) {
      if (T + X/V < ans) ans = T + X/V;
      T += C/V;
      V += F;
    }
    // cout << "Case #" << cs << ": ";
    printf("Case #%d: %.9f\n", cs, ans);
  }
  return 0;
}
