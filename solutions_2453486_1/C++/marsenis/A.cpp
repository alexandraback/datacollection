#include <cstdio>
#define X 1
#define O 10
#define T 100
#define DOT 0

using namespace std;

int trans(char x) {
   if (x == 'X') return X;
   else if (x == 'O') return O;
   else if (x == 'T') return T;
   else return DOT;
}

int main() {
   //freopen("A.in", "r", stdin);

   int tests, n = 4;
   char c;
   int tto[5][5], sum[2*n+3];

   scanf("%d\n", &tests);

   for (int t = 0; t < tests; t++) {
      int incomplete = 0;

      for (int i = 0; i < 2*n+3; i++)
            sum[i] = 0;

      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            scanf("%c", &c);
            tto[i][j] = trans(c);
            if (c == '.') incomplete = 1;
         }
         scanf("\n");
      }
      scanf("\n");

      int ans = 0;

      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            sum[i] += tto[i][j]; 
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            sum[n+i] += tto[j][i]; 
      for (int j = 0; j < n; j++)
         sum[2*n] += tto[j][j];
      for (int j = 0; j < n; j++)
         sum[2*n+1] += tto[j][n-j-1];

      for (int i = 0; !ans && i < 2*n+3; i++)
         if (sum[i] == 4*X || sum[i] == 3*X + T) ans = 1;
         else if (sum[i] == 4*O || sum[i] == 3*O + T) ans = 2;

      if (ans == 1) printf("Case #%d: X won\n", t+1);
      else if (ans == 2) printf("Case #%d: O won\n", t+1);
      else if (incomplete) printf("Case #%d: Game has not completed\n", t+1);
      else printf("Case #%d: Draw\n", t+1);
   }

	return 0;
}
