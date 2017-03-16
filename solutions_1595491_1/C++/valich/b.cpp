#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int N, S, p;

int main() {
  int T;
  scanf("%d", &T);
  for (int q = 1; q <= T; q++) {
    scanf("%d %d %d", &N, &S, &p);
    int numgood = 0;
    int numrest = S;
    for (int i = 0; i < N; i++) {
      int t;
      scanf("%d", &t);
      int a = (t + 2) / 3;
      if ((t % 3 != 1) && t >= 2 && t <= 28 && a < p && (a + 1) >= p && numrest) {
        numgood++;
        numrest--;
      } else if (a >= p) {
        numgood++;
      }
    }

    printf("Case #%d: %d\n", q, numgood);
  }
  

  return 0;
}
