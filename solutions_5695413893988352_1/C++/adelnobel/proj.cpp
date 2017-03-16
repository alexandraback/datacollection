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

string assignAll(const string& s, int startIdx, char c) {
  string ret = s;
  for(int i = startIdx; i < s.size(); i++) {
    if (s[i] == '?') ret[i] = c;
  }
  return ret;
}

ps setCurAndRemaining(const ps& cur, int idx, char cA1, char cA2, char cB1, char cB2) {
  ps ret = cur;
  ret.first[idx] = cA1;
  ret.second[idx] = cB1;
  ret.first = assignAll(ret.first, idx + 1, cA2);
  ret.second = assignAll(ret.second, idx + 1, cB2);
  return ret;
}

ps solve(int idx, ps cur) {
  if (idx == cur.first.size()) {
    return cur;
  }

  ps ret;
  if (cur.first[idx] == '?' && cur.second[idx] == '?') {

    //Set equal
    ps newCur = cur;
    newCur.first[idx] = newCur.second[idx] = '0';
    ret = solve(idx + 1, newCur);

    //Set less by one
    ps lessByOneAns = setCurAndRemaining(cur, idx, '0', '9', '1', '0');
    ret = best(ret, lessByOneAns);

    //Set greater by 1
    ps greaterByOneAns = setCurAndRemaining(cur, idx, '1', '0', '0', '9');
    ret = best(ret, greaterByOneAns);
  } else if (cur.first[idx] == '?') {
    ps newCur = cur;
    newCur.first[idx] = newCur.second[idx];
    ret = solve(idx + 1, newCur);

    if (newCur.second[idx] != '0') {
      //Set less by one
      ps lessByOneAns = setCurAndRemaining(cur, idx, newCur.second[idx] - 1, '9', newCur.second[idx], '0');
      ret = best(ret, lessByOneAns);
    }

    if (newCur.second[idx] != '9') {
      //Set greater by 1
      ps greaterByOneAns = setCurAndRemaining(cur, idx, newCur.second[idx] + 1, '0', newCur.second[idx], '9');
      ret = best(ret, greaterByOneAns);
    }
  } else if (cur.second[idx] == '?') {
    ps newCur = cur;
    newCur.second[idx] = newCur.first[idx];
    ret = solve(idx + 1, newCur);

    if (newCur.first[idx] != '0') {
      //Set less by one
      ps lessByOneAns = setCurAndRemaining(cur, idx, newCur.first[idx], '0', newCur.first[idx] - 1, '9');
      ret = best(ret, lessByOneAns);
    }

    if (newCur.first[idx] != '9') {
      //Set greater by 1
      ps greaterByOneAns = setCurAndRemaining(cur, idx, newCur.first[idx], '9', newCur.first[idx] + 1, '0');
      ret = best(ret, greaterByOneAns);
    }
  } else {
    if (cur.first[idx] == cur.second[idx]) {
      ret = solve(idx + 1, cur);
    } else if (cur.first[idx] < cur.second[idx]) {
      ret = setCurAndRemaining(cur, idx, cur.first[idx], '9', cur.second[idx], '0');
    } else {
      ret = setCurAndRemaining(cur, idx, cur.first[idx], '0', cur.second[idx], '9');
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
