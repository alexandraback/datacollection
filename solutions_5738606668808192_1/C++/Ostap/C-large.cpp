#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

const int MAXP = (1<<30);
//const int MAXP = (1<<28);
//const int MAXP = (1<<20);
char * P;
int KP;
int * Primes;

void sieve() {
  P = new char[MAXP];
  memset(P, 0, sizeof(char)*MAXP);
  KP = 0;
  for (int i = 2; i < MAXP; ++i)
    if (P[i] == 0) {
      Int st = i*(Int)i;
      if (st >= MAXP)
	break;
      for (int j = st; j < MAXP; j += i)
	P[j] = 1;
    }
  KP = 0;
  for (int i = 2; i < MAXP; ++i)
    if (P[i] == 0)
      ++KP;

  Primes = new int[KP];
  int pos = 0;
  for (int i = 2; i < MAXP; ++i)
    if (P[i] == 0)
      Primes[pos++] = i;
}

__int128 convert(Int x, int base) {
  __int128 res = 0;
  __int128 k = 1;
  while (x) {
    if (x & 1) {
      res += k;
    }
    k *= base;
    x >>= 1;
  }
  return res;
}

int divisor(__int128 x) {
  for (int i = 0; i < KP; ++i) {
    if (Primes[i] * (__int128) Primes[i] > x) break;
    if (x % Primes[i] == 0)
      return Primes[i];
  }
  return -1;
}

vector<int> check(Int x) {
  vector<int> res;
  for (int base = 2; base <= 10; ++base) {
    //    printf("testing %lld base %d\n", x, base);
    __int128 xb = convert(x, base);
    //    printf("checking %lld: %lld (%d)\n", x, xb, base);
    int div = divisor(xb);
    if (div == -1)
      return vector<int>();
    res.PB(div);
  }
  return res;
}

void print(Int x, vector<int> divs) {
  string bs;
  while (x) {
    if (x & 1)
      bs += '1';
    else
      bs += '0';
    x >>= 1;
  }
  reverse(ALL(bs));
  printf("%s", bs.c_str());
  for (int i = 0; i < divs.size(); ++i)
    printf(" %d", divs[i]);
  printf("\n");
}

int main()
{
  sieve();
  fprintf(stderr, "sieve done\n");
  int digs = 32;
  int need = 500;
  
  int start = 0;
  int finish = 1000000000;

  Int first = (1LL<<(digs-1)) + 1;
  Int last = (1LL<<digs) - 1;
  int found = 0;

  printf("Case #1:\n");
  Int num = first;
  for (int i = 0; i < finish && num < last && found < need; ++i) {
    if (i < start) continue;
    vector<int> res = check(num);
    if (!res.empty()) {
      print(num, res);
      fflush(stdout);
      ++found;
      fprintf(stderr, "Found: %d (i=%d)", found, i);
    }
    num += 2;
  }
  fprintf(stderr, "Found: %d\n", found);
  
  return 0;
};
