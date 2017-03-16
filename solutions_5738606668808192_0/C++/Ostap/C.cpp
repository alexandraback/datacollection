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

const int MAXP = (1<<20);
int P[MAXP] = {0};

void sieve() {
  for (int i = 2; i < MAXP; ++i)
    for (int j = i*i; j < MAXP; j += i)
      P[j] = 1;
}

Int convert(Int x, int base) {
  Int res = 0;
  Int k = 1;
  while (x) {
    if (x & 1) {
      res += k;
    }
    k *= base;
    x >>= 1;
  }
  return res;
}

int divisor(Int x) {
  for (int i = 2; i < x && i < MAXP; ++i) {
    if (P[i] == 0) {
      if (x % i == 0)
	return i;
    }
  }
  return -1;
}

vector<int> check(Int x) {
  vector<int> res;
  for (int base = 2; base <= 10; ++base) {
    //    printf("testing %lld base %d\n", x, base);
    Int xb = convert(x, base);
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
  printf("Case #1:\n");
  sieve();
  //  printf("sieve done\n");
  int digs = 16;
  Int first = (1LL<<(digs-1)) + 1;
  Int last = (1LL<<digs) - 1;
  int start = 0;
  int finish = 40000;
  int found = 0;

  Int num = first;
  for (int i = 0; i < finish && num < last && found < 50; ++i) {
    if (i < start) continue;
    vector<int> res = check(num);
    if (!res.empty()) {
      print(num, res);
      ++found;
    }
    num += 2;
  }
  
  return 0;
};
