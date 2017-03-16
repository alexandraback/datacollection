#include <iostream>
#include <vector>
using namespace std;

using vvc = vector<vector<char>>;

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    int x, y, m;
    bool tr = false;
    cin >> x >> y >> m;
    int empty = x*y - m;
    if (x < y) swap(x, y), tr = true;

    vvc ans;
    auto make = [](int r, int c) {
      return vvc(r, vector<char>(c, '*'));
    };

    if (empty == 1) {
      ans = make(y, x);
      ans[0][0] = 'c';
    } else if (y == 1) {
      ans = make(y, x);
      fill(ans[0].begin(), ans[0].begin() + empty, '.');
      ans[0][0] = 'c';
    } else {
      for (int i = 2; i <= x; ++i) {
	for (int j = 2; j <= y; ++j) {
	  if (empty >= 2*i + 2*j - 4 &&
	      empty <= i*j) {
	    ans = make(y, x);
	    int full = (i*j - empty);
	    int fullrows = (i > 2 ? full / (i - 2) : 0);
	    int rem = (i > 2 ? full % (i - 2) : 0);
	    for (int a = 0; a < j; ++a) {
	      if (a < j - fullrows - 1)
		fill(ans[a].begin(), ans[a].begin() + i, '.');
	      else if (a == j - fullrows - 1)
		fill(ans[a].begin(), ans[a].begin() + i - rem, '.');
	      else
		fill(ans[a].begin(), ans[a].begin() + 2, '.');
	    }
	    ans[0][0] = 'c';
	    goto outta;
	  }
	}
      }
    outta:					
      ;
    }

    cout << "Case #" << ncase << ":" << endl;
    if (ans.empty()) cout << "Impossible" << endl;
    else {
      if (tr) {
	for (int i = 0; i < y; ++i, cout << endl)
	  for (int j = 0; j < x; ++j)
	    cout << ans[i][j];
      } else {
	for (int i = 0; i < x; ++i, cout << endl)
	  for (int j = 0; j < y; ++j)
	    cout << ans[j][i];
      }
    }
  }
}
