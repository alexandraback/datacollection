#include <cstdio>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct i128
{
  unsigned long long d0, d1;

  i128(unsigned long long a) : d0(a), d1(0) { }

  i128 &operator += (unsigned long long d) {
    d1 += (d + d0 < d0);
    d0 += d;
    return *this;
  }

  i128 &operator += (i128 other) {
    d1 += (other.d0 + d0 < d0);
    d0 += other.d0;
    d1 += other.d1;
    return *this;
  }
  i128 &operator *= (int x) {
    i128 v(0);
    for (int i = 0; i < x; i++) {
      v += *this;
    }
    d0 = v.d0;
    d1 = v.d1;
    return *this;
  }

  unsigned int mod(unsigned int m) {
    unsigned int ans = d1 % m;
    for (int i = 0; i < 64; i++)
    {
      ans += ans;
      ans %= m;
    }
    ans += d0 % m;
    ans %= m;
    return ans;
  }
};

int main()
{
  int n, J;
  scanf("%*d%d%d", &n, &J);
  printf("Case #1:\n");
  set<string> reported;
  while (J > 0)
  {
    vector<int> digits;
    string jam;
    for (int i = 0; i < n; i++) {
      if (i == 0 || i + 1 == n)
      {
        digits.push_back(1);
      }
      else
      {
        digits.push_back(rand() % 2);
      }
    }
    for (int i = 0; i < n; i++) {
      jam.push_back(digits[i] + '0');
    }
    if (!reported.insert(jam).second)
      continue;
    vector<int> divisors;
    for (int base = 2; base <= 10; base++)
    {
      i128 value = 0;
      for (int i = 0; i < n; i++) {
        value *= base;
        value += digits[i];
      }
      bool found = false;
      int maxtrial = min((1ll << n) - 1, 1000ll);
      for (int trial = 2; trial < maxtrial; trial++) {
        if (value.mod(trial) == 0) {
          divisors.push_back(trial);
          found = true;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    if (divisors.size() != 9) {
      continue;
    }
    J--;
    printf("%s", jam.c_str());
    for (auto d : divisors) {
      printf(" %d", d);
    }
    puts("");
  }
  return 0;
}