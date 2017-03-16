#include <cstdio>
#include <cstdlib>
#include <cstring>
char T[10][10];
int cum[7][7], R, C, empt;
bool visit[7][7], trouve;
void dfs(int i, int j){
   if (visit[i][j] || T[i][j] == '*') return;
   
   if ( i > 0 && j> 0 && R >= i && C >= j ){
      visit[i][j] = 1;
      if (cum[i][j] == 0){
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
   if (trouve) return;
   for (int i = 1; i<=R; i++){
      for (int j = 1; j<=C; j++)
         //printf("%c(%d)%d", T[i][j], cum[i][j], visit[i][j]);
         printf("%c", T[i][j]);
      printf("\n");
   }
}
void check(){
   memset(cum, 0, sizeof(cum));
   int sum = 0;
   for (int i = 1; i<=R; i++)
      for (int j = 1; j<=C; j++){
         if (T[i][j] == '.'){ 
            cum[i][j] = (T[i-1][j]=='*')+(T[i+1][j]=='*') + (T[i-1][j-1]=='*')+
                        (T[i][j-1]=='*')+(T[i][j+1]=='*') + (T[i+1][j+1]=='*')+
                        (T[i-1][j+1]=='*')+(T[i+1][j-1]=='*');
            sum++;
            //printf("(%d, %d) -> %d\n", i, j, cum[i][j]);
         }
         else cum[i][j] = 9;
      }
      //printf("%d \n", sum);
   memset(visit, 0, sizeof(visit));
   for (int i = 1; i<=R; i++)
      for (int j = 1; j<=C; j++){
         if (cum[i][j] == 0 || empt == 1){
            //visit[i][j] = 1;
            dfs(i, j);
            for (int ki = 1; ki<=R; ki++)
               for (int kj = 1; kj<=C; kj++) sum -= visit[ki][kj];
               //print_sol();
               //printf("(%d, %d) %d\n", i, j, sum);
            if (sum == 0) {
               T[i][j] = 'c';
               print_sol();
               trouve = true;
            }
            return;
         }
      }
   
}
void fill(int i, int j,  int rem){
   if (trouve) return;
   if (i == R && j == C){
      if (rem>1) return;
      if (rem == 1) {
         T[i][j] = '*';
         check();
          //printf("------------------------------\n");
          //print_sol();
      }
      else{
         T[i][j] = '.';
         check();
         // printf("------------------------------\n");
         // print_sol();
      }
   }
   else{
      int z = i+1, k = 0;
      if (i == R) { z = 1; k = 1; }
      if (rem > 0) {
         T[i][j] = '*';
         fill (z, j+k, rem-1);
      }
      
      T[i][j] = '.';
      fill (z, j+k, rem);
      
   }
}

int main(){
   int M, t;
   freopen("in.in", "r", stdin);  
   freopen("out.out", "w", stdout);
   scanf("%d", &t);
   for (int kl = 1; kl <= t; kl++){
      scanf("%d%d%d", &R, &C, &M);   
      trouve = false;
      empt = R*C - M;
      memset(T, '.', sizeof(T));
      printf("Case #%d:\n", kl);
      fill(1, 1, M);
      if (!trouve) printf("Impossible\n");
   }
   return 0;
}
