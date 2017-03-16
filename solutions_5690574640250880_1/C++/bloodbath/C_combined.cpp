#include <cstdio>
#include <cstdlib>
#include <cstring>
char A[51][51];
char fT[10][10];
int fcum[7][7], R, C, empfT;
bool visifT[7][7], fTrouve;
void dfs(int i, int j){
   if (visifT[i][j] || fT[i][j] == '*') return;
   
   if ( i > 0 && j> 0 && R >= i && C >= j ){
      visifT[i][j] = 1;
      if (fcum[i][j] == 0){
         dfs(i+1, j+1);
         dfs(i+1, j-1);
         dfs(i-1, j-1);
         dfs(i-1, j+1);
         dfs(i+1, j);
         dfs(i-1, j);
         dfs(i, j+1);
         dfs(i, j-1);
      }
   }
}
void print_sol(){
   if (fTrouve) return;
   for (int i = 1; i<=R; i++){
      for (int j = 1; j<=C; j++)
         //printf("%c(%d)%d", fT[i][j], fcum[i][j], visifT[i][j]);
         printf("%c", fT[i][j]);
      printf("\n");
   }
}
void check(){
   memset(fcum, 0, sizeof(fcum));
   int sum = 0;
   for (int i = 1; i<=R; i++)
      for (int j = 1; j<=C; j++){
         if (fT[i][j] == '.'){ 
            fcum[i][j] = (fT[i-1][j]=='*')+(fT[i+1][j]=='*') + (fT[i-1][j-1]=='*')+
                        (fT[i][j-1]=='*')+(fT[i][j+1]=='*') + (fT[i+1][j+1]=='*')+
                        (fT[i-1][j+1]=='*')+(fT[i+1][j-1]=='*');
            sum++;
            //printf("(%d, %d) -> %d\n", i, j, fcum[i][j]);
         }
         else fcum[i][j] = 9;
      }
      //printf("%d \n", sum);
   memset(visifT, 0, sizeof(visifT));
   for (int i = 1; i<=R; i++)
      for (int j = 1; j<=C; j++){
         if (fcum[i][j] == 0 || empfT == 1){
            //visifT[i][j] = 1;
            dfs(i, j);
            for (int ki = 1; ki<=R; ki++)
               for (int kj = 1; kj<=C; kj++) sum -= visifT[ki][kj];
               //print_sol();
               //printf("(%d, %d) %d\n", i, j, sum);
            if (sum == 0) {
               fT[i][j] = 'c';
               print_sol();
               fTrouve = true;
            }
            return;
         }
      }
   
}
void fill(int i, int j,  int rem){
   if (fTrouve) return;
   if (i == R && j == C){
      if (rem>1) return;
      if (rem == 1) {
         fT[i][j] = '*';
         check();
          //printf("------------------------------\n");
          //print_sol();
      }
      else{
         fT[i][j] = '.';
         check();
         // printf("------------------------------\n");
         // print_sol();
      }
   }
   else{
      int z = i+1, k = 0;
      if (i == R) { z = 1; k = 1; }
      if (rem > 0) {
         fT[i][j] = '*';
         fill (z, j+k, rem-1);
      }
      
      fT[i][j] = '.';
      fill (z, j+k, rem);
      
   }
}
int main(){
   freopen("large.in", "r", stdin);
   freopen("out.out", "w", stdout);
   int t, R, C, M, mn, cnt;
   scanf("%d", &t);
   for (int kl = 1; kl <= t; kl++){
      scanf("%d%d%d", &R, &C, &M);
      M = R*C - M;
      memset(A, '*', sizeof(A));
      mn = R>C?C:R;
      //printf("Case #%d: (%d %d %d)\n", kl, R, C, R*C - M);
      printf("Case #%d:\n", kl);
      if ((M == 2 || M == 3) && mn!=1) {
         printf("Impossible\n");
         continue;
      }
      if (mn == 2 && (R*C-M)%2 == 1) {
         printf("Impossible\n");
         continue;
      }
      if (R < 5 && C < 5){
         fTrouve = false;
         empfT = R*C - M;
         memset(fT, '.', sizeof(fT));
         fill(1, 1, M);
         if (!fTrouve) printf("Impossible\n");
      }
      cnt = 0;
      int lst;
      bool found = false;
      for (int k = 1; k <= mn && cnt < M; k++){
         lst = 0;
         for (int j = 1; j <k && cnt < M; j++){
            lst = j;
            A[k][j] = '.';
            cnt++;
         }
         if (lst == 1 && k<=3 && mn>2 && cnt == M ) found = true;
         else if (lst == 1 && k!=2 && cnt == M ){
            A[k-1][k-1] = '*';
            A[k][2] = '.';
         }
         lst = 0;
         for (int j = 1; j < k && cnt < M; j++){
            lst = j;
            A[j][k] = '.';
            cnt++;
         }
         if (lst == 1 && k<=3 && mn>2 && cnt == M ) found = true;
         else if (lst == 1 && k!=2 && cnt == M ){
            A[k][k-1] = '*';
            A[2][k] = '.';
         }
         if (cnt < M){
            A[k][k] = '.';
            cnt++;
         }
      }
      if (cnt < M){
         int last = 0;
         if (R>C)
            for (int i = mn+1; i<=R && cnt < M; i++){
               last  = 0;
               for (int j = 1; j <= C && cnt < M; j++) {
                  A[i][j] = '.';
                  cnt++;
                  last++;
               }
               if (last == 1 && mn!=1) {
                  A[i][2] = '.';
                  A[i-1][C] = '*';
                  //if (kl==17) printf("ho\n");
               }
            }
         else 
            for (int i = mn+1; i<=C && cnt < M; i++){
               last  = 0;
               for (int j = 1; j <= R && cnt < M; j++) {
                  A[j][i] = '.';
                  cnt++;
                  last++;
               }
               if (last == 1 && mn!=1) {
                  A[2][i] = '.';
                  A[R][i-1] = '*';
                  // if (kl==17) printf("hi\n");
               }
            }
      }
      A[1][1] = 'c';
      if (found) printf("Impossible\n");
      else
         for (int i = 1; i<=R; i++){
            for (int j = 1; j<=C; j++)
               printf("%c", A[i][j]);
            printf("\n");
         }
   }
   return 0;
}
