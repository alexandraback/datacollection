#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz size()
#define pb push_back
#define mp make_pair
#define ALL(X) (X).begin(),(X).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void output(int c, double n) { printf ("Case #%d: %.10lf\n", c, n); }

int main(void)
{
  double t, c, f, x;
  int buy;
  cin >> t;
  REP(cas,t) {
    cin >> c >> f >> x;
    if (c >= x) buy = 0;
    else buy = max((x * f - 2 * c) / (c * f), 0.0);
    double res = 0;
    REP(i,buy) res += 1.0 * c / (2 + f * i);
    res += 1.0 * x / (2 + f * buy);
    output(cas+1, res);
  }
  return 0;
}
