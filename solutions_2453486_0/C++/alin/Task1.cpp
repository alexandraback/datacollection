#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

char A[1000][4][4];
char Answers[4][30] = {"X won", "O won", "Draw", "Game has not completed"};

int Solver(int t){
  int i, j, ti=0, tj=0, tflag = 0;
  for( i = 0; i < 4; i ++ )
    for( j = 0; j < 4; j ++ )
      if( A[t][i][j] == 'T' ){
        tflag = 1;
        ti = i;
        tj = j;
      }

  // X won
  if( tflag )
    A[t][ti][tj] = 'X';
  for( i = 0; i < 4; i ++ ){
    if( (A[t][i][0] == 'X') && (A[t][i][1] == 'X') && (A[t][i][2] == 'X') && (A[t][i][3] == 'X') )
      return 0;
    if( (A[t][0][i] == 'X') && (A[t][1][i] == 'X') && (A[t][2][i] == 'X') && (A[t][3][i] == 'X') )
      return 0;
  }
  if( (A[t][0][0] == 'X') && (A[t][1][1] == 'X') && (A[t][2][2] == 'X') && (A[t][3][3] == 'X') )
    return 0;
  if( (A[t][0][3] == 'X') && (A[t][1][2] == 'X') && (A[t][2][1] == 'X') && (A[t][3][0] == 'X') )
    return 0;
  if( tflag )
    A[t][ti][tj] = 'T';
  // O won
  if( tflag )
    A[t][ti][tj] = 'O';
  for( i = 0; i < 4; i ++ ){
    if( (A[t][i][0] == 'O') && (A[t][i][1] == 'O') && (A[t][i][2] == 'O') && (A[t][i][3] == 'O') )
      return 1;
    if( (A[t][0][i] == 'O') && (A[t][1][i] == 'O') && (A[t][2][i] == 'O') && (A[t][3][i] == 'O') )
      return 1;
  }
  if( (A[t][0][0] == 'O') && (A[t][1][1] == 'O') && (A[t][2][2] == 'O') && (A[t][3][3] == 'O') )
    return 1;
  if( (A[t][0][3] == 'O') && (A[t][1][2] == 'O') && (A[t][2][1] == 'O') && (A[t][3][0] == 'O') )
    return 1;
  if( tflag )
    A[t][ti][tj] = 'T';
  // Not completed
  for( i = 0; i < 4; i ++)
    for( j = 0; j < 4; j ++ )
      if( A[t][i][j] == '.' )
        return 3;

  return 2;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int res, t, i;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
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
    for( i = 0; i < 4; i ++){
      fscanf(filein, "%c%c%c%c\n", &(A[t][i][0]),&(A[t][i][1]),&(A[t][i][2]),&(A[t][i][3]));
      printf("%c%c%c%c\n", (A[t][i][0]),(A[t][i][1]),(A[t][i][2]),(A[t][i][3]));
    }
    fscanf(filein, "\n");

    // Solve & Output
    res = Solver(t);
    fprintf(fileout, "Case #%d: %s\n", t + 1, Answers[res]);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
