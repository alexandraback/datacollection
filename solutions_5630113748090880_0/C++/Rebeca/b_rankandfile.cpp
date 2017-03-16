#include <bits/stdc++.h>
using namespace std;

int n, t, aux;
int h[2510], l[60], c;

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <=t; tt++) {
    printf("Case #%d:", tt);
    memset(h, 0, sizeof(h));
    scanf("%d", &n);
    c = 0;
    for (int i = 0; i<(2*n-1)*n; i++) {
      scanf("%d", &aux);
      h[aux]++;
    }
    for (int i = 1; i<=2500; i++) {
      if (h[i]%2) l[c++] = i;
    }
    sort(l, l+c);
    for (int i = 0; i<n; i++) printf(" %d", l[i]);
    printf("\n");
  }
}
