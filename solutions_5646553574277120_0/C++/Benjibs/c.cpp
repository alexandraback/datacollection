#include <cstdio>
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>


//#define DEBUG

#ifdef DEBUG
#define DBG(...) printf(__VA_ARGS__)
#else
#define DBG(...)
#endif

using namespace std;

typedef long long ll;


int main() {

  int t, T;
  scanf("%d", &T);

  for (t=0; t<T; t++) {
    int C, D, V;
    scanf("%d%d%d", &C, &D, &V);

    int vyskl[V+1]; // co mozme vyskladat
    for (int i=0; i<=V; i++) vyskl[i] = 0;
    vyskl[0] = 1;
    // čo môžeme vyskladať
    int vyskladanych = 0;
    for (int i=0; i<D; i++) {
      int denom;
      scanf("%d", &denom);
      for (int v = V; v >= 0; v--) {
        if (v + denom <= V && vyskl[v] && !vyskl[v+denom]) { 
          vyskl[v+denom] = 1;
          vyskladanych++;
        }
      }
    }
    for (int i=0; i<=V;i++) DBG("%d,", vyskl[i]);
    DBG("\nVyskladanych: %d\n", vyskladanych);
    // teraz doplname tie, ktore este nemozeme vyskladat
    vyskladanych--;
    int doplnenych = 0;
    while (vyskladanych < V) {
      // najdeme prve este nevyskladane
      int num = -1;
      for (int i=0; i<=V; i++) {
        if (!vyskl[i]) { num = i; break; }
      }
      if (num == -1) break;;
      // doplnime to, co ide
      for (int v = V; v >= 0; v--) {
        if (v + num <= V && vyskl[v] && !vyskl[v+num]) {
          vyskl[v+num] = 1;
          vyskladanych++; 
        }
      }
      doplnenych++;
    }
    printf("Case #%d: %d\n", t+1, doplnenych); 
  }

  return 0;
}

