#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iostream>
#include <cstring>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

using namespace std;

template<class T> inline void umax(T &a,T b){if(a < b) a = b;}
template<class T> inline void umin(T &a,T b){if(a > b) a = b;}
template<class T> inline T abs(T a){return a > 0 ? a : -a;}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

int pdiv[44];

int getPrimeDiv(ll x) {
  for (int i = 2; ll(i) * i <= x; i++) {
    if (x % i == 0) {
      return i;
    }
  }
  return -1;
}

bool test(int x, int k) {
  return (x >> k) & 1;
}

int main() {
  printf("Case #1:\n");
  int need = 50;
  for (int x = 0; x < (1 << 16); x++) {
    if (x % 1000 == 0) {
      eprintf("x = %d\n", x);
    }
    if (!test(x, 0)) continue;
    if (!test(x, 15)) continue;
    bool good = true;
    for (int base = 2; base <= 10; base++) {
      ll v = 0;
      for (int i = 15; i >= 0; i--) {
        v *= base;
        v += test(x, i);
      }
      pdiv[base] = getPrimeDiv(v);
      good &= (pdiv[base] != -1);
    }
    if (good) {
      for (int i = 15; i >= 0; i--) {
        printf("%d", test(x, i));
      }
      printf(" ");
      for (int i = 2; i <= 10; i++) {
        printf("%d ", pdiv[i]);
      }
      printf("\n");
      need--;
      if (need == 0) {
        return 0;
      }
    }
  }
  return 0;
}