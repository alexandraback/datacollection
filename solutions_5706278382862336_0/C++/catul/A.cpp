#define DBG 1

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

typedef vector<int>          vint;
typedef vector<unsigned int> vuint;
typedef vector<string>       vstr;
typedef long long            ll;
typedef unsigned long long   ull;
typedef pair<int, int>       pii;

#define FORN(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define FE  (i,x) for (typeof((x).begin()) (i) = (x).begin(); (i) != (x).end(); (i)++)

#define PB push_back
#define MP make_pair
#define A  first
#define B  second

#if DBG
#define db(x) { cout << __FUNCTION__ << "(" << __LINE__ << "): " << #x << " = " << x << endl; }
#define dbgp(...) fprintf(stderr, __VA_ARGS__);
#define dmp(table,n) { for (int __i = 0; __i < n; __i++) cerr << (__i==0 ? "" : ",") << table[__i]; cout << endl;}
ostream& operator<<(ostream& os, const vector<int> keys) {
  vector<int>::size_type sz = keys.size();
  for (unsigned int i = 0; i < sz; i++)
    os << keys[i] << " ";
  os << endl;
  return os;
}
void disp_table(int table[101][101], int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      dbgp("%d ", table[i][j]);
    dbgp("\n");
  }
  dbgp("\n");
}
#else
#define db(x)
#define dbgp(...)
#define dmp(t,n)
#define disp_table(t,n,m)
#endif

ull gcd(ull a, ull b) {
  ull c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}

bool is_powerof2(ull x) {
  if (x == 1) return true;
  if (x & (x-1)) return false;
  return true;
}

int main() {
  int T, num=1;

  for (cin >> T; T--;) {
    unsigned long long found;
    ull p, q;
    ull g;
    if (scanf("%llu/%llu\n",&p,&q) != 2)
      printf("ERROR reading case %d\n", num);

    // reduce the fraction
    g = gcd(p,q);
    p /= g;
    q /= g;

    if (!is_powerof2(q)) {
      printf("Case #%d: impossible\n", num++);
      continue;
    }

    found = 1;
    while(1) {
      if (2*p >= q) break;
      q /= 2;
      found++;
    }

    printf("Case #%d: %llu\n", num++, found);
  }


}
