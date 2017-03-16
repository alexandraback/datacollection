// {{{
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<int(n);++i)
template<class T>inline void check_min(T&a,T b){if(b<a)a=b;}
template<class T>inline void check_max(T&a,T b){if(a<b)a=b;}
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;
// }}}

template<typename T>
string to_s(T x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

template<typename T>
T to_i(const string &s) {
  stringstream ss(s);
  T x;
  ss >> x;
  return x;
}

string str[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

string solve() {
  static char s[2048];
  scanf("%s", s);
  map<char, int> mp;
  map<int, int> num;
  for (int i = 0; s[i]; ++i) {
    ++mp[s[i]];
  }
  vector<pair<int, char>> pv = {
    {0, 'Z'},
    {2, 'W'},
    {4, 'U'},
    {6, 'X'},
    {8, 'G'},
    {7, 'S'},
    {5, 'V'},
    {3, 'H'},
    {1, 'O'},
    {9, 'I'},
  };
  for (const auto &p: pv) {
    int x = num[p.X] = mp[p.Y];
    for (char c: str[p.X]) mp[c] -= x;
  }
  string ans;
  for (const auto &p: num) {
    ans += string(p.Y, char('0' + p.X));
  }
  return ans;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %s\n", index, solve().c_str());
  }
  return 0;
}
