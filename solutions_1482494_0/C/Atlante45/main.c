#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
  int T = 0;
  
  FILE *input = fopen(argv[1], "r");
  FILE *output = fopen("output.txt", "w");
  //output = stdout;

  if(NULL == input || NULL == output)
    exit(EXIT_FAILURE);
  
  fscanf(input, "%d ", &T);
  
  for(int i = 0; i < T; i++){
    int N = 0, result = 0, stars = 0;;
    
    if(output != stdout)
      fprintf(stdout, "%d\n", i);
    
    fscanf(input, "%d ", &N);
    int p[1100][3] = {0};

    for(int j = 0; j < N; j++){
      fscanf(input, "%d %d ", &p[j][0], &p[j][1]);
      p[j][2] = 0;
    }
    
    while(stars != 2*N){
      int bool = 0;

      for(int j = 0; j < N; j++)
	if(p[j][1] <= stars && p[j][2] < 2){
	  stars += 2 - p[j][2];
	  p[j][2] = 2;
	  result++;
	  bool = 1;
	}

      if(!bool)
	for(int j = 0; j < N && !bool; j++)
	  if(p[j][0] <= stars && p[j][2] == 0){
	    stars += 1;
	    p[j][2] = 1;
	    result++;
	    bool = 1;
	  }
      
      
      if(!bool)
	break;
    }
      
    if(stars == 2*N)
      fprintf(output, "Case #%d: %d\n", i + 1, result);
    else
      fprintf(output, "Case #%d: Too Bad\n", i + 1);
    
  }

  fclose(input);
  fclose(output);
  
  return EXIT_SUCCESS;
}
