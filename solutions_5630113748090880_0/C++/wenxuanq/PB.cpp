#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main () {
  FILE *filein;
  FILE *fileout;
  filein = fopen ("B_in.txt", "r");
  fileout = fopen ("B_out.txt", "w");
  int T;
  fscanf(filein, "%d", &T);
  for (int i = 0; i < T; i++){
    int N;
    fscanf(filein, "%d", &N);
    int *heights = (int *) malloc(sizeof(int) * 2501);
    for (int j = 0; j < 2501; j++){
        heights[j] = 0;
    }
    for (int j = 0; j < (2* N - 1) * N; j++){
        int cur;
        fscanf(filein, "%d", &cur);
        //fprintf(stdout, "%d ", cur);
        heights[cur] += 1;
    }
    fprintf(fileout, "%s%d%s", "Case #", i + 1, ": ");
    int c = 0;
    for (int j = 1; j < 2501; j++){
        if (heights[j] % 2 == 1){
            c++;
            if (c == N){
                fprintf(fileout, "%d\n", j);
            }
            else{
                fprintf(fileout, "%d ", j);
            }
        }
    }
  }
  return 0;
}

