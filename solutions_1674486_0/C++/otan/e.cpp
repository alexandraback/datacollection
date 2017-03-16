#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <errno.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>

#define MAX_INHERIT 1000
#define MAX_INHERIT_NODE 10

using namespace std;

int main() {
   FILE *in = fopen("in.txt", "r");
   FILE *out = fopen("out.txt", "w");
   
   assert(in != NULL && out != NULL);
   int args;
   
   fscanf(in, "%d\n", &args);

   for (int TT = 0; TT < args; TT++) {
      int classes;
      fscanf(in, "%d\n", &classes);
      int nodes[classes+1][classes+1];
      memset(nodes, -1, sizeof(nodes));
      
      for (int JJ = 1; JJ <= classes; JJ++) {
         int connected;
         fscanf(in, "%d", &connected);
         
         for (int KK = 0; KK < connected; KK++) {
            fscanf(in, "%d", &(nodes[JJ][KK+1]));
         }
         fscanf(in, "\n");
      }
      
      bool yes = false;
      int reaches[classes+1];
      
      /*for (int i = 0 ; i < classes+1; i++) {
         for (int j = 0; j < classes+1; j++) {
            printf("%d ", nodes[i][j]);
         }
         printf("\n");
      }*/
      
      for (int i = 1; i <= classes; i++) {
         memset(reaches, 0, sizeof(reaches));
         
         queue<int> proceed;
         for (int j = 1; j <= classes && nodes[i][j] != -1; j++) {
            proceed.push(nodes[i][j]);
            //printf("Pushed %d\n", nodes[i][j]);
         }
         
         int count = 1;
         int zzz = proceed.size();
         while (zzz) {
            for (int j = 0; j < zzz; j++) {
               //if (count > 1) {
                  reaches[proceed.front()]++;
               //}
               for (int k = 1; k <= classes && nodes[proceed.front()][k] != -1; k++) {
                  if (nodes[proceed.front()][k] != i) {
                     proceed.push(nodes[proceed.front()][k]);
                     //printf("%d -> %d\n", proceed.front(), nodes[proceed.front()][k]);
                  }
               }               
               proceed.pop();
            }
            count++;  
            zzz = proceed.size();            
         }
         
         for (int i = 1; i <= classes; i++) {
            if (reaches[i] >= 2) {
               yes = true;
               break;
            }
         }
      }
      
      printf("\n");
      printf("\n");
      fprintf(out, "Case #%d: %s\n", TT+1, yes ? "Yes" : "No");
   }
   
   fclose(in);
   fclose(out);
   
   return EXIT_SUCCESS;
}