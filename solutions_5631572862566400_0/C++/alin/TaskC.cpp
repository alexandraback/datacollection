#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int BFF[1000];
int f[1000];

int Solver(int N){
  int i,j,k,len;
  int MaxLoop, CurLoop, MaxPair1, MaxPair2, CurPair, MaxI, MaxBFFI;

  for( i = 0; i < N; i ++ ){
    BFF[i] --;
  }

  // Search for max loop
  MaxLoop = 0;
  for( i = 0; i < N; i ++ ){
    f[i] = 0;
  }
  for( i = 0; i < N; i ++ ){
    if( f[i] == 0 ){
      j = i;
      len = 1;
      while( f[j] == 0 ){
        f[j] = 1000 * i + len;
        len ++;
        j = BFF[j]; 
      }
      if( (f[j]) / 1000 == i ){
        CurLoop = len - f[j] % 1000;
        if( CurLoop > MaxLoop ){
          MaxLoop = CurLoop;
        }
      }
    }
  }
  printf("MaxLoop = %d\n", MaxLoop);

  // Search for pairs with tails
  MaxPair1 = 0;
  MaxPair2 = 0;
  for( i = 0; i < N; i ++ ){
    if( (i < BFF[i]) && (i == BFF[BFF[i]]) ){
      for( j = 0; j < N; j ++ ){
        f[j] = 0;
      }
      MaxI = 0;
      MaxBFFI = 0;
      for( j = 0; j < N; j ++ ){
        if( (j == i) || ( j == BFF[i] ) ){
          continue;
        }
        k = j;
        len = 0;
        f[i] = 1001;
        f[BFF[i]] = 1001;
        while( (f[k] != j+1)&&(f[k] != 1001) ){
          f[k] = j+1;
          k = BFF[k];
          len ++;
        }
        if( k == i ){
          if( len > MaxI ){
            MaxI = len;
          }
        }
        if( k == BFF[i] ){
          if( len > MaxBFFI ){
            MaxBFFI = len;
          }
        }
      }
      if( MaxI + MaxBFFI + 2 > MaxPair1 ){
        MaxPair2 = MaxPair1;
        MaxPair1 = MaxI + MaxBFFI + 2;
      }
      else{
        if( MaxI + MaxBFFI + 2 > MaxPair2 ){
          MaxPair2 = MaxI + MaxBFFI + 2;
        }
      }
    }
  }
  printf("MaxPair = %d\n", MaxPair1 + MaxPair2);
  if( MaxPair1 + MaxPair2 < MaxLoop )
    return MaxLoop;
  else
    return MaxPair1 + MaxPair2;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, N;
  int t, i, res;

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
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
    for( i = 0; i < N - 1; i ++ ){
      fscanf(filein, "%d ", BFF + i);
      printf("%d ", BFF[i]);
    }
    fscanf(filein, "%d\n", BFF + i);
    printf("%d\n", BFF[i]);

    // Solve & Output
    res = Solver(N);
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
