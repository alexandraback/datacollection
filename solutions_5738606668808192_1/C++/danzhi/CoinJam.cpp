#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <functional>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <math.h>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
bool test = false;
const double pi = acos(-1.0);
const double eps = 1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\CoinJam";
void reopen(char* a) {
  char input[256], output[256];
  sprintf(input, "%s\\%s", rootdir, a);
  sprintf(output, "%s\\%s", rootdir, a);
  char *p = strstr(output, ".in");
  if (p) sprintf(p, ".out");
  else sprintf(&p[strlen(output)], ".out");
  freopen(input, "r", stdin);
  if (!test) freopen(output, "w", stdout);
}

int N;
int J;

__int64 pt[11][16];

const int NN = 65536;
bool pa[NN];
vector<int> primes;

void computePrimes() {
  for (int i = 2; i < NN; i++) pa[i] = true;
  pa[0] = false;
  pa[1] = false;
  for (int i = 2; i < NN; i++) {
    if (!pa[i]) continue;
    pa[i] = true;
    int k = i + i;
    while (k < NN) {
      pa[k] = false;
      k += i;
    }
  }
  for (int i = 2; i < NN; i++) {
    if (pa[i]) primes.push_back(i);
  }
}

int getPrimeFactor(__int64 v) {
  for (int i = 0; i < primes.size(); i++) {
    if (v % primes[i] == 0) {
      return primes[i];
    }
  }
  return 1;  // no prime factor found
}

__int64 getBaseNumber(char bits[17], int m) {
  __int64 v = 0;
  for (int i = 0; i < 16; i++) {
    if (bits[i] == '1') {
      v += pt[m][15-i];
    }
  }
  return v;
}

void solve(int t) {
  assert(N == 16 || N == 32);
  printf("Case #%d:\n", t);
  int factors[11];
  for (int i = 0; i < 11; i++) factors[i] = 0;
  char bits[17];
  bits[16] = 0;
  int count = 0;
  for (int n = (1 << 15) + 1; n < (1 << 16); n++) {
    if (n % 2 == 0) continue;
    for (int i = 0; i < 16; i++) {
      bits[i] = (n & (1 << (15 - i))) ? '1' : '0';
    }
    bool ok = true;
    for (int m = 2; m <= 10; m++) {
      __int64 v = getBaseNumber(bits, m);
      factors[m] = getPrimeFactor(v);
      // The prime factor must be nontrivial
      if (factors[m] == 1 || factors[m] == v) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("%s", bits);
      if (N == 32) printf("%s", bits);
      for (int m = 2; m <= 10; m++) {
        // if (test) printf(" %lld", getBaseNumber(bits, m));
        printf(" %d", factors[m]);
      }
      printf("\n");
      count++;
      if (count >= J) break;
    }
  }
}

int main() {
  // test = true;
  // reopen("sample.in");
  // reopen("C-small-attempt2.in");
  reopen("C-large.in");

  // build power table
  for (int m = 2; m <= 10; m++) {
    pt[m][0] = 1;
    for (int e = 1; e < 16; e++) {
      pt[m][e] = pt[m][e - 1] * m;
    }
  }

  computePrimes();

  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d %d", &N, &J);
    solve(qq);
  }
  return 0;
}
