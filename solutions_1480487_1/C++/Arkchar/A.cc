#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <complex>
using namespace std;

// begin insert defines
#define Rep(i,n) for(int n_ = (n), i = 0; i< n_; ++i)

// end insert defines

const int N = 210;

int p[N], n;
int sp;

bool check(int id, double pc)
{
  double rpc = 1.0 - pc;
  double lim = p[id] + sp * pc;
  Rep(i, n) {
    if (i == id) continue;
    rpc -= max(0.0, (lim - p[i]) / sp);
  }
  return rpc > 0.0;
}

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  Rep(Ca, T) {
    cout << "Case #" << Ca + 1 << ":";
    cin >> n;
    Rep(i, n) cin >> p[i];
    sp = 0;
    Rep(i, n) sp += p[i];
    Rep(i, n) {
      double l = 0.0, r = 1.0;
      for (int iter = 0; iter < 1000; iter++) {
        double mid = (l + r) * .5;
        if (check(i, mid)) 
          l = mid;
        else {
          r = mid;
        }
      }
      printf(" %.7lf", l * 100);
    }
    cout << endl;
  }
  return 0;
}
