#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Google Code Jam
Qualification 2014
Problem C. Minesweeper Master
*/

#define TRUE 1
#define FALSE 0

#define HAS_MINE '*'
#define NO_MINE '.'
#define CLICKED 'c'

struct board {
  int nrows;
  int ncols;
  char **tiles;
};

void Init_Board(struct board *b, int nrows, int ncols)
{
  int i, j;
  b->nrows = nrows;
  b->ncols = ncols;
  b->tiles = (char**)(malloc(nrows*sizeof(char*)));
  for(i=0;i<nrows;i++){
    b->tiles[i] = (char*)(malloc(ncols*sizeof(char)));
    for (j=0;j<ncols;j++) {
      b->tiles[i][j] = HAS_MINE;
    }
  }
}

void Print_Board(struct board *b)
{
  int i,j;

  for(i=0;i<b->nrows;i++){
    for(j=0;j<b->ncols;j++){
      fprintf(stdout, "%c", b->tiles[i][j]);
    }
    fprintf(stdout, "\n");
  }
}

void Unmine_Row(struct board *b, int r, int len)
{
  int i;
  for(i=0;i<len;i++){
    b->tiles[r][i] = NO_MINE;
  }
}

void Unmine_Col(struct board *b, int c, int len)
{
  int i;
  for(i=0;i<len;i++){
    b->tiles[i][c] = NO_MINE;
  }
}

void Decon_Board(struct board *b)
{
  int i;
  for(i=0;i<b->nrows;i++){
    free(b->tiles[i]);
  }
  free(b->tiles);
}

int Bigger(int a, int b)
{
  if (a>b)
    return a;
  return b;
}

int Smaller(int a, int b)
{
  if(a<b)
    return a;
  return b;
}

int Is_Valid(struct board b, int test, int fac, int rem)
{
  int min;
  
  //1xN boards can have test's that are 1
  if (Smaller(b.nrows, b.ncols) == 1) {
    min = 1;
  }
  //If the remainder is 1 we need an extra layer to pull from
  else if (rem == 1) {
    min = 3;
  }
  else {
    min = 2;
  }

  if (test >= min && fac >= min) {
    if ( (Bigger(b.nrows, b.ncols) >= Bigger(test, fac)) 
	 && (Smaller(b.nrows, b.ncols) >= Smaller(test, fac)) ) {
      //if (rem <= Smaller(test, fac)) {
	return TRUE;
	//}
    }
  }

  if (test==1 && fac==1) {
    return TRUE;
  }

  return FALSE;
}

void Populate_Board(struct board *b, int s1, int s2, int rem)
{
  int i;
  int n_rows, n_cols;

  if (b->nrows > b->ncols) {
    n_rows = Bigger(s1, s2);
    n_cols = Smaller(s1, s2);
  }
  else {
    n_cols = Bigger(s1, s2);
    n_rows = Smaller(s1, s2);
  }

  for (i=0;i<n_rows;i++) {
    Unmine_Row(b, i, n_cols);
  }

  if (rem == 1) {
    b->tiles[n_rows-1][n_cols-1] = HAS_MINE;
    rem++;
  }

  if (rem) {
    if (n_rows < b->nrows && rem <= n_cols) {
      Unmine_Row(b, n_rows, rem);
    }
    else {
      Unmine_Col(b, n_cols, rem);
    }
  }
  
  b->tiles[0][0] = CLICKED;
}

void Run(int c)
{
  int nrows, ncols;
  int nmines;
  int nfree;
  int test, factor, remainder;
  int has_solution = 0;
  struct board b;

  scanf("%d %d %d", &nrows, &ncols, &nmines);

  nfree = (nrows*ncols) - nmines;

  Init_Board(&b, nrows, ncols);

  test = 1;
  while( (test == 1 || test<=(nfree/2)) && !has_solution) {
    factor = nfree / test;
    //fprintf(stderr, "Free: %d\n Test: %d\nFactor: %d\n", nfree, test, factor);
    remainder = nfree % test;
    
    if (Is_Valid(b, test, factor, remainder)) {
      Populate_Board(&b, test, factor, remainder);
      has_solution = 1;
    }
    test++;
  }

  fprintf(stdout, "Case #%d:\n", c);

  if (has_solution) {
    //fprintf(stderr, "cells: %d, free: %d\n", nrows*ncols, nfree);
    //fprintf(stderr, "%d %d %d\n", test, factor, remainder);
    Print_Board(&b);
  }
  else {
    //fprintf(stdout, "%d %d %d %d \n", nrows, ncols, nmines, nfree);
    fprintf(stdout, "Impossible\n");
  }

  Decon_Board(&b);

}


int main() {
  int T;
  int i;
  scanf("%d", &T);

  for(i=1;i<=T;i++){
    Run(i);
  }
  return 0;
}
