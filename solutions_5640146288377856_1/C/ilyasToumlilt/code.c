#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define BUF_SIZE 128

typedef struct _testCase {
  int R;
  int C;
  int W;
} testCase;

typedef struct _testCases {
  int T;
  testCase** Tarr;
} testCases;

testCases* tc;
int* soluce;

void parse(char* filename);
int resolveCase(int caseNumber);

int main(int argc, char** argv)
{
  /* parse */
  parse(argv[1]);

  /* soluce prepare */
  soluce = (int*)malloc(tc->T * sizeof(int));

  /* resolving */
  int i;
  for(i=0; i<tc->T; i++)
    soluce[i] = resolveCase(i);

  /* print result */
  for(i=0; i<tc->T; i++)
    printf("Case #%d: %d\n", (i+1), soluce[i]);
  
  return EXIT_SUCCESS;
}

int resolveCase(int caseNumber){
  int R = tc->Tarr[caseNumber]->R;
  int C = tc->Tarr[caseNumber]->C;
  int W = tc->Tarr[caseNumber]->W;

  int reste = C - W;
  int nbDep = reste / W;
  int mod = (reste % W) ? 1 : 0;
  int i;
  int ret = 0;
  for(i=0; i<R; i++)
    ret += nbDep;
  

  return (ret+W+mod+(R-1));
}

void parse(char* filename)
{
  tc = (testCases*)malloc(sizeof(testCases));
  
  FILE* f = fopen(filename, "r");
  char buffer[BUF_SIZE];

  /* parsing T */
  fgets(buffer, BUF_SIZE, f);
  tc->T    = atoi(buffer);
  tc->Tarr = (testCase**)malloc(tc->T * sizeof(testCase*));

  /* parsing other lines */
  int counter = 0, i;
  while( fgets(buffer, BUF_SIZE, f) ){
    tc->Tarr[counter] = (testCase*)malloc(sizeof(testCase));
    sscanf(buffer, "%d %d %d", &(tc->Tarr[counter]->R),
	   &(tc->Tarr[counter]->C), &(tc->Tarr[counter]->W));
    counter++;
  }
 
  fclose(f);

  return;
}
