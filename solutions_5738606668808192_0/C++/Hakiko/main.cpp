#include <bits/stdc++.h>

typedef unsigned long long UL;
typedef __int128 BN;

BN toBase(int b, BN n) {
  std::string res;
  while (n > 0) {
    res.push_back('0' + (n % b));
    n /= b;
  }
  BN out = 0;
  for (size_t i = res.length(); i-- > 0;) {
    out *= 10;
    out += res[i] - '0';
  }
  return out;
}

BN fromBinary(int to, BN n) {
  BN res = 0;
  BN b = 1;
  while (n > 0) {
    res += (n % 10) * b;
    n /= 10;
    b *= to;
  }
  return res;
}

void print(BN n) {
  std::vector<unsigned long long> tab;
  while (n > 0) {
    tab.push_back(n % 1000000000);
    n /= 1000000000;
  }
  printf("%llu", tab.size() > 0 ? tab.back() : 0);
  for (size_t i = tab.size() - 1; i-- > 0;) {
    printf("%09llu", tab[i]);
  }
}

BN findDiv(BN n) {
  for (BN i = 2; i < 100; ++i) {
    if (n % i == 0) {
      return i;
    }
  }
  return 1;
}

bool checkCoin(BN n) {
  std::vector<BN> divs;
  for (int i = 2; i <= 10; ++i) {
    int d = findDiv(fromBinary(i, n));
    if (d != 1) {
      divs.push_back(d);
    }
  }
  if (divs.size() == 9) {
    print(n);
    for (BN &b : divs) {
      printf(" ");
      print(b);
    }
    printf("\n");
    return true;
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, j;
    scanf("%d %d", &n, &j);
    printf("Case #%d:\n", i + 1);
    int found = 0;
    BN start = 1;
    start <<= n - 1;
    start += 1;
    while (found < j) {
      BN c = toBase(2, start);
      start += 2;
      if (checkCoin(c)) {
        found += 1;
      }
    }
  }
}
