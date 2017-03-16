#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)

using namespace std;

int A, B;
bool bylo[250000];

void solve() {
  scanf("%d%d", &A, &B);
  int k = 0; int x = A; int MOD = 1; while (x>0) { x/=10; MOD *= 10; k++; }
  MOD /= 10;
  FOR (i, A, B+1)
    bylo[i] = 0;
  long long ret = 0;
  FOR (i, A, B+1) {
    if (bylo[i]==0) {
      bylo[i] = 1;
      int x = i;
      long long pocet = 1;
      FOR (j, 0, k) {
	x = x/10 + MOD*(x%10);
	if (x>=A && x<=B && bylo[x]==0) {
	  bylo[x] = 1;
	  pocet++;
	}
      }
      ret += pocet*(pocet-1)/2;
    }
  }
  printf("%lld\n", ret);
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}
