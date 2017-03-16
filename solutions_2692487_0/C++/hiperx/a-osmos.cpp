#include <cstdio>
#include <algorithm>

using namespace std;

int nt, nt0;
int a, n;
const int MAXN = 128;
int mote[MAXN];
int ans[MAXN], sum[MAXN];

int qt(int &a, int x) {
  int ct = 0;
  while(a <= x) {
    a += a-1;
    ++ct;
  }
  return ct;
}

int calc(int a, int i) {
  int k = 0, a2 = a;
  if(i == n) return 0;
  if(a <= mote[i])
    k = qt(a2, mote[i]);
  return min(calc(a2+mote[i], i+1)+k, calc(a, i+1)+1);
}

int main() {
  scanf(" %d", &nt0);

  for(nt=1 ; nt<=nt0 ; ++nt) {
    scanf(" %d %d", &a, &n);

    for(int i=0 ; i<n ; ++i)
      scanf(" %d", &mote[i]);
    sort(mote, mote+n);

    if(a == 1) {
      printf("Case #%d: %d\n", nt, n);
      continue;
    }

    printf("Case #%d: %d\n", nt, calc(a, 0));
  }
  return 0;
}
