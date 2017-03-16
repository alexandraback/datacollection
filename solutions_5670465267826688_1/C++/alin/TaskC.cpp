#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

char S[10003];
char t[8][8] = {{0,1,2,3,4,5,6,7}, //1,i,j,k,-1,-i,-j,-k
                {1,4,3,6,5,0,7,2},
                {2,7,4,1,6,3,0,5},
                {3,2,5,4,7,6,1,0},
                {4,5,6,7,0,1,2,3},
                {5,0,7,2,1,4,3,6},
                {6,3,0,5,2,7,4,1},
                {7,6,1,0,3,2,5,4}};

bool Solver(int L, long long X){
  int i, j, cur, sres;
  int start, end;

  for( i = 0; i < L; i ++ ){
    S[i] = S[i] - 'i' + 1;
//    printf("%d", S[i]);
  }
//  printf("\n");

  cur = 0;
  for( i = 0; i < L; i ++ ){
    cur = t[cur][S[i]];
  }
  sres = cur;
  printf("sres=%d\n", sres);

  cur = 0;
  for( i = 0; i < X % 4; i ++ ){
    cur = t[cur][sres];
  }
  if( cur != 4 ){
    printf("NO 1\n");
    return false;
  }

  cur = 0;
  start = 0;
  for( i = 0; i < 4; i ++ ){
    for( j = 0; j < L; j ++ ){
      cur = t[cur][S[j]];
      if( cur == 1 ){
        start = i * L + j + 1;
        break;
      }
    }
    if( start > 0 ){
      break;
    }
    if( cur == 0 ){
      printf("NO 2\n");
      return false;
    }
  }
  if( start == 0 ){
    printf("NO 3\n");
    return false;
  }

  cur = 0;
  end = 0;
  for( i = 0; i < 4; i ++ ){
    for( j = L - 1; j >= 0; j -- ){
      cur = t[S[j]][cur];
      if( cur == 3 ){
        end = i * L + (L - 1 - j) + 1;
        break;
      }
    }
    if( end > 0 ){
      break;
    }
    if( cur == 0 ){
      printf("NO 4\n");
      return false;
    }
  }
  if( end == 0 ){
    printf("NO 5\n");
    return false;
  }

  if( (long long)start + (long long) end > (long long) L * X ){
    printf("NO 6\n");
    return false;
  }

  return true;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, L;
  long long X;
  int t;

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
    fscanf(filein, "%d %lld\n", &L, &X);
    printf("%d %lld\n", L, X);
    fscanf(filein, "%s\n", S);
//    printf("%s\n", S);

    // Solve & Output
    if( Solver(L, X) ){
      fprintf(fileout, "Case #%d: YES\n", t + 1);
    }
    else{
      fprintf(fileout, "Case #%d: NO\n", t + 1);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
