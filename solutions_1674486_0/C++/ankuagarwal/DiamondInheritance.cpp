#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int n;
int matrix[1001][1001];

void initialize (){
   for (int i = 1; i <= n; i++)
      for ( int j = 1; j <= n; j++)
          matrix[i][j] = 0;
}

void print(){
   for ( int i = 1; i <= n; i++){
      for (  int j = 1; j <= n; j++){
         printf("%d", matrix[i][j]);
      }
      printf("\n");
   }
}

int bfs(int i){
   int mark[n];
   for ( int j = 1; j <= n; j++)
      mark[j] = 0;
   mark[i] = 1;

   queue <int> q;
   q.push(i);

   while ( ! q.empty()){
     int k = q.front();
     q.pop();

    for ( int j = 1; j <= n; j++){
      if ( matrix[k][j] == 1) {
         if ( mark[j] == 1)
           return 1;
         q.push(j);
         mark[j] = 1;
      }
    }
   }
   return 0;
}

void solve (){
   for ( int i = 1; i <= n; i++){
         if(bfs(i) == 1) {
          printf("Yes\n");
          return;
         }
   }
   printf("No\n");

}

main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int t;
    scanf ("%d", &t);

    for ( int i = 1; i <= t; i++){
       scanf ("%d", &n);
       initialize();
       for ( int j = 1; j <= n; j++){
          int m;
          scanf ("%d", &m);
          for ( int k = 0; k < m; k++){
              int x;
              scanf ("%d", &x);
              matrix[j][x] = 1;
          }
       }
     //  print();
       printf("Case #%d: ", i);
       solve ();
    }
}
