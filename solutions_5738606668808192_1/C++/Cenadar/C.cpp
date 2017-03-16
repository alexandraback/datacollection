#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second
#define GET_RUNTIME_ERROR *(int*)(NULL) = 1

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

const int l = 32;
const int n = 500;

LL bin_to_LL(string s) {
  LL res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res |= LL(s.rbegin()[i] - '0') << i;
  }
  return res;
}

string LL_to_bin(LL v) {
  string s;
  while (v) {
    s += '0' + (v & 1);
    v >>= 1;
  }
  return string(s.rbegin(), s.rend());
}

LL convert(string val, int base) {
  LL res = 0;
  LL p = 1;
  for (int i = 0; i < val.size(); ++i) {
    res += (val.rbegin()[i] - '0') * p;
    p *= base;
  }
  return res;
}

int test(LL v) {
  FOR(i, 2, 1000) {
    if (v % i == 0) {
      return i;
    }
  }
  return -1;
}

void solve() {
  string s(l, '0');
  s[0] = s.rbegin()[0] = '1';

  vector<pair<string, vector<int>>> ans;

  LL val = bin_to_LL(s);
  for ( ; ans.size() < n; val += 2) {
    vector<int> res;
    string bin_val = LL_to_bin(val);
    for (int i = 2; i <= 10; ++i) {
      int r = test(convert(bin_val, i));
      if (r != -1) {
        res.PB(r);
      } else {
        break;
      }
    }
    if (res.size() == 9) {
      ans.PB(MP(bin_val, res));

      cout << ans.back().first;
      for (int i = 0; i < res.size(); ++i) {
        cout << " " << ans.back().second[i];
      }
      cout << endl;
    }
  }
}

int main() {
#ifdef    CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("/home/maksym/Downloads/B-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif // CENADAR_DEBUG

  printf("Case #1:\n");
  solve();

  return 0;
}
