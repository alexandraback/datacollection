#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Val {
  int t, s;
};

Val mat[4][4];
Val operator * (Val A, Val B) {
  Val C = mat[A.t][B.t];
  C.s ^= A.s ^ B.s;
  return C;
}

bool operator == (Val A, Val B) {
  return A.t == B.t && A.s == B.s;
}

Val O = {0, 0};
Val I = {1, 0};
Val J = {2, 0};
Val K = {3, 0};

void init() {
  auto neg = [] (Val V) {
    V.s ^= 1;
    return V;
  };

  auto add = [] (Val A, Val B, Val C) {
    mat[A.t][B.t] = C;
  };

  add(O, O, O);
  add(O, I, I);
  add(O, J, J);
  add(O, K, K);

  add(I, O, I);
  add(I, I, neg(O));
  add(I, J, K);
  add(I, K, neg(J));
  
  add(J, O, J);
  add(J, I, neg(K));
  add(J, J, neg(O));
  add(J, K, I);

  add(K, O, K);
  add(K, I, J);
  add(K, J, neg(I));
  add(K, K, neg(O));
}

int N;
llint R;
char s[10100];
Val seq[10100];

int find_i() {
  Val v = O;
  REP(i, 10*N) {
    v = v * seq[i%N];
    if (v == I) return i+1;
  }
  return -1;
}

int find_k() {
  Val v = O;
  for (int i = 10*N-1; i >= 0; --i) {
    v = seq[i%N] * v;
    if (v == K) return 10*N - i;
  }
  return -1;
}

Val power(Val a, llint b) {
  Val ret = O;
  for (; b > 0; b /= 2) {
    if (b%2) ret = ret * a;
    a = a * a;
  }
  return ret;
}

int main() {
  init();

  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    scanf("%d%lld%s", &N, &R, s);
    REP(i, N) {
      if (s[i] == 'i') seq[i] = I;
      if (s[i] == 'j') seq[i] = J;
      if (s[i] == 'k') seq[i] = K;
    }

    int ci = find_i();
    int ck = find_k();

    Val v = O;
    REP(i, N) v = v * seq[i];
    v = power(v, R);

    printf("Case #%d: ", tt);
    if (v == I*J*K && ci != -1 && ck != -1 && ci + ck < N*R)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
