#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, N, J, P, S, K;
  int JP[100], JS[100], PS[100], cJ, cP, cS, JJ[1000], PP[1000], SS[1000];
  int t, i, j, k, res;

  if( argc < 3 ){
    printf("Usage is: TaskC filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%d %d %d %d\n", &J, &P, &S, &K);
    printf("%d %d %d %d\n", J, P, S, K);

    // Solve & Output
    res = 0;
    cJ = cP = cS = 0;
    for( i = 0; i < 100; i ++ ){
      JP[i] = 0;
      JS[i] = 0;
      PS[i] = 0;
    }
    for( i = 0; i < 10; i ++ ){
      for( j = 0; j < 11; j ++ ){
        for( k = 0; k < 13; k ++ ){
          if( (cJ < J) && ( cP < P ) && (cS < S) ){
            printf("cJ=%d,cP=%d,cS=%d,JP=%d,JS=%d,PS=%d",cJ,cP,cS,JP[cJ*10+cP],JS[cJ*10+cS],PS[cP*10+cS]);
            if( (JP[cJ*10+cP] < K) && (JS[cJ*10+cS] < K) && (PS[cP*10+cS] < K ) ){
              JJ[res] = cJ;
              PP[res] = cP;
              SS[res] = cS;
              res ++;
              JP[cJ*10+cP] ++;
              JS[cJ*10+cS] ++;
              PS[cP*10+cS] ++;
              printf(" +\n");
            }else{
              printf("\n");
            }
          }
          cJ = (cJ + 17) % 10;
          cP = (cP + 19) % 11;
          cS = (cS + 23) % 13;
        }
      }
    }

    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
    for( i = 0; i < res; i ++ ){
      fprintf(fileout, "%d %d %d\n", JJ[i] + 1, PP[i] + 1, SS[i] + 1);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
