#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef vector<int> vi;

const string digits[] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

/*
z"ZERO"
w"TWO"
g"EIGHT"
t"THREE"
x"SIX"
s"SEVEN"
u"FOUR"
o"ONE"
f"FIVE"
n"NINE"
*/

void solve() {
  string s;
  cin >> s;
  map<char, int> m;
  for(char c: s) ++m[c];
  vi a(10, 0);
  auto ok = [&] (const string& s) {
    bool r = true;
    map<char, int> t;
    for(char c: s) ++t[c];
    for(auto e: t) r &= m[e.first] >= e.second;
    return r;
  };
  for(int i: {0,2,8,3,6,7,4,1,5,9}) {
    while (ok(digits[i])) {
      for(char c: digits[i])
        --m[c];
      a[i] += 1;
    }
  }
  int uu = 0;
  for(auto e: m) uu += e.second;
  cerr << uu << '\n';
  forn(i, 10) while(a[i]--)
    cout << i;
  cout << '\n';
}

int main() {
  int T;
  cin >> T;
  forn(t, T) {
    cout << "Case #" << t + 1 << ": ";
    solve();
  }
  return 0;
}
