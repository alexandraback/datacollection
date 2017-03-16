#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int T;
string s;
int cnt[26];
int dig[10];

void load() {
  cin >> s;
  for (int i = 0; i < (int)s.size(); ++i) {
    ++cnt[(int)s[i] - 'A'];
  }
}

void f(string t, int d) {
  int val = 1e9;
  for (auto c : t) {
    val = min(val, cnt[(int)c - 'A']);
  }
  dig[d] += val;
  for (auto c : t) {
    cnt[(int)c - 'A'] -= val;
  }
}

void solve(int tc) {
  f("ZERO", 0);
  f("TWO", 2);
  f("FOUR", 4);
  f("FIVE", 5);
  f("SIX", 6);
  f("SEVEN", 7);
  f("EIGHT", 8);
  f("THREE", 3);
  f("ONE", 1);
  f("NINE", 9);
  cout << "Case #" << tc << ": ";
  for (int i = 0; i < 10; ++i) {
    while (dig[i]--) {
      cout << i;
    }            
  }
  cout << '\n';
}

void clear() {
  memset(cnt, 0, sizeof cnt);
  memset(dig, 0, sizeof dig);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    clog << "Testcase " << tc << endl;
    load();
    solve(tc);
    clear();
  }
  return 0;
}