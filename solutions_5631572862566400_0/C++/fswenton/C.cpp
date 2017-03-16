#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#define iterate(_i, _c) _i = _c.begin(); _i != _c.end(); ++_i
#define existsIn(_k, _c) (_c.find(_k) != _c.end())

#if 0
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;
#define Integer cpp_int
#define Rational cpp_rational
#define Float cpp_dec_float_50
#endif

int main(void) {
  int T; cin >> T;
  
  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ":";
    cerr << "[" << iCase << "] " << flush;

    int n; cin >> n;
    vector<int> bffs(n);
    for (int i = 0; i < n; ++i) { cin >> bffs[i]; --bffs[i]; }

    vector<int> cycle(n);
    for (int i = 0; i < n; ++i) cycle[i] = i;

    int bestCycle = 0;
    do {
      for (int len = bestCycle+1; len <= n; ++len) {
	int i;
	for (i = 0; i < len; ++i)
	  if (cycle[(i+1)%len]!=bffs[cycle[i]] && cycle[(i+len-1)%len]!=bffs[cycle[i]])
	    break;
	if (i >= len && len >= bestCycle)
	  bestCycle = len;
      }
    } while (next_permutation(cycle.begin(), cycle.end()));

    cout << " " << bestCycle;
    
    cout << "\n";
  }

  return 0;
}
