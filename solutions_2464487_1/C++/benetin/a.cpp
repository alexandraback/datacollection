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

long long r, t;

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin >> r >> t;
    long long lo, hi, S;
    lo = 0; hi = 1LL<<32;
    while (lo + 1 < hi) {
      S = (lo + hi) / 2;
      long double test = 0.9 * S * (2.0 * r + 2.0 * S - 1);
      long long test1 = S * (2 * r + 2 * S - 1);
      if (test > t) hi = S;
      else {
        if (test1 <= t) lo = S;
        else hi = S;
      }
    }
    cout << "Case #" << cs << ": " << lo << endl;
  }
  return 0;
}
