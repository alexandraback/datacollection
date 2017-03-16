#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <functional>
#include <bitset>
#include <list>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, p, k) for(int i = (p); i <= (k); ++i)
#define FORD(i, p, k) for(int i = (p); i >= (k); --i)
#define FOREACH(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

#define mp make_pair
#define pb push_back
#define st first
#define nd second

void solve(int X, char W, char E) {
  if (X < 0) swap(W, E), X = -X;
  REP(i, X) printf("%c%c", W, E);
}

int main() {
  int Z; scanf("%d", &Z);
  FOR(t, 1, Z) {
    int X, Y;
    scanf("%d %d", &X, &Y);
    printf("Case #%d: ", t);
    solve(X, 'W', 'E');
    solve(Y, 'S', 'N');
    printf("\n");
  }
  return 0;
}
