#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int A[4][4], AA, B[4][4], BB;
char Answers[2][30] = {"Bad magician!", "Volunteer cheated!"};

void Solver(int R, int C, int M, FILE* fileout){
  int i, j, R1, C1, Free = R * C - M, r, r1, r2;

  if( Free == 1 ){
    for( i = 0; i < R; i ++ ){
      for( j = 0; j < C; j ++ ){
        if ( ( i == 0 )&&( j == 0 ) ){
          fprintf(fileout,"%c",'c');
        }
        else{
          fprintf(fileout,"%c",'*');
        }
      }
      fprintf(fileout,"\n");
    }
    return;
  }
  if( R == 1 ){
    fprintf(fileout,"%c",'c');
    for( j = 1; j < C - M; j ++ ){
      fprintf(fileout,"%c",'.');
    }
    for( j = C - M; j < C; j ++ ){
      fprintf(fileout,"%c",'*');
    }
    fprintf(fileout,"\n");
    return;
  }
  if( C == 1 ){
    fprintf(fileout,"%c\n",'c');
    for( i = 1; i < R - M; i ++ ){
      fprintf(fileout,"%c\n",'.');
    }
    for( i = R - M; i < R; i ++ ){
      fprintf(fileout,"%c\n",'*');
    }
    return;
  }
  for( R1 = 2; R1 <= R; R1 ++ ){
    for( C1 = 2; C1 <= C; C1 ++ ){
      if( ( R1 > 2 )&&( C1 > 2 ) ){
          r = R1 + C1 - 4 - 1;
      }
      else{
        r = 0;
      }
      if( ( Free <= R1 * C1 )&&( Free >= R1 * C1 - r ) ){
        r = R1 * C1 - Free;
        if( r > C1 - 2 ){
          r1 = C1 - 2;
          r2 = r - r1;
        }
        else{
          r1 = r;
          r2 = 0;
        }
//        fprintf(fileout,"Possible %d %d %d %d\n", R1, C1, r1, r2);
        for( i = 0; i < R; i ++ ){
          for( j = 0; j < C; j ++ ){
            if( ( i == 0 )&&( j == 0 ) ){
              fprintf(fileout,"%c",'c');
            }
            else if( i >= R1 ){
              fprintf(fileout,"%c",'*');
            }
            else if( ( i == R1 - 1 )&&( j >= C1 - r1 ) ){
              fprintf(fileout,"%c",'*');
            }
            else if( ( i < R1 - 1 )&&( i >= R1 - 1 - r2 )&&( j >= C1 - 1 ) ){
              fprintf(fileout,"%c",'*');
            }
            else if( j >= C1 ){
              fprintf(fileout,"%c",'*');
            }
            else{
              fprintf(fileout,"%c",'.');
            }
          }
          fprintf(fileout,"\n");
        }
        return;
      }
    }
  }

  fprintf(fileout,"Impossible\n");
  return;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, R, C, M;
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
    fscanf(filein, "%d %d %d\n", &R, &C, &M);
    printf("%d %d %d\n", R, C, M);

    // Solve & Output
    fprintf(fileout, "Case #%d:\n", t + 1);
    Solver(R, C, M, fileout);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
