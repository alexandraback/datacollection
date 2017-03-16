#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long llint;

const llint maxn = 10e14;

vector<llint> fairs;

bool is_palin(llint x) {
  llint rev = 0, org = x;
  while (x) {
    rev *= 10; rev += (x % 10); x /= 10;
  }
  return org == rev;
}

void init() {
  for (llint j = 1; j * j <= maxn; ++j)
    if (is_palin(j) && is_palin(j*j))
      fairs.push_back(j*j);
}

llint solve(int a, int b) {
  return upper_bound(fairs.begin(), fairs.end(), b) -
    lower_bound(fairs.begin(), fairs.end(), a);
}

int main() {
  int k;
  init();
  scanf("%d", &k);
  for (int j = 0; j < k; ++j) {
    llint a, b;
    scanf("%lld%lld", &a, &b);
    printf("Case #%d: %lld\n", j + 1, solve(a, b));
  }
  return 0;
}

