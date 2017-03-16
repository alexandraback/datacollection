#include <cstdio>
#include <cstdlib>

int min (int a, int b) {
   if (a < b) {
      return a;
   }
   return b;
}

int main (int argc, char **argv) {
   FILE *fin = fopen ("input.txt", "r");
   FILE *fout = fopen ("output.txt", "w");
   
   int T;
   fscanf (fin, "%d", &T);
   
   int activities[10005];
   
   for (int i = 0; i < T; i++) {
      int E, R, N;
      fscanf (fin, "%d %d %d", &E, &R, &N);
      for (int j = 0; j < N; j++) {
         fscanf (fin, "%d", &activities[j]);
      }
      int curE = E;
      long long curScore = 0;
      for (int j = 0; j < N; j++) {
         int nextHeighest;
         for (int k = j; k < N; k++) {
            if (k == N-1) {
               nextHeighest = 10000000;
            }
            if (activities[k] > activities[j]) {
               nextHeighest = k - j;
               k = N;
            }
         }
         long long numRegen = R * nextHeighest;
         if (curE + numRegen > E) {
            int energyToSpend = min ((curE + numRegen) - E, curE);
            curScore +=  energyToSpend * activities[j];
            curE -= energyToSpend;
            //printf ("spending %d energy on activity %d worth %d\n", energyToSpend, j, activities[j]);
         }
         curE += R;
      }
      fprintf (fout, "Case #%d: %d\n", i+1, curScore);
      //system ("pause");
   }
}
