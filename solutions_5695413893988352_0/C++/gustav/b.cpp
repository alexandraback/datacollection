#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1e19 / 2;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

string pad(string s, int n) {
  while ((int)s.size() < n)
    s = "0" + s;
  return s;
}

typedef pair< llint, pair< llint, llint > > tt;

int n;
char a[25], b[25];
llint p10[25];
int bio[25][3];

tt memo[25][3];

tt solve(int i, int sgn) {
  if (i == n) return {0, {0, 0}};

  if (bio[i][sgn + 1]) 
    return memo[i][sgn + 1];

  bio[i][sgn + 1] = true;

  int lo_a = 0, hi_a = 9;
  if (a[i] != '?') {
    lo_a = a[i] - '0';
    hi_a = a[i] - '0';
  }

  int lo_b = 0, hi_b = 9;
  if (b[i] != '?') {
    lo_b = b[i] - '0';
    hi_b = b[i] - '0';
  }

  tt sol = {inf, {0, 0}};
  llint cp10 = p10[n - i - 1];

  FOR(da, lo_a, hi_a + 1) {
    FOR(db, lo_b, hi_b + 1) {
      if (da == db) {
	auto csol = solve(i + 1, sgn);
	csol.second.first += da * cp10;
	csol.second.second += db * cp10;
	sol = min(sol, csol);
	continue;
      }

      if (sgn == 0) {
	if (da < db) {
	  auto csol = solve(i + 1, -1);
	  csol.first += (db - da) * cp10;
	  csol.second.first += da * cp10;
	  csol.second.second += db * cp10;
	  sol = min(sol, csol);
	} else {
	  auto csol = solve(i + 1, +1);
	  csol.first += (da - db) * cp10;
	  csol.second.first += da * cp10;
	  csol.second.second += db * cp10;
	  sol = min(sol, csol);
	}
	continue;
      }

      auto csol = solve(i + 1, sgn);
      csol.first += (da - db) * sgn * cp10;
      csol.second.first += da * cp10;
      csol.second.second += db * cp10;
      sol = min(sol, csol);
    }
  }

  memo[i][sgn + 1] = sol;

  return sol;
}

void solve() {
  scanf("%s%s", a, b);
  n = strlen(a);

  p10[0] = 1;
  FOR(i, 1, n + 1) p10[i] = 10 * p10[i - 1];
  memset(bio, 0, sizeof bio);

  auto ret = solve(0, 0);

  printf("%s ", pad(to_string(ret.second.first), n).c_str());
  printf("%s\n", pad(to_string(ret.second.second), n).c_str());
}

int main(void) 
{
  int T;
  scanf("%d", &T);
  FOR(i, 1, T + 1) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}
