#include <cstdio>
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;


int main() {

  int t, T;
  scanf("%d", &T);

  for (t=0; t<T; t++) {
    int C, D, V;
    scanf("%d%d%d", &C, &D, &V);

    int v[V+1]; // co mozme vyskladat
    for (int i=0; i<=V; i++) v[i] = 0;
    v[0] = 1;
    int vyskladanych = 0;
    for (int i=0; i<D; i++) {
      int denom;
      scanf("%d", &denom);
          for (int vl = V; vl>= 0; vl--) {
        if (vl + denom <= V && v[vl] && !v[vl+denom]) { 
          v[vl+denom] = 1;
          vyskladanych++;
        }
      }
    }
    vyskladanych--;
    int dopl = 0;
    while (vyskladanych < V) {
      int n = -1;
      for (int i=0; i<=V; i++) {
        if (!v[i]) { n = i; break; }
      }
      if (n == -1) break;;
      for (int vl = V; vl >= 0; vl--) {
        if (vl + n <= V && v[vl] && !v[vl+n]) {
          v[vl+n] = 1;
          vyskladanych++; 
        }
      }
      dopl++;
    }
    printf("Case #%d: %d\n", t+1, dopl); 
  }
}

