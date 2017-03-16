#include <bits/stdc++.h>
#define vec vector
#define sz(c) int(c.size())
#define FOR(i, a, b) for (int i = a; i < (b); ++i)
#define DOWN(i, a, b) for(int i = (a) - 1; i >= (b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vec<int> vi;
typedef tuple<ll, string, string> state;

const state state_none = state(-1, "none", "none");
const state state_zero = state(0, "", "");

ostream& operator<<(ostream &out, const state &s) {
  return out << get<0>(s) << ": " << get<1>(s) << " " << get<2>(s) << endl;
}

int n;
string C, J;

vec<state> best_min;
vec<state> best_max;
vec<state> best_abs;

void update_min(int i, ll tmp, int c, int j, const state &s) {
  ll cur;
  string curC, curJ;
  tie(cur, curC, curJ) = best_min[i];

  ll pre;
  string preC, preJ;
  tie(pre, preC, preJ) = s;

  ll next = tmp + pre;
  string nextC = string() + char(c) + preC;
  string nextJ = string() + char(j) + preJ;
  if (best_min[i] == state_none 
      || cur > next
      || (cur == next && curC > nextC)
      || (cur == next && curC == nextC && curJ > nextJ)) 
  {
    best_min[i] = state(next, nextC, nextJ);
  }
}

void update_max(int i, ll tmp, int c, int j, const state &s) {
  ll cur;
  string curC, curJ;
  tie(cur, curC, curJ) = best_max[i];

  ll pre;
  string preC, preJ;
  tie(pre, preC, preJ) = s;

  ll next = tmp + pre;
  string nextC = string() + char(c) + preC;
  string nextJ = string() + char(j) + preJ;
  if (best_max[i] == state_none 
      || cur < next
      || (cur == next && curC > nextC)
      || (cur == next && curC == nextC && curJ > nextJ)) 
  {
    best_max[i] = state(next, nextC, nextJ);
  }
}

void update_abs(int i, ll tmp, int c, int j, const state &s) {
  ll cur;
  string curC, curJ;
  tie(cur, curC, curJ) = best_abs[i];

  ll pre;
  string preC, preJ;
  tie(pre, preC, preJ) = s;

  ll next = tmp + pre;
  string nextC = string() + char(c) + preC;
  string nextJ = string() + char(j) + preJ;

  if (best_abs[i] == state_none 
      || abs(cur) > abs(next)
      || (abs(cur) == abs(next) && curC > nextC)
      || (abs(cur) == abs(next) && curC == nextC && curJ > nextJ)) 
  {
    best_abs[i] = state(next, nextC, nextJ);
  }
}

void rec(int i) {
  if (i == n) {
    return;
  }
  rec(i + 1);

  ll p10 = 1;
  FOR(t, 0, n - i - 1) p10 *= 10;

  if (C[i] != '?' && J[i] != '?') {
    update_min(i, (C[i] - J[i]) * p10, C[i], J[i], best_min[i + 1]);
    update_min(i, (C[i] - J[i]) * p10, C[i], J[i], best_max[i + 1]);
    update_min(i, (C[i] - J[i]) * p10, C[i], J[i], best_abs[i + 1]);

    update_max(i, (C[i] - J[i]) * p10, C[i], J[i], best_min[i + 1]);
    update_max(i, (C[i] - J[i]) * p10, C[i], J[i], best_max[i + 1]);
    update_max(i, (C[i] - J[i]) * p10, C[i], J[i], best_abs[i + 1]);

    update_abs(i, (C[i] - J[i]) * p10, C[i], J[i], best_min[i + 1]);
    update_abs(i, (C[i] - J[i]) * p10, C[i], J[i], best_max[i + 1]);
    update_abs(i, (C[i] - J[i]) * p10, C[i], J[i], best_abs[i + 1]);
    return;
  }

  if (C[i] == '?' && J[i] == '?') {
    FOR(a, 0, 10) FOR(b, 0, 10) {
      update_min(i, (a - b) * p10, a + '0', b + '0', best_min[i + 1]);
      update_min(i, (a - b) * p10, a + '0', b + '0', best_max[i + 1]);
      update_min(i, (a - b) * p10, a + '0', b + '0', best_abs[i + 1]);

      update_max(i, (a - b) * p10, a + '0', b + '0', best_min[i + 1]);
      update_max(i, (a - b) * p10, a + '0', b + '0', best_max[i + 1]);
      update_max(i, (a - b) * p10, a + '0', b + '0', best_abs[i + 1]);

      update_abs(i, (a - b) * p10, a + '0', b + '0', best_min[i + 1]);
      update_abs(i, (a - b) * p10, a + '0', b + '0', best_max[i + 1]);
      update_abs(i, (a - b) * p10, a + '0', b + '0', best_abs[i + 1]);
    }
    return;
  }

  if (C[i] == '?') {
    FOR(a, 0, 10) {
      update_min(i, (a - J[i] + '0') * p10, a + '0', J[i], best_min[i + 1]);
      update_min(i, (a - J[i] + '0') * p10, a + '0', J[i], best_max[i + 1]);
      update_min(i, (a - J[i] + '0') * p10, a + '0', J[i], best_abs[i + 1]);

      update_max(i, (a - J[i] + '0') * p10, a + '0', J[i], best_min[i + 1]);
      update_max(i, (a - J[i] + '0') * p10, a + '0', J[i], best_max[i + 1]);
      update_max(i, (a - J[i] + '0') * p10, a + '0', J[i], best_abs[i + 1]);

      update_abs(i, (a - J[i] + '0') * p10, a + '0', J[i], best_min[i + 1]);
      update_abs(i, (a - J[i] + '0') * p10, a + '0', J[i], best_max[i + 1]);
      update_abs(i, (a - J[i] + '0') * p10, a + '0', J[i], best_abs[i + 1]);
    }
    return;
  }

  if (J[i] == '?') {
    FOR(b, 0, 10) {
      update_min(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_min[i + 1]);
      update_min(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_max[i + 1]);
      update_min(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_abs[i + 1]);

      update_max(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_min[i + 1]);
      update_max(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_max[i + 1]);
      update_max(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_abs[i + 1]);

      update_abs(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_min[i + 1]);
      update_abs(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_max[i + 1]);
      update_abs(i, (C[i] - '0' - b) * p10, C[i], b + '0', best_abs[i + 1]);
    }
    return;
  }

}

