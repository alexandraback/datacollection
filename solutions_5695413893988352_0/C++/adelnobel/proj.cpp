#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<string, string> ps;

int convertToNum(const string& S) {
  int ret = 0;
  for(int i = 0; i < S.size(); i++) {
    ret = ret * 10 + S[i] - '0';
  }
  return ret;
}

int getDifference(const ps& p) {
  return convertToNum(p.first) - convertToNum(p.second);
}

ps best(const ps& a, const ps& b) {
  int d1 = abs(getDifference(a));
  int d2 = abs(getDifference(b));
  if (d1 != d2) {
    if (d1 < d2) return a;
    return b;
  }

  int cS1 = convertToNum(a.first);
  int cS2 = convertToNum(b.first);
  if (cS1 != cS2) {
    if (cS1 < cS2) return a;
    return b;
  }

  if (convertToNum(a.second) < convertToNum(b.second)) return a;
  return b;
}

ps solve(int idx, ps cur) {
  if (idx == cur.first.size()) {
    return cur;
  }

  bool initialized = false;
  ps ret;

  for(int i = 0; i < 10; i++) {
    if (cur.first[idx] != '?' && cur.first[idx] - '0' != i) continue;
    for(int j = 0; j < 10; j++) {
      if (cur.second[idx] != '?' && cur.second[idx] - '0' != j) continue;
      ps newCur = cur;
      newCur.first[idx] = '0' + i;
      newCur.second[idx] = '0' + j;
      ps ans = solve(idx + 1, newCur);
      if (!initialized) {
        ret = ans;
        initialized = true;
      } else {
        ret = best(ret, ans);
      }
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T, n;
  cin >> T;
  string s1, s2;

  for (int tt = 1; tt <= T; tt++) {
    ps orig;
    cin >> orig.first >> orig.second;

    ps ans = solve(0, orig);

    cout << "Case #" << tt << ": ";
    cout << ans.first << " " << ans.second;

    cout << endl;
  }

  return 0;
}
