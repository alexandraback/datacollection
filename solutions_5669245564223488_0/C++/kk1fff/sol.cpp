#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;

void reduce(string &s) {
  string t = s;
  s = "";
  char c = '\0';
  for (auto i = t.begin(); i != t.end(); i++) {
    if (c != *i) {
      c = *i;
      s += *i;
    }
  }
}

bool valid(string cur) {
  int m[26];
  bzero(m, sizeof(int) * 26);
  reduce(cur);
  for (auto i = cur.begin(); i != cur.end(); ++i) {
    if (m[*i - 'a']) {
      return false;
    }
    m[*i - 'a'] = 1;
  }
  return true;
}

ll r(string *s, int slen, int *used, int left, const string &cur) {
  if (left == 0) {
    if (valid(cur)) {
      return 1;
    } else {
      return 0;
    }
  }

  ll ret = 0;
  // cout << cur << endl;
  for (int i = 0; i < slen; i++) {
    if (!used[i]) {
      used[i] = 1;
      ret = (ret + r(s, slen, used, left - 1, cur + s[i])) % 1000000007;
      used[i] = 0;
    }
  }
  return ret;
}

void run(istream& in, int t) {
  int N;
  in >> N;
  string s[100];
  int used[100];

  bzero(used, sizeof(int) * 100);
  for (int i = 0; i < N; i++) {
    in >> s[i];
    reduce(s[i]);
  }

  ll ret = 0;

  for (int i = 0; i < N; i++) {
    used[i] = 1;
    ret = (ret + r((string*)s, N, used, N - 1, s[i])) % 1000000007;
    used[i] = 0;
  }

  cout << "Case #" << t << ": " << ret << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    run(cin, i + 1);
  }
}
