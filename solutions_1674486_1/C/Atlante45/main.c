#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int diamond(int M[1500][20], int r[1500], int i);

int main(int argc, char *argv[]){
  int T = 0;
  
  FILE *input = fopen(argv[1], "r");
  FILE *output = fopen("output.txt", "w");
  //output = stdout;

  if(NULL == input || NULL == output)
    exit(EXIT_FAILURE);
  
  fscanf(input, "%d ", &T);
  
  for(int i = 0; i < T; i++){
    if(output != stdout)
      fprintf(stdout, "%d\n", i);
    
    int N = 0;
    int M[1500][20] = {0};
    int bool = 0;

    fscanf(input, "%d ", &N);
    for(int j = 0; j < N; j++){
      fscanf(input, "%d ", &M[j][0]);

      for(int k = 0; k < M[j][0]; k++){
	fscanf(input, "%d ", &M[j][k + 1]);
	M[j][k + 1]--;
      }
    }
    
    for(int j = 0; j < N; j++){
      int r[1500] = {0};      
      
      if(diamond(M, r, j)){
	bool = 1;
	break;
      }
    }
    
    fprintf(output, "Case #%d: ", i + 1);

    if(bool)
      fprintf(output, "Yes\n");
    else
      fprintf(output, "No\n");
  }
    
  fclose(input);
  fclose(output);
  
  return EXIT_SUCCESS;
}

int diamond(int M[1500][20], int r[1500], int i){
  
  if(r[i])
    return 1;
  else
    r[i] = 1;
  
  for(int j = 0; j < M[i][0]; j++){
    //fprintf(stdout, "%d %d\n", i, M[i][j+1]);

    if(diamond(M, r, M[i][j+1]))
      return 1;
  }
  
  
  return 0;
}
