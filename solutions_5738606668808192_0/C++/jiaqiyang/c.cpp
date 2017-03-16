#include <cstdio>
#include <random>
#include <unordered_set>

typedef long long i64;
typedef __int128 i128;

const int N = 131072;

int n, j;

int prime[N], m;

void sieve() {
  static bool flag[N];
  m = 0;
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) prime[++m] = i;
    for (int j = 1; j <= m && i * prime[j] < N; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

inline int get(i128 x) {
  for (int i = 1; i <= m && (i64)prime[i] * prime[i] <= x; ++i) if (x % prime[i] == 0) return prime[i];
  return 0;
}

i128 calcBase(i64 temp, int x) {
  i128 t = 1, res = 0;
  for (int i = 0; i < n; ++i) {
    if (temp >> i & 1) res += t;
    t *= x;
  }
  return res;
}

int main() {
  scanf("%*d%d%d", &n, &j);
  puts("Case #1:");
  sieve();
  std::mt19937 gen;
  std::unordered_set<i64> pool;
  while (pool.size() < j) {
    i64 temp = gen();
    temp &= ((1LL << n) - 1);
    temp |= 1;
    temp |= 1LL << (n - 1);
    if (pool.find(temp) != pool.end()) continue;
    static int mem[N];
    for (int i = 2; i <= 10; ++i) if (!(mem[i] = get(calcBase(temp, i)))) goto fail;
    pool.insert(temp);
    for (int i = n - 1; i >= 0; --i) printf("%lld", temp >> i & 1);
    for (int i = 2; i <= 10; ++i) printf(" %d", mem[i]);
    puts("");
 fail:
    continue;
  }
  return 0;
}
