#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float product(float *p, int A);

int main(int argc, char *argv[]){
  int T = 0, A = 0, B = 0;
  float result = 0;
  
  FILE *input = fopen(argv[1], "r");
  FILE *output = fopen("output.txt", "w");
  //output = stdout;

  if(NULL == input || NULL == output)
    exit(EXIT_FAILURE);
  
  fscanf(input, "%d ", &T);
  
  for(int i = 0; i < T; i++){
    if(output != stdout)
      fprintf(stdout, "%d\n", i);
    
    fscanf(input, "%d %d ", &A, &B);
    float prod = 1, *p = malloc(A*sizeof(float));

    for(int j = 0; j < A; j++){
      fscanf(input, "%f ", &p[j]);
      prod *= p[j];
    }

    result = B + 2;
    
    if(prod*(B - A + 1) + (1 - prod)*(2*B - A + 2) < result)
      result = prod*(B - A + 1) + (1 - prod)*(2*B - A + 2);
    
    for(int j = A - 1; j > 0; j--){
      prod = product(p, j);
      
      if(prod*(A - 2*j + B + 1) + (1 - prod)*(A - 2*j + 2*B + 2) < result)
	result = prod*(A - 2*j + B + 1) + (1 - prod)*(A - 2*j + 2*B + 2);
    }
    
    
    fprintf(output, "Case #%d: %f\n", i + 1, result);
    free(p);
  }

  fclose(input);
  fclose(output);
  
  return EXIT_SUCCESS;
}


float product(float *p, int A){
  float result = 1;
  
  for(int i = 0; i < A; i++)
    result *= p[i];
  
  return result;
}
