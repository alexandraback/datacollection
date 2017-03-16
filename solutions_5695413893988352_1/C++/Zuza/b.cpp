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
bool revved;

string A, B;
vector<int> valA, valB;

typedef pair<llint, pair<llint, llint> > Tri;
const llint inf = 4611686018427387904 / 2;
Tri ans;

void solve(int x, bool done, llint p, llint q) {
  if (x == len) {
    assert(p <= q);
    auto tmp = Tri(q-p, make_pair(p, q));
    if (revved) {
      swap(tmp.second.first, tmp.second.second);
    }
    if (tmp < ans) ans = tmp;
    return ;
  }

  int t1[2]; int t1l = 0;
  int t2[2]; int t2l = 0;

  if (done && A[x] == '?') {
    t1[0] = 9; t1l = 1;
  }
  if (done && B[x] == '?') {
    t2[0] = 0; t2l = 1;
  }
  if (A[x] != '?') {
    t1[0] = A[x] - '0'; t1l = 1;
  }
  if (B[x] != '?') {
    t2[0] = B[x] - '0'; t2l = 1;
  }
  if (!done && A[x] == '?' && B[x] == '?') {
    t1[0] = 0; t1l = 1;
    t2[0] = 0; t2[1] = 1; t2l = 2;
  }
  if (!done && A[x] == '?' && B[x] != '?') {
    t1[0] = t2[0]; t1l = 1;
    if (t1[0]-1 >= 0) {
      t1[1] = t1[0] - 1;
      ++t1l;
    }
  }
  if (!done && A[x] != '?' && B[x] == '?') {
    t2[0] = t1[0]; t2l = 1;
    if (t1[0]+1 <= 9) {
      t2[1] = t1[0]+1;
      ++t2l;
    }
  }

  //  printf("x=%d done=%d t1={ "); REP(i, t1l) printf("%d ", t1[i]);
  //  printf("} t2={ "); REP(i, t2l) printf("%d ", t2[i]); printf("}\n");

  assert(t1l+t2l <= 3);
  REP(i, t1l) REP(j, t2l) {
    if (!done && t1[i] > t2[j]) continue;
    valA[x] = t1[i];
    valB[x] = t2[j];
    solve(x+1, (done || (t1[i] != t2[j])), p*10+t1[i], q*10+t2[j]);
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

    valA.clear(); valB.clear();
    valA.resize(len, -1); valB.resize(len, -1);

    ans = {inf, {inf, inf}};
   
    // A < B
    revved = false;
    solve(0, false, 0, 0);
    
    // A > B
    revved = true;
    swap(A, B);
    solve(0, false, 0, 0);

    output(ans.second.first);
    printf(" ");
    output(ans.second.second);
    printf("\n");
  }

  return 0;
}   
