#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAXN 201
#define MAXS 101

void myfunction(FILE *fp)
{
  float* curr = malloc(sizeof(float)*201);
  int totline;
  int i, j;
  int N;
  int reducenum;
  float equal;
  float total;
  float reduce;
  float* result = malloc(sizeof(float)*201);
  fscanf(fp, "%d", &totline);
  for(i=1; i<=totline; i++){
    printf("Case #%d:", i);
    total = 0;
    reducenum = 0;
    reduce = 0;
    fscanf(fp, "%d", &N);
    for(j=0; j<N; j++){
      fscanf(fp, "%f", &curr[j]);
      total += curr[j];
    }
    equal = 2*total / N;
    for(j=0; j<N; j++){
      result[j] = (equal - curr[j]) / total*100;
    }
    for(j=0; j<N; j++){
      if(result[j] < 0){
        reduce += curr[j];
        reducenum ++;
        result[j] = 0.0;
      }
    }
    equal = (2*total - reduce) / (N - reducenum);
    for(j=0; j<N; j++){
      if(result[j] != 0.0){
        result[j] = (equal - curr[j])/total*100;
      }
      printf(" %.6f", result[j]);
    }
    printf("\n");
  }
  free(curr);
  free(result);
}

int main(int argc, char* argv[])
{
  FILE* fp = fopen(argv[1], "r");
  myfunction(fp);
  return 0;
}
