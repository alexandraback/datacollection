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

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

string toString(int x, int n) {
  string s = "";
  for (int i = n; --i >= 0; ) {
    s = (char)('0'+x % 10) + s;
    x /= 10;
  }
  return s;
}

int main(void) {
  int T; cin >> T;
  
  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ":";
    cerr << "[" << iCase << "] " << flush;

    string s, t;
    cin >> s >> t;

    int i, n = s.length();

    int top = 1; for (i = 0; i < n; ++i) top *= 10;
    // cout << top << "\n";
    
    int k;
    pair<int, int> best;
    int bestDiff = 10*top;
    for (int i = 0; i < top; ++i) {
      string s0 = toString(i, n);
      for (k = 0; k < n; ++k) if (s0[k]!=s[k] && s[k]!='?') break;
      if (k < n) continue;
      
      for (int j = 0; j < top; ++j) {
	string t0 = toString(j, n);
	for (k = 0; k < n; ++k) if (t0[k]!=t[k] && t[k]!='?') break;
	if (k < n) continue;
	
	int diff = abs(i - j);
	// cerr << i << " " << j << " " << diff << "\n";
	if (diff < bestDiff || (diff==bestDiff && best.first > i)) {
	  bestDiff = diff;
	  best.first = i; best.second = j;
	}
      }
    }
    cout << " " << toString(best.first, n) << " " << toString(best.second, n);
    
#if 0
    cpp_int value = 1;

    vector< pair<cpp_int> > sLarger(n+1), tLarger(n+1), close(n+1);

    sLarger[n].first = 0; sLarger[n].second = 0;
    tLarger[n].first = 0; tLarger[n].second = 0;
    close[n].first = 0; close[n].second = 0;
    int i = n;
    while (--i >= 0) {
      


    }

    int sign = 0;
    for (int i = 0; i < n; ++i)
      if (sign) {
	if (s[i]=='?') s[i] = "09"[sign < 0 ? 1 : 0];
	if (t[i]=='?') t[i] = "09"[sign < 0 ? 0 : 1];
      } else {
	if (s[i]=='?' && t[i]=='?') {
	  s[i] = t[i] = '0';
	} else if (s[i]=='?' && t[i]!='?') {
	  s[i] = t[i];
	} else if (s[i]!='?' && t[i]=='?') {
	  t[i] = s[i];
	} else if (!sign) {
	  if (s[i] < t[i])
	    sign = -1;
	  else if (s[i] > t[i])
	    sign = 1;
	}
      }

    cout << " " << s << " " << t;
#endif
    
      
    
    cout << "\n";
  }

  return 0;
}
