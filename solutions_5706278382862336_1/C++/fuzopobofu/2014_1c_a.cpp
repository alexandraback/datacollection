#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

long gcd(long n, long m) {
  long s = min(n, m);
  long l = max(n, m);

  while (s > 0) {
    long tmp = l;
    l = s;
    s = tmp % s;
  }

  return l;
}

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long P, Q; char c;
    string s;

    cin >> s;
    std::istringstream is( s );
    is >> P >> c >> Q;
    
    long ret = LONG_MAX;
    bool possible = true;
    long p, q;
    p = P;
    q = Q;

    // cerr << "p=" << p << endl;
    // cerr << "q=" << q << endl;
    while (p > 0 && q > 0) {
      long g = gcd(p, q);
      p = p/g;
      q = q/g;
      
      // cerr << "g=" << g << endl;
      // cerr << "p=" << p << endl;
      // cerr << "q=" << q << endl;

      long l = 1;
      long m;
      for (m = 2; m < q; m*=2) {
	l++;
      }
      // cerr << "m=" << m << endl;
      // cerr << "l=" << l << endl;

      ret = min(ret, l);
      if (m != q) {
	possible = false;
	break;
      }
      p -= 1;
    }
    if (possible) {
      std::cout << "Case #" << (t+1) << ": " << ret << std::endl;
    } else {
      std::cout << "Case #" << (t+1) << ": " << "impossible" << std::endl;
    }
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
