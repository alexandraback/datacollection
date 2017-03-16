#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int gen(int val[3], int perm[3], int K, bool print) {
  int nocc[3][11][11];
  int total = 0;
  int rtab[3];
  for (int i = 0; i < 3; i++)
    rtab[perm[i]] = i;
  //printf("%d %d %d\n", rtab[0], rtab[1], rtab[2]);
  for (int k = 0; k < 3; k++)
    for (int i = 0; i < 11; i++)
      for (int j = 0; j < 11; j++)
          nocc[k][i][j] = 0;
  for (int j = 0; j < val[perm[0]]; j++) {
    for (int p = 0; p < val[perm[1]]; p++) {
      for (int s = 0; s < val[perm[2]]; s++) {
        int jj = j;
        int pp = (p + j) % val[perm[1]];
        int ss = (s + p) % val[perm[2]];
        if (nocc[0][jj][pp] < K && nocc[1][pp][ss] < K && nocc[2][jj][ss] < K) {
          total++;
          if (print) {
            int valtab[3];
            valtab[0] = jj+1;
            valtab[1] = pp+1;
            valtab[2] = ss+1;
            printf("%d %d %d\n", valtab[rtab[0]], valtab[rtab[1]], valtab[rtab[2]]);
          }
          nocc[0][jj][pp]++;
          nocc[1][pp][ss]++;
          nocc[2][jj][ss]++;
          //printf("set nocc 0 %d %d to %d\n", jj, pp, nocc[0][jj][pp]);
          //printf("set nocc 1 %d %d to %d\n", pp, ss, nocc[1][pp][ss]);
          //printf("set nocc 2 %d %d to %d\n", jj, ss, nocc[1][jj][ss]);
        }
      }
    }
  }
  return total;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    int J, P, S, K;
    scanf("%d%d%d%d", &J, &P, &S, &K);
    int tab[3];
    tab[0] = J;
    tab[1] = P;
    tab[2] = S;
    int perm[3] = {0, 1, 2};
    int nposs = 0;
    int best[3] = {0, 1, 2};
    //do {
      //printf("%d %d %d\n", perm[0], perm[1], perm[2]);
      int cnposs = gen(tab, perm, K, false);
      if (cnposs > nposs) {
        nposs = cnposs;
        best[0] = perm[0];
        best[1] = perm[1];
        best[2] = perm[2];
      }
    //} while(next_permutation(perm, perm+3));
    printf("Case #%d: %d\n", ncase+1, nposs);
    //int adj = min(P, max(K-(S-P), 0))-1;
    //if (J == 1 && nposs != min(K,P)*P - adj*(adj-1)/2) {
    //  printf("WTF\n");
    //}
    gen(tab, best, K, true);
  }
  return 0;
}
