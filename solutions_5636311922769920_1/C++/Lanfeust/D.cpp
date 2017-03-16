#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"

using namespace std;

typedef long long i64;

i64 pow(int p, int exp) {
  i64 res = 1;
  while (exp-- > 0)
    res *= p;
  return res;
}

vector<bool> next(vector<bool> cur, vector<bool> pat) {
  vector<bool> res;
  for (bool b: cur)
    for (bool bb: pat)
      res.push_back(b || bb);
  return res;
}

void show(int K, int C, int S) {
  for (int i = 0; i < (1 << K); i++) {
    auto v = vector<bool>(K);
    for (int j = 0; j < K; j++) {
      v[j] = (i & (1 << j)) != 0;
      printf(v[j] ? "G" : "L");
    }
    printf(" -> ");
    vector<bool> res = v;
    for (int c = 1; c < C; c++)
      res = next(res, v);
    
    for (bool b: res)
      printf(b ? "G" : "L");
    printf("\n");
  }
}

vector<i64> solve(int K, int C, int S) {
  vector<i64> res;
  if (K > S * C)
    return res;
  int pos = 0;
  i64 cur = 0, cur_pow = 1;
  while (pos < K) {
    if (pos > 0 && pos % C == 0) {
      res.push_back(cur);
      cur = 0;
      cur_pow = 1;
    }
    cur += pos * cur_pow;
    cur_pow *= K;
    pos++;
  }
  res.push_back(cur);
  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    fprintf(stderr, "Case #%d of %d...\n", Ti, T);
    int K, C, S;
    scanf("%d %d %d", &K, &C, &S);
    //show(K, C, S);
    auto solution = solve(K, C, S);
    printf("Case #%d:", Ti);
    if (solution.size() == 0)
      printf(" IMPOSSIBLE");
    else
      for (auto i: solution)
        printf(" %lld", i + 1);
    printf("\n");
  }
  return 0;
}
