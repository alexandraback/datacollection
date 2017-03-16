#include <cstdio>
#include <algorithm>
using namespace std;

int counter = 0;
char a[50][50];
char b[50][50];

int r, c, m;
void printBoard() {
   for(int i = 0; i < r; ++i)
   {
      for(int j = 0; j < c; ++j)
      {
         printf("%c", b[i][j]);
      }
      printf("\n");
   }
}

void printBoardA() {
   for(int i = 0; i < r; ++i)
   {
      for(int j = 0; j < c; ++j)
      {
         printf("%c", a[i][j]);
      }
      printf("\n");
   }
}

void click(int y, int x) {
//   printf("clicking %d %d", x, y);
   b[y][x] = '.';
   int numMines = 0;
   if(y > 0) {
      if(b[y-1][x] == '*') {
         numMines++;
      }
      if(x > 0) {
         if(b[y-1][x-1] == '*') {
            numMines++;
         }
      }
      if(x < (c-1)) {
         if(b[y-1][x+1] == '*') {
            numMines++;
         }
      }
   }
   if(x > 0) {
      if(b[y][x-1] == '*') {
         numMines++;
      }
   }
   if(x < (c-1)) {
      if(b[y][x+1] == '*') {
         numMines++;
      }
   }
   
   
   if(y < (r-1)) {
      if(b[y+1][x] == '*') {
         numMines++;
      }
      if(x > 0) {
         if(b[y+1][x-1] == '*') {
            numMines++;
         }
      }
      if(x < (c-1)) {
         if(b[y+1][x+1] == '*') {
            numMines++;
         }
      }
   }
   
   if(numMines == 0) {
      if(y > 0) {
         if(b[y-1][x] == ',') {
            click(y-1, x);
         }
         if(x > 0) {
            if(b[y-1][x-1] == ',') {
               click(y-1, x-1);
            }
         }
         if(x < (c-1)) {
            if(b[y-1][x+1] == ',') {
               click(y-1, x+1);
            }
         }
      }
      if(x > 0) {
         if(b[y][x-1] == ',') {
            click(y, x-1);
         }
      }
      if(x < (c-1)) {
         if(b[y][x+1] == ',') {
            click(y, x+1);
         }
      }
   
   
      if(y < (r-1)) {
         if(b[y+1][x] == ',') {
            click(y+1, x);
         }
         if(x > 0) {
            if(b[y+1][x-1] == ',') {
               click(y+1, x-1);
            }
         }
         if(x < (c-1)) {
            if(b[y+1][x+1] == ',') {
               click(y+1, x+1);
            }
         }
      }
   }
   
   
   
}
bool testCase(int y,int x) {
   for(int i = 0; i < r; ++i)
   {
      for(int j = 0; j < c; ++j)
      {
         b[i][j] = a[i][j];
      }
   }
//    printBoard();
//   printf("\n\n");
    click(y,x);
  // printBoard();
    for(int i = 0; i < r; ++i)
    {
       for(int j = 0; j < c; ++j)
       {
          if(b[i][j] == ',') {
             return false;
          }
       }
    }
   return true;
}

void runCase() {
    printf("Case #%d:\n", ++counter);
    
     scanf("%d %d %d", &r, &c, &m);

     int minesPlaced = 0;
     int perm[r*c];
    for (int i=0; i<r*c; ++i) {
           if(minesPlaced < m) {
              perm[i] = '*';
              minesPlaced++;
           } else {
              perm[i] = ',';
           }
    }
  //  int permutations = 0;
    do {  
       int x = 0, y = 0;  
       for(int i = 0; i < r*c; ++i) {
          a[y][x] = perm[i];
          if(x < c - 1) {
             x++;
          } else {
             x = 0;
             y++;
          }
          
       }
       for(int i = 0; i < r; ++i)
       {
          for(int j = 0; j < c; ++j)
          {
             if(a[i][j] == ',') {
                if(testCase(i,j)) {
                   b[i][j] = 'c';
                     printBoard();
                   return;
                }
             }
          }
      } 
    } while ( std::next_permutation(perm,perm+(r*c)) ); 
          
    
    printf("Impossible\n");
    return;
}

void preprocess() {
   
}
int main() {
   preprocess();
   
    int t; scanf("%d", &t);
    while(t--) {
      runCase();
    }
    return 0;
}

//  n, m, 2 numbers per line
//    int n, m; scanf("%d %d", &n, &m);


/* GRID - N x M  
int n, m; scanf("%d %d", &n, &m);
 for (int i=0; i<n; ++i) {
     for (int j=0; j<m; ++j) {
         scanf("%d", &t[i][j]);
     }
 }
 */