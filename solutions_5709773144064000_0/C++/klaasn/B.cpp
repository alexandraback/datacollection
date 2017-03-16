#include "cmath"
#include "iostream"
#include "iomanip"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long ll;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b)                                                    \
	for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define ITER(c, it) \
	for (auto it = (c).begin(); it != (c).end(); it++)
int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    double time, prod, min, X, C, F;
    time = 0;
    prod = 2;
    min = 10E10;
    cin >> C >> F >> X;
    while (time < min) {
      double b1 = X/prod + time;
      if (b1 < min) { min = b1; }
      time = time +C/prod;
      prod += F;
    }

    cout << "Case #" << Ti << ": " << fixed << setprecision(7) << min << endl;
  }
  return 0;
}
