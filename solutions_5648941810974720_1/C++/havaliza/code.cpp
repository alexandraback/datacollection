#include <algorithm>
#include <iostream>
#include <valarray>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <ctime>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (int i = (a); i < int(n); ++i)
#define error(x) cout << #x << " = " << (x) << endl;
#define all(n) (n).begin(), (n).end()
#define Size(n) ((int)(n).size())
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; }
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; }
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); }

struct data {
  int count[10];
  string letters;

  data (string letters) {
    FOR(i, 0, 10) count[i] = 0;
    this->letters = letters;
  }

  bool contains(char letter) {
    return letters.find(letter) != string::npos;
  }

  void remove(char letter) {
    letters.erase(letters.begin() + letters.find(letter));
  }

  void extract(char letter, string digit, int value) {
    while (contains(letter)) {
      FOR(i, 0, Size(digit)) {
        remove(digit[i]);
      }
      count[value]++;
    }
  }

  string result() {
    string r = "";
    FOR(i, 0, 10) {
      r += string(count[i], '0' + i);
    }
    return r;
  }
};

string phone_number(string letters) {
  data d(letters);
  d.extract('Z', "ZERO", 0);
  d.extract('X', "SIX", 6);
  d.extract('G', "EIGHT", 8);
  d.extract('W', "TWO", 2);
  d.extract('H', "THREE", 3);
  d.extract('U', "FOUR", 4);
  d.extract('O', "ONE", 1);
  d.extract('F', "FIVE", 5);
  d.extract('V', "SEVEN", 7);
  d.extract('N', "NINE", 9);
  return d.result();
}

int main() {
  int t;
  cin >> t;
  FOR(test_number, 1, t + 1) {
    string letters;
    cin >> letters;
    cout << "Case #" << test_number << ": " << phone_number(letters) << endl;
  }
	return 0;
}
