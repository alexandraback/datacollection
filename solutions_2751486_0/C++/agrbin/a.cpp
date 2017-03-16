#include <cstdio>
#include <cstring>
#include <cstdlib>

const int maxn = 1000010;
typedef long long llint;

const char* vow = "aeiou";
char word[maxn];
int N, K;

bool is_vow(char x) {
  for (const char *it = vow; *it; ++it)
    if (*it == x)
      return 1;
  return 0;
}

int kraj[maxn];

void init() {
  int last_cos = -1;
  memset(kraj, -1, sizeof kraj);
  for (int i = 0; i < N; ++i) {
    if (is_vow(word[i]))
      last_cos = i;
    if (i - last_cos >= K) {
      kraj[i - K + 1] = i;
    }
  }
}

llint solve() {
  llint sol = 0;
  int nesto = 0;
  while (kraj[nesto] == -1 && nesto < N)
    ++nesto;
  if (nesto == N) return sol;
  for (int it = 0; it < N; ++it) {
    while (kraj[nesto] == -1 && nesto < N)
      ++nesto;
    if (nesto == N) return sol;

    sol += (N - kraj[nesto]);
    while (nesto <= it) ++nesto;
  }
  return sol;
}

int main() {
  int casen;
  scanf("%d", &casen);
  for (int j = 0; j < casen; ++j) {
    scanf("%s%d", word, &K);
    N = strlen(word);
    init();
    printf("Case #%d: %lld\n", j + 1, solve());
  }
  return 0;
}
