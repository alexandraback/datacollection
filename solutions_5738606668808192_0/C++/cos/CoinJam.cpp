 // g++ -Wall hoge.cpp -lgmpxx -lgmp
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

#include <gmpxx.h>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d:", test_case);
    puts("");
    solve();
  }
}

#include <bitset>
const int PRIME_SIZE = 10000;
int psize;
bitset<PRIME_SIZE + 1> bprime;
int prime[PRIME_SIZE / 10 + 1000];
int Eratosthenes(int n) {
  psize = 0;
  bprime.set();
  bprime[0] = bprime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!bprime[i]) { continue; }
    prime[psize++] = i;
    if ((long long)i * i > n) { continue; }
    for (int j = i * i; j <= n; j += i) {
      bprime[j] = false;
    }
  }
  return psize;
}

// need Eratosthenes
vector<pair<mpz_class, int> > PrimeFactorization(mpz_class n) {
  assert(n > 1);
  assert(psize != 0);
  vector<pair<mpz_class, int> > ret;
  for (int i = 0; i < psize && (mpz_class)prime[i] * prime[i] <= n; i++) {
    int size = 0;
    while (n % prime[i] == 0) {
      n /= prime[i];
      size++;
    }
    if (size != 0) { ret.push_back(make_pair((mpz_class)prime[i], size)); }
  }
  if (n != 1) { ret.push_back(make_pair(n, 1)); }
  return ret;
}

mpz_class sto_mpz_class(char *str, int base) {
  int len = strlen(str);
  mpz_class ret = 0;
  REP(i, len) {
    ret = ret * base + (str[i] - '0');
  }
  return ret;
}

void solve() {
  Eratosthenes(PRIME_SIZE);
  int l, m;
  scanf("%d %d", &l, &m);
  ll digit = (1LL << (l - 1)) + 1;
  vector<pair<string, vector<mpz_class> > > ans;
  while ((int)ans.size() < m) {
    char str[100];
    REP(i, l) { str[i] = ((digit >> (l - i - 1)) & 1) + '0'; }
    str[l] = 0;
    vector<mpz_class> lans;
    FOREQ(base, 2, 10) {
      mpz_class v = sto_mpz_class(str, base);
      vector<pair<mpz_class, int> > factor = PrimeFactorization(v);
      if (factor.size() <= 1) { goto next; }
      lans.push_back(factor[0].first);
    }
    ans.push_back(make_pair((string)str, lans));
next:
    digit += 2;
  }
  FORIT(it1, ans) {
    cout << it1->first;
    FORIT(it2, it1->second) {
      cout << " " << *it2;
    }
    cout << endl;
  }
}
