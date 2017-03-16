#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

const int maxk = 15;

int R, N, M, K;
int prod[maxk], num[maxk];
set<int> pset;

bool check(int s) {
  for (int i = 0; i < N; ++i) {
    num[i] = s % 10;
    s /= 10;
    if (!(2 <= num[i] && num[i] <= M))
      return false;
  }
  return true;
}

void get_all_prod() {
  pset.clear();
  for (int mask = (1 << N) - 1; mask >= 0; --mask) {
    int p = 1;
    for (int i = 0; i < N; ++i)
      if (0 != (mask & (1 << i)))
        p *= num[i];
    pset.insert(p);
  }
}

bool find_sol() {
  for (int i = 0; i < K; ++i)
    if (pset.find(prod[i]) == pset.end())
      return false;
  return true;
}

int guess() {
  for (int s = 2; s <= 555; ++s) {
    if (!check(s)) continue;
    get_all_prod();
    if (find_sol()) return s;
  }
  return 0;
}

void solve() {
  cin >> R >> N >> M >> K;
  while (R--) {
    for (int i = 0; i < K; ++i)
      scanf("%d", prod+i);
    printf("%d\n", guess());
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  printf("Case #1:\n");
  solve();
  return 0;
}
