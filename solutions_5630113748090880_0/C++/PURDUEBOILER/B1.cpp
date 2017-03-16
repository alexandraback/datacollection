#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<algorithm>
#include <vector>
using namespace std;
int lists[100][50];
map<int, int> loc;
int heights[2510];
int main() {
   int T;
   scanf("%d", &T);
   for (int t = 0; t < T; t++) {
      int N;
      scanf("%d", &N);
      loc.clear();
      int count = 0;
      for (int i = 0; i < 2*N-1; i++) {
         for (int j = 0; j < N; j++) {
            scanf("%d", &lists[i][j]);
            if (loc.find(lists[i][j]) == loc.end()) {
               heights[count++] = lists[i][j];
               loc[lists[i][j]] = 1; 
            } else {
               loc[lists[i][j]] ++; 
            }
         }
      }
      vector<int> output(50);
      int count2 = 0;
      for (int k = 0; k < count; k++) {
         if (loc[heights[k]] % 2) {
            output[count2++] = heights[k];
         }
      }

      sort(output.begin(), output.begin()+count2);
     
      printf("Case #%d:", t+1); 
      for (int k = 0;  k < count2; k++) {
         printf(" %d", output[k]);
      }
      printf("\n");
   }
   return 0;
}
