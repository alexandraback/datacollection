#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
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

bool precedes(const vector<int> &v1, const vector<int> &v2) {
  int n = v1.size();
  for (int i = 0; i < n; ++i)
    if (v1[i] >= v2[i])
      return false;
  return true;
}

int main(void) {
  int T; cin >> T;
  
  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ":";
    cerr << "[" << iCase << "] " << flush;

    int n; cin >> n;
    int nLines = 2*n-1;
    vector< vector<int> > data(nLines+1, vector<int>(n));
    vector<int> appearances(2501, 0);
    for (int i = 0; i < nLines; ++i)
      for (int j = 0; j < n; ++j) {
	cin >> data[i][j];
	++appearances[data[i][j]];
      }

    vector<int> missing;
    for (int i = 0; i <= 2500; ++i)
      if (appearances[i] & 1)
	missing.push_back(i);

    for (int i = 0; i < n; ++i)
      cout << " " <<  missing[i];

    cout << "\n";
  }

  return 0;
}
