#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const ll kLim = 10000000;

int Z;
ll A, B;
vector< ll > v;

void read();
void prep();
void soups_on(int);

inline bool is_plnd(ll q) {
  ostringstream oss;
  string str, rstr;

  oss << q, rstr = str = oss.str();
  reverse(rstr.begin(), rstr.end());

  return str == rstr;
}

int main() {
  prep();
  cin >> Z;
  for (int zi = 1; zi <= Z; ++zi)
    read(), soups_on(zi);

  return 0;
}

void read() {
  cin >> A >> B;
}

void prep() {
  for (ll i = 1; i <= kLim; ++i)
    if (is_plnd(i) && is_plnd(i * i))
      v.push_back(i * i);
}

void soups_on(int zi) {
  int l, u;

  l = int(lower_bound(v.begin(), v.end(), A) - v.begin());
  u = int(upper_bound(v.begin(), v.end(), B) - v.begin());

  cout << "Case #" << zi << ": " << u - l << "\n";
}
