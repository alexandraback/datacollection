#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int start[1000005], ed[1000005];

bool isVowels(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}

typedef long long LL;

LL count(LL s, LL e, LL n) {
  if (e - s + 1 < n)
    return 0;

  LL l = e - s + 1;
  return (l-n+1)*(l-n+2)/2;
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);

  int T;
  cin >> T;
  string s;
  int n;
  for (int cas = 1; cas <= T; cas++) {
    cin >> s >> n;
    int num = 0, st = 0, idx = 0;
    for (int i = 0; i < s.length(); i++) {
      if (!isVowels(s[i])) {
        num++;
        if (num == 1) st = i;
      } else {
        if (num >= n) {
          start[idx] = st;
          ed[idx++] = i - 1;
        }
        num = 0;
      }
    }
    if (num >= n) {
      start[idx] = st;
      ed[idx++] = s.length() - 1;
    }

    long long res = count(0, s.length()-1, n);
    long long beg = 0;
    for (int i = 0; i < idx; i++) {
      res -= count(beg, start[i] + n - 2, n);
      beg = ed[i] - n + 2;
    }
    res -= count(beg, s.length() - 1, n);

    cout << "Case #" << cas << ": " << res << '\n';

  }

  return 0;
}
