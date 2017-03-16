#include <bits/stdc++.h>

using namespace std;

const int MAX_NUM = 1 << 16;
bool flag[MAX_NUM + 1];
vector<int> primes;

void sieve() {
  fill(flag, flag + MAX_NUM + 1, true);
  flag[0] = flag[1] = false;
  for (int i = 2; i * i <= MAX_NUM; ++i) {
    if (!flag[i]) {
      continue;
    }
    for (int j = i + i; j <= MAX_NUM; j += i) {
      flag[j] = false;
    }
  }
  for (int i = 0; i <= MAX_NUM; ++i) {
    if (flag[i]) {
      primes.push_back(i);
    }
  }
}

bool judge(int bit, int num) {
  vector<int> factors;
  for (int base = 2; base <= 10; ++base) {
    uint64_t val = 0;
    for (int i = bit - 1; i >= 0; --i) {
      val = val * base + ((num >> i) & 1);
    }
    if (val <= MAX_NUM && flag[val]) {
      return false;
    }
    for (int i = 0; primes[i] * primes[i] <= val && i < primes.size(); ++i) {
      if (val % primes[i] == 0) {
        factors.push_back(primes[i]);
        break;
      }
    }
    if (factors.size() != base - 1) {
      return false;
    }
  }
  for (int i = bit - 1; i >= 0; --i) {
    printf("%d", (num >> i) & 1);
  }
  for (int i = 0; i < 9; ++i) {
    printf(" %d", factors[i]);
  }
  puts("");
  return true;
}

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);

  sieve();

  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("Case #%d:\n", test);
    for (int i = 0, j = 0; i < (1 << (n - 2)) && j < m; ++i) {
      int num = (1 << (n - 1)) + (i << 1) + 1;
      if (judge(n, num)) {
        ++j;
      }
    }
  }
  return 0;
}
