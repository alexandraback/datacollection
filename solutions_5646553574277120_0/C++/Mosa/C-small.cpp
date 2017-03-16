#include <bits/stdc++.h>

using namespace std;

int c, d, v;
bool have[31];
char dp[31][31];

bool solve(int i, int val, const vector<int> &ds) {
  if(val == 0) return true;
  if(i == (int)ds.size()) return false;
  char &res = dp[i][val];
  if(res != -1) return res;
  res = solve(i + 1, val, ds);
  if(ds[i] <= val) res |= solve(i + 1, val - ds[i], ds);
  return res;
}

bool ok(const vector<int> &ds) {
  bool can = true;
  memset(dp, -1, sizeof dp);
  for(int val = 1; val <= v; ++val) {
    can &= solve(0, val, ds);
  }
  return can;
}

int add, best;
vector<int> myD; // Denominations :P
void solve(int i) {
  if(ok(myD)) {
    best = min(best, add);
    return;
  }
  if(i > 15) return;
  solve(i + 1);
  if(!have[i]) {
    ++add;
    myD.push_back(i);
    solve(i + 1);
    myD.pop_back();
    --add;
  }
}

int main() {
  freopen("C.in", "rt", stdin);
  freopen("C.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    myD.clear();
    memset(have, 0, sizeof have);
    scanf("%d %d %d", &c, &d, &v);
    for(int i = 0; i < d; ++i) {
      int foo; scanf("%d", &foo);
      have[foo] = true;
      myD.push_back(foo);
    }
    best = 100;
    add = 0;
    solve(1);
    printf("Case #%d: %d\n", test, best);
  }
  return 0;
}
