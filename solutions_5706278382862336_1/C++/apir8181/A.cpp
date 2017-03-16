#include <stdio.h>
#include <string.h>

#define LL long long
#define NOTFIND -1

void swap(LL &a, LL &b) {
  LL c = a;
  a = b;
  b = c;
}

LL gcd(LL a, LL b) {
  while (b != 0) {
    if (a < b) swap(a, b);
    else {
      LL c = a % b;
      a = b;
      b = c;
    }
  }
  return a;
}

bool is_two_exp(LL n) {
  while (n >= 2) {
    if (n % 2 != 0) return false;
    n /= 2;
  }
  return true;
}

int solve(LL p, LL q) {
  LL c = gcd(p, q);
  p /= c; q /= c;

  if (p == q) return 1;
  if (!is_two_exp(q)) return NOTFIND;

  int count = 0;
  while (p < q) {
    p *= 2;
    ++ count;
  }
  return count;
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 1; i <= t; ++ i) {
    LL p, q; char temp;
    scanf("%lld%c%lld", &p, &temp, &q);
    int count = solve(p, q);
    
    printf("Case #%d: ", i);
    if (count == NOTFIND) printf("impossible\n");
    else printf("%d\n", count);
  }
  return 0;
}
