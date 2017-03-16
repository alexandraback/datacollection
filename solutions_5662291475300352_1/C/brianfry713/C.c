#define DEBUG 1

#include "../../stdc++.h"
using namespace std;

struct node {
  long long D, M;
} nd[10];

int comp(const void *va, const void *vb) {
  node *a = (node *)va;
  node *b = (node *)vb;
  if(a->M != b->M)
    return b->M - a->M;
  return a->D - b->D;
}

int main() {
  long long cn, tc, N, n, H, ans;
  scanf("%lld", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld", &n);
    N = 0;
    while(n--) {
      scanf("%lld%lld%lld", &nd[N].D, &H, &nd[N].M);
      while(--H) {
	N++;
	nd[N].D = nd[N - 1].D, nd[N].M = nd[N - 1].M + 1;
      }
      N++;
    }

    qsort(nd, N, sizeof(nd[0]), comp);

    ans = 0;
    //nd[N - 1] is fastest (ties go to closer to start), go that fast
    for(int i = 0; i < N - 1; i++)
      if((360 - nd[i].D) * nd[i].M >= (720 - nd[N - 1].D) * nd[N - 1].M)
	ans++;
    printf("Case #%lld: %lld\n", cn, ans);
  }
  return 0;
}
