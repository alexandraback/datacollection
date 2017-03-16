#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int P1[2000], P2[2000], *p, *pnext, *ptmp;
int BestSplit[1001], BestSplitCost[1001];

int intcmp( const void *arg1, const void *arg2 ){
  if( *(int*)arg1 < *(int*)arg2 )
    return 1;
  if( *(int*)arg1 > *(int*)arg2 )
    return -1;
  return 0;
}


int Solver(int D){
  int res, size, time, mintime, t, i, j;
  int h1,h2;
  bool flag;
  int waits, waittime;
  p = P1;
  pnext = P2;
  qsort(P1, D, sizeof(int), intcmp);
  if( p[0] == 1 ){
    return 1;
  }

  flag = true;
  for( time = p[0]; (time > 1) && flag;  ){
    time --;
//    printf("time = %d -------------\n", time);
    flag = false;
    for( waittime = 1; (waittime < time) && (!flag); waittime ++ ){
//      printf("  waittime = %d\n", waittime);
      waits = 0;
      for( i = 0; i < D; i ++ ){
        waits += (p[i] - 1) / (time - waittime);
//        printf("    p[%i] waittime = %d, waits = %d\n", p[i], (p[i] - 1) / (time - waittime), waits);
        if( waits > waittime ){
          break;
        }
      }
      if( waits <= waittime ){
        flag = true;
      }
    }
  }
  printf("res = %d\n", time + 1);
  return time + 1;

/*  mintime = p[0];
  size = D;
  for( t = 1; (p[0] > 0) && (t < mintime); t ++ ){
    h1 = p[0] / 2 + p[0] % 2;
    h2 = p[0] / 2;
    for( i = 1, j = 0; (p[i] > h1) && (i < size); i ++ ){
      pnext[j] = p[i];
      j++;
    }
    pnext[j] = h1;
    j++;
    for( ; (p[i] > h2) && (i < size); i ++ ){
      pnext[j] = p[i];
      j++;
    }
    pnext[j] = h2;
    j++;
    for( ; i < size; i ++ ){
      pnext[j] = p[i];
      j++;
    }
    size++;
    ptmp = p;
    p = pnext;
    pnext = ptmp;
    if( p[0] + t < mintime ){
      mintime = p[0] + t;
    }
  }
*/
  return mintime;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, D;
  int t, i, j, res;

  if( argc < 3 ){
    printf("Usage is: TaskB filein fileout\n");
    return 0;
  }

  BestSplit[1] = 1;
  BestSplitCost[1] = 1;
  for( i = 2; i < 1001; i ++){
    BestSplit[i] = i - 1;
    BestSplitCost[1] = 1;
    for( j = 1; j < (i + 1) / 2; j ++ ){
    }
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
    fscanf(filein, "%d\n", &D);
    printf("%d\n", D);
    for( i = 0; i < D; i ++ ){
      fscanf(filein, "%d ", P1 + i);
      printf("%d ", P1[i]);
    }
    fscanf(filein, "\n");
    printf("\n");

    // Solve & Output
    res = Solver(D);
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
