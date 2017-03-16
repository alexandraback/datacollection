#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long LONG_T;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

#define MAXA (100000)
double PROB[MAXA];

char buf[1000000];
#ifdef LOCAL
#define INPUT   fgets(buf,sizeof(buf),FD)
#define USEFILEIO
#else
#define INPUT gets(buf)
#endif

int main (int argc, char *argv[]) {
  FILE *FD;
  char *saveptr;
  char *tok;
  int i;
  int T; 
  
//  gen_translate();
////  translate(OUT);
//  return;
  
  
#ifdef USEFILEIO
  FD = fopen(argv[1], "r");
  
  if (!FD) {
    printf("error cannot open %s\n",argv[1]);
    return -1;
  }
#endif

  
//  fgets(buf,sizeof(buf),FD);
  INPUT;
  int num_case;
  T = atoi(buf);
  for (num_case = 1;num_case <= T;num_case++) {
    int A, B;
    double prob;
    
    INPUT;
    tok = strtok_r(buf," ", &saveptr);
    A = atoi(tok);
    tok = strtok_r(NULL," ",&saveptr);
    B = atoi(tok);
    
    INPUT;
    tok = strtok_r(buf," ", &saveptr);
    double accum = 1;
    for (i=0;i<A;i++) {
      prob = atof(tok);
      accum *= prob;
      PROB[i] = accum;
      tok = strtok_r(NULL," ",&saveptr);
    }
    double e1 = (accum * (B-A+1)) + ((1-accum)*(B-A+1+B+1));
    double e2 = B+2;
    double min;
    min = MIN(e1,e2);
    int i=0;
    accum = 1;
    for (i=0;i<A;i++) {
      accum = PROB[A-1-i];
      int partial = (i+B-A+i+1);
      e1 = (accum * partial) + ((1-accum)*(partial+B+1));
//      printf("e1 partial %d accum %f = %f\n",partial,accum,e1);
      min = MIN(min,e1);
//      printf("min = %f\n",min);
    }
    
//    printf("accum = %f\n",accum);
//    printf("e1 = %f\n",e1);
//    printf("e2 = %f\n",e2);
//    printf("min = %f\n",min);
    if (e2 < e1) {
      e1 = e2;
    }
    printf("Case #%d: %f\n",num_case,min);
  }
  return 0;
}
