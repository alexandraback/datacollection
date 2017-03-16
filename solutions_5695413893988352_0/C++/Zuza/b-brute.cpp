#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int len;
string A, B;

typedef pair<llint, pair<llint, llint> > Tri;
const llint inf = 4611686018427387904 / 2;
Tri ans;

void solve(int x, llint p, llint q) {
  if (x == len) {
    auto tmp = Tri(abs(q-p), make_pair(p, q));
    if (tmp < ans) ans = tmp;
    return ;
  }
  
  REP(a, 10) REP(b, 10) {
    if (A[x] != '?' && a != A[x]-'0') continue;
    if (B[x] != '?' && b != B[x]-'0') continue;
    solve(x+1, p*10 + a, q*10 + b);
  }
}

void output(llint x) {
  string s;
  REP(i, len) {
    s += char(x%10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  printf("%s", s.c_str());
}

int main(void) {
  int ntc; scanf("%d", &ntc);
  REP(tc, ntc) {
    printf("Case #%d: ", tc+1); fflush(stdout);

    char AA[123], BB[123];
    scanf("%s %s", AA, BB); len = strlen(AA);
    A = AA, B = BB;

    ans = {inf, {inf, inf}};
   
    // A < B
    solve(0, 0, 0);

    output(ans.second.first);
    printf(" ");
    output(ans.second.second);
    printf("\n");
  }

  return 0;
}   