state solve_fast() {
  best_min = vec<state>(n + 1, state_none);
  best_max = vec<state>(n + 1, state_none);
  best_abs = vec<state>(n + 1, state_none);
  best_min[n] = best_max[n] = best_abs[n] = state_zero;
  rec(0);
  return best_abs[0];
}

void solve(int testcase) {
  cout << "Case #" << testcase << ": ";
  cin >> C >> J;
  n = sz(C);
  //cerr << best_min[1] << endl;
  ll res;
  string resC, resJ;
  tie(res, resC, resJ) = solve_fast();
  //assert(res >= 0);
  //cerr << best_abs[0] << endl;
  //cerr << best_abs[1] << endl;
  cout << resC << " " << resJ << endl;
}

state rec_slow(int, ll, ll);

void stress_run() {
  n = rand() % 6 + 1;
  C = J = "";
  int q = rand() % 6;
  FOR(i, 0, n) {
    if (q > 0 && rand() % 2 == 0) {
      q -= 1;
      C += '?';
    } else {
      C += char(rand() % 10 + '0');
    }
  }
  FOR(i, 0, n) {
    if (q > 0 && rand() % 2 == 0) {
      q -= 1;
      J += '?';
    } else {
      J += char(rand() % 10 + '0');
    }
  }
  cerr << C << " " << J << endl;
  ll ans;
  string ansC, ansJ;
  state ans_state = rec_slow(0, 0, 0);
  tie(ans, ansC, ansJ) = ans_state;
  ll res;
  string resC, resJ;
  state res_state = solve_fast();
  tie(res, resC, resJ) = res_state;
  if (ansC != resC || ansJ != resJ) {
    cerr << "FAIL";
    cerr << ans_state << endl;
    cerr << res_state << endl;
  }
  cerr << "OK " << ans << endl;
  cerr << endl;
}

void stress() {
  srand(int(time(0)));
  while (true) stress_run();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  #ifdef STRESS
  stress();
  #endif

  int testcases;
  cin >> testcases;
  FOR(testcase, 1, testcases + 1) {
    cerr << "Case " << testcase << "/" << testcases << endl;
    solve(testcase);
  }

  return 0;
}

state rec_slow(int i, ll c, ll j) {
  if (i == n) {
    return state(abs(c - j), "", "");
  }
  if (C[i] != '?' && J[i] != '?') {
    ll tmp;
    string tmpC;
    string tmpJ;
    tie(tmp, tmpC, tmpJ) = rec_slow(i + 1, c * 10 + (C[i] - '0'), j * 10 + (J[i] - '0'));
    string resC = string() + C[i] + tmpC;
    string resJ = string() + J[i] + tmpJ;
    return state(tmp, resC, resJ);
  }
  if (C[i] == '?' && J[i] == '?') {
    ll res = -1;
    string resC;
    string resJ;
    FOR(a, 0, 10) FOR(b, 0, 10) {
      ll tmp;
      string tmpC, tmpJ;
      tie(tmp, tmpC, tmpJ) = rec_slow(i + 1, c * 10 + a, j * 10 + b);
      if (res == -1 || res > tmp) {
        res = tmp;
        resC = string() + char(a + '0') + tmpC;
        resJ = string() + char(b + '0') + tmpJ;
      }
    }
    return state(res, resC, resJ);
  }
  if (C[i] == '?') {
    ll res = -1;
    string resC;
    string resJ;
    FOR(a, 0, 10) {
      ll tmp;
      string tmpC, tmpJ;
      tie(tmp, tmpC, tmpJ) = rec_slow(i + 1, c * 10 + a, j * 10 + J[i] - '0');
      if (res == -1 || res > tmp) {
        res = tmp;
        resC = string() + char(a + '0') + tmpC;
        resJ = string() + J[i] + tmpJ;
      }
    }
    return state(res, resC, resJ);
  }
  if (J[i] == '?') {
    ll res = -1;
    string resC;
    string resJ;
    FOR(b, 0, 10) {
      ll tmp;
      string tmpC, tmpJ;
      tie(tmp, tmpC, tmpJ) = rec_slow(i + 1, c * 10 + C[i] - '0', j * 10 + b);
      if (res == -1 || res > tmp) {
        res = tmp;
        resC = string() + C[i] + tmpC;
        resJ = string() + char(b + '0') + tmpJ;
      }
    }
    return state(res, resC, resJ);
  }
  return state(-1, "", "");
}

