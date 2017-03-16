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
    cout << "Case #" << iCase << ": ";
    cerr << "[" << iCase << "] " << flush;

    int i, n;
    cin >> n;
    vector< pair<string, string> > titles(n);
    for (i = 0; i < n; ++i)
      cin >> titles[i].first >> titles[i].second;

    int bitsMax = (1 << (n+1));
    int maxFaked = 0;
    for (int bits = 0; bits < bitsMax; ++bits) {
      set<string> haveFirst, haveSecond;
      int faked = 0;
      
      for (i = 0; i < n; ++i)
	if (bits & (1 << i)) {
	  haveFirst.insert(titles[i].first);
	  haveSecond.insert(titles[i].second);
	}

      for (int i = 0; i < n; ++i)
	if (!(bits & (1 << i)))
	  if (haveFirst.find(titles[i].first)==haveFirst.end()
	      || haveSecond.find(titles[i].second)==haveSecond.end())
	    break;
	  else
	    ++faked;

      if (i >= n && faked > maxFaked) maxFaked = faked;
    }
    
    cout << maxFaked;
        
    cout << "\n";
  }

  return 0;
}
