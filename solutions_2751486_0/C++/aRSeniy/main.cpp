#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

bool isVovel (char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void precalc () {

}

int triv (const string& s, int n) {
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i + n - 1; j < s.size(); ++j) {
      int cur = 0;
      int k = 0;
      for (; k < n; ++k) {
        cur += !isVovel(s[i + k]);
      }
      if (cur == n) {
        ++ans;
        continue;
      }
      for (; i + k <= j; ++k) {
        cur -= !isVovel(s[i + k - n]);
        cur += !isVovel(s[i + k]);
        if (cur == n) {
          ++ans;
          break;
        }
      }
    }
  }
  return ans;
}

void solve () {
  string s;
  int n;
  cin >> s >> n;

  long long ans = 0;

  int cur = 0;
  int m = 0;
  int i = 0;
  for (; i < n; ++i) {
    cur += !isVovel(s[i]);
  }
  if (cur == n) {
    ans += (long long)s.size() - n + 1LL;
    m = 1;
  }
  for (; i < s.size(); ++i) {
    cur -= !isVovel(s[i - n]);
    cur += !isVovel(s[i]);
    if (cur == n) {
      ans += (long long)(i - n - m + 2LL) * ((long long)s.size() - i);
      m = i - n + 2;
    }
  }

  cout << ans << endl;
  //cout << triv(s, n) << endl;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    
    solve();
	}
	return 0;
}
