#include <bits/stdc++.h>
using namespace std;

int B, M;
int G[100][100];

int smf(int n) {
   return (n * (n + 1)) / 2;
}

bool at(int st, int i, int j) {
   int ii = smf(B) - smf(B - i) + j - i;
   return st & (1 << ii);
}

void buildGraph(int st) {
   for(int i = 0; i < B; i++) {
      for(int j = 0; j < B; j++) {
         if(j <= i) G[i][j] = 0;
         else G[i][j] = at(st, i, j);
      }
   }
}

int cf(int u = 0) {
   if(u == (B-1)) return 1;
   int rs = 0;
   for(int v = 0; v < B; v++) {
      if(v <= u) continue;
      if(G[u][v]) rs += cf(v);
   }
   return rs;
}

void ff() {
   for(int i = 0; i < (1 << smf(B)); i++) {
      buildGraph(i);
      if(cf() == M) {
         printf("POSSIBLE\n");
         for(int i = 0; i < B; i++) {
            for(int j = 0; j < B; j++) {
               printf("%d", G[i][j]);
            }
            printf("\n");
         }
         return;
      }
   }
   printf("IMPOSSIBLE\n");
}

int main() {
   freopen("inp.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
   int T; scanf("%d", &T);
   for(int cs = 1; cs <= T; cs++) {
      scanf("%d%d", &B, &M);
      printf("Case #%d: ", cs);
      ff();
   }
}
