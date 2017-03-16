#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <cstdlib>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz size
#define FOR(I,X) for(int I=0;I<(X);I++)
#define FORD(I,X) for(int I=(X)-1;I>=0;I--)
#define REP(I,V,X) for(int I=(V);I<=(X);I++)
#define REPD(I,V,X) for(int I=(V);I>=(X);I--)

using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;

int t;
int x, y, n, j, k;
long double res;
long double ile[10000];

long double prob(int n, int k)
{
  long double pot = 1, sum = 0;
 // printf("POT: %d %d\n", n, k);
  memset(ile, 0, sizeof(ile));
  ile[0] = 1;
  REP(i,1,n) { REPD(j,i,1) ile[j] = ile[j] + ile[j-1]; pot *= 2; }
  REP(i,k,n) sum += ile[i];
  return sum / pot;
}

int main()
{
  scanf("%d", &t);
  FOR(i,t) {
    scanf("%d %d %d", &n, &x, &y);
    if (x < 0) x = -x;
    if ((x + y) % 2 == 1) res = 0;
    else {
      int row = (x + y) / 2;
      for (j = 0, k = 1; j < row; j++, k += 4) n -= k;
      if (n <= 0) res = 0;
      else if (n >= k || k/2+y+1<=n) res = 1;
      else if (x == 0) res = 0;
      else res = prob(n, y+1);
    }
    printf("Case #%d: %Lf\n", i+1, res);
  }
  return 0;
}
