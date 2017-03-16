#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

// global
int T;
int r,c,m,n,f;
char table[50][50];
bool transpose;
bool impos;

void special() {
  table[0][0] = 'c';
}

void clear() {
  for (int i = 0;i < r;i++)
    for (int j = 0;j < c;j++)
      table[i][j] = '*';
}

void even() {
  for (int i = 0;i < f / 2;i++) {
    table[r-2][i] = '.';
    table[r-1][i] = '.';
  }
  table[r-1][0] = 'c';
}

void odd() {
  table[r-3][0] = table[r-3][1] = table[r-3][2] = '.';
  for (int i = 0;i < (f-3)/2;i++) {
    table[r-2][i] = '.';
    table[r-1][i] = '.';
  }
  table[r-1][0] = 'c';
}

void normal() {
  for (int i = m;i < n;i++) {
    table[i/c][i % c] = '.';
  }
  if (m % c == c-1) {
    int lastRow =m/c;
    table[lastRow][c-2] = '.';
    table[lastRow+1][0] = '*';
  }
  table[r-1][0] = 'c';
}

void printSol() {
  if (transpose) std::swap(r,c);
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      if (transpose)
        printf("%c",table[j][i]);
      else
        printf("%c",table[i][j]);
    }
    printf("\n");
  }
}


int main() {
  cin >> T;
  int run = 0;
  while (run++ < T) {
    fprintf(stderr,"doing case %d\n",run);
    cin >> r >> c >> m;
    n = r * c;
    f = n - m; //  number of  non-bomb
    if (r < c) {
      transpose = true;
      std::swap(r,c);
    } else transpose = false;
    impos = false;
    clear();

    //solve
    printf("Case #%d:\n",run);
    if (f == 1) {
      special();
      printSol();
    } else if (c == 1) { 
      for (int i = m;i < n;i++) {
        table[i][0] = '.';
      }
      table[r-1][0] = 'c';
      printSol();
    } else if (c == 2) {
      if (m % 2 == 1 || f == 2) {
        printf("Impossible\n");
      } else {
        normal();
        printSol();
      }
    } else if (f == 2 || f == 3 || f == 5 || f == 7) {
      printf("Impossible\n");
    } else if (m <= n - 2*c && m != n - 2*c - 1) {
      normal();
      printSol();
    } else if (f % 2 == 0) {
      even();
      printSol();
    } else {
      odd();
      printSol();
    }
  }
}
