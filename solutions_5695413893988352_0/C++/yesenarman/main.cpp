#include <bits/stdc++.h>
#define vec vector
#define sz(c) int(c.size())
#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define DOWN(i, a, b) for(int i = (a) - 1; i >= (b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vec<int> vi;

int n;
string C, J;

tuple<ll, string, string> rec(int i, ll c, ll j) {
  if (i == n) {
    return tuple<ll, string, string>(abs(c - j), "", "");
  }
  if (C[i] != '?' && J[i] != '?') {
    ll tmp;
    string tmpC;
    string tmpJ;
    tie(tmp, tmpC, tmpJ) = rec(i + 1, c * 10 + (C[i] - '0'), j * 10 + (J[i] - '0'));
    string resC = string() + C[i] + tmpC;
    string resJ = string() + J[i] + tmpJ;
    return tuple<ll, string, string>(tmp, resC, resJ);
  }
  if (C[i] == '?' && J[i] == '?') {
    ll res = -1;
    string resC;
    string resJ;
    FOR(a, 0, 10) FOR(b, 0, 10) {
      ll tmp;
      string tmpC, tmpJ;
      tie(tmp, tmpC, tmpJ) = rec(i + 1, c * 10 + a, j * 10 + b);
      if (res == -1 || res > tmp) {
        res = tmp;
        resC = string() + char(a + '0') + tmpC;
        resJ = string() + char(b + '0') + tmpJ;
      }
    }
    return tuple<ll, string, string>(res, resC, resJ);
  }
  if (C[i] == '?') {
    ll res = -1;
    string resC;
    string resJ;
    FOR(a, 0, 10) {
      ll tmp;
      string tmpC, tmpJ;
      tie(tmp, tmpC, tmpJ) = rec(i + 1, c * 10 + a, j * 10 + J[i] - '0');
      if (res == -1 || res > tmp) {
        res = tmp;
        resC = string() + char(a + '0') + tmpC;
        resJ = string() + J[i] + tmpJ;
      }
    }
    return tuple<ll, string, string>(res, resC, resJ);
  }
  if (J[i] == '?') {
    ll res = -1;
    string resC;
    string resJ;
    FOR(b, 0, 10) {
      ll tmp;
      string tmpC, tmpJ;
      tie(tmp, tmpC, tmpJ) = rec(i + 1, c * 10 + C[i] - '0', j * 10 + b);
      if (res == -1 || res > tmp) {
        res = tmp;
        resC = string() + C[i] + tmpC;
        resJ = string() + char(b + '0') + tmpJ;
      }
    }
    return tuple<ll, string, string>(res, resC, resJ);
  }
  return tuple<ll, string, string>(-1, "", "");
}

void solve(int testcase) {
  cout << "Case #" << testcase << ": ";
  cin >> C >> J;
  n = sz(C);
  ll res;
  string resC, resJ;
  tie(res, resC, resJ) = rec(0, 0, 0);
  assert(res >= 0);
  cout << resC << " " << resJ << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int testcases;
  cin >> testcases;
  FOR(testcase, 1, testcases + 1) {
    cerr << "Case " << testcase << "/" << testcases << endl;
    solve(testcase);
  }

  return 0;
}
