#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> vowels(26);

ll nvalue(const string & s, ll N) {
  ll cnt = 0;
  ll startpoints = 0;

  ll cc = 0;
  for (unsigned int r = 0; r < s.length(); ++r) {
    if (vowels[(int)(s[r] - 'a')]) {
      cc = 0;
    } else {
      cc++;
    }

    if (cc >= N) {
      startpoints = r + 1 - N + 1;
    }
    cnt += startpoints;
  }
  return cnt;
}

void solve(int tc) {
  ll ans = 0;
  ll N;
  string s;

  cin >> s >> N;

  ans = nvalue(s, N);

  cout << "Case #" << tc << ": " << ans << endl;
}

int main() {
  int N;
  vowels['a' - 'a'] = 1;
  vowels['e' - 'a'] = 1;
  vowels['i' - 'a'] = 1;
  vowels['o' - 'a'] = 1;
  vowels['u' - 'a'] = 1;

  cin >> N;
  for (int tc = 1; tc <= N; ++tc)
    solve(tc);
  return 0;
}
