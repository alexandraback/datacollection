#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())
typedef long long LL;

const int N = 1005;
double a[N], b[N];
void solve(int cs) {
  printf("Case #%d: ", cs);
  int N;
  scanf("%d", &N);
  for(int i=0;i<N;i++) scanf("%lf", &b[i]);
  for(int i=0;i<N;i++) scanf("%lf", &a[i]);
  sort(a, a+N);
  sort(b, b+N);
  int xc = 0, xd = 0;
  for(int i=0, j=0;i<N;i++) {
    while(j<N && a[j] < b[i]) ++j;
    if(j<N) ++xc, ++j;
  } // N - xc;
  for(int i=0, j=0;i<N;i++) {
    while(j<N && b[j] < a[i]) ++j;
    if(j<N) ++xd, ++j;
  }
  printf("%d %d\n", xd, N-xc);
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(int cs=1;cs<=T;cs++) solve(cs);
  return 0;
}
