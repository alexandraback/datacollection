#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> vowels(26);

ll nvalue(const string & s, ll N) {

  cerr << s << ' ' << N << endl;

  ll cnt = 0;
  for (unsigned int l = 0; l < s.length(); ++l) {
    for (unsigned int r = l+1; r <= s.length(); ++r) {
      int cc = 0;

      cerr << s.substr(l,r);

      for (unsigned int i = l; i < r && cc < N; ++i) {
        if (vowels[(int)(s[i] - 'a')] == 1)
          cc = 0;
        else
          ++cc;
//        cerr << s[i] << ' ' << vowels[(int)(s[i] - 'a')] << ' ' << cc << endl;
      }

      if (cc >= N) {
        cnt++;
        cerr << " YES " << cc << endl;
      } else {
        cerr << " NO " << cc << endl;
      }
    }
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
