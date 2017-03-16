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

int gcd(int n, int m) {
  int s = min(n, m);
  int l = max(n, m);

  while (s > 0) {
    int tmp = l;
    l = s;
    s = tmp % s;
  }

  return l;
}

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int P, Q; char c;
    string s;

    cin >> s;
    std::istringstream is( s );
    is >> P >> c >> Q;
    
    int ret = INT_MAX;
    bool possible = true;
    int p, q;
    p = P;
    q = Q;

    // cerr << "p=" << p << endl;
    // cerr << "q=" << q << endl;
    while (p > 0 && q > 0) {
      int g = gcd(p, q);
      p = p/g;
      q = q/g;
      
      // cerr << "g=" << g << endl;
      // cerr << "p=" << p << endl;
      // cerr << "q=" << q << endl;

      int l = 1;
      int m;
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
