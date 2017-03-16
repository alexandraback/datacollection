#include <algorithm>
#include <cstdio>
#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef vector<int> VI;
typedef pair<int, int> PII;

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int A = ri(), B = ri(), K = ri(), ans = 0;
    REP(i, A)
      REP(j, B)
        if ((i&j) < K)
          ans++;
    printf("Case #%d: %d\n", cc, ans);
  }
}
