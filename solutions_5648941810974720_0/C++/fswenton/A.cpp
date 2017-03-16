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

void remove(string s, vector<int> &letters) {
  for (int i = s.length(); --i >= 0; )
    --letters[s[i]];
}

int main(void) {
  int T; cin >> T;
  
  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ": ";
    cerr << "[" << iCase << "] " << flush;

    string s;
    cin >> s;
    int n = s.length();

    vector<int> letters(128, 0);
    for (int i = 0; i < n; ++i) ++letters[s[i]];

    multiset<int> digits;
    while (letters['Z']) { digits.insert(0); remove("ZERO", letters); }
    while (letters['X']) { digits.insert(6); remove("SIX", letters); }
    while (letters['G']) { digits.insert(8); remove("EIGHT", letters); }
    while (letters['W']) { digits.insert(2); remove("TWO", letters); }
    while (letters['H']) { digits.insert(3); remove("THREE", letters); }
    while (letters['U']) { digits.insert(4); remove("FOUR", letters); }
    while (letters['F']) { digits.insert(5); remove("FIVE", letters); }
    while (letters['S']) { digits.insert(7); remove("SEVEN", letters); }
    while (letters['O']) { digits.insert(1); remove("ONE", letters); }
    while (letters['N']) { digits.insert(9); remove("NINE", letters); }
    
    for (auto iterate(it, digits))
      cout << *it;
    
    cout << "\n";
  }

  return 0;
}
