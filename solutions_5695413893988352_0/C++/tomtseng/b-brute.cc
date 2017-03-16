#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool match (const string& c, const string& j, int cattempt, int jattempt) {
  int i = c.size()-1;
  while (i >= 0) {
    if (c[i] != '?' && cattempt%10 != c[i] - '0')
      return false;
    if (j[i] != '?' && jattempt%10 != j[i] - '0')
      return false;
    cattempt /= 10;
    jattempt /= 10;
    i--;
  }

  return true;
}

string fixlen (const string& s, int len) {
  string padding(len - s.size(), '0');
  return padding + s;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    string c, j;
    cin >> c >> j;
    int sz = c.size();

    int max = 1;
    for (int i = 0; i < sz; i++)
      max *= 10;

    int bestc;
    int bestj;
    int bestdiff = numeric_limits<int>::max()/3;

    for (int ca = 0; ca < max; ca++) {
      for (int ja = 0; ja < max; ja++) {
        if (match(c, j, ca, ja) && abs(ca - ja) < bestdiff) {
          bestdiff = abs(ca - ja);
          bestc = ca;
          bestj = ja;
        }
      }
    }

    cout << "Case #" << t << ": " << fixlen(to_string(bestc), sz) << " "
         << fixlen(to_string(bestj), sz) << "\n";
  }

  return 0;
}
