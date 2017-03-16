/*
ID: Plagapong
LANG: C++
TASK: C
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999
#define IMPOSSIBLE "Impossible\n"

using namespace std;
int r, c, m, l;
bool inverse;
char a[51][51];

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  for (int i = 0; i < 51; i++) 
    for (int j = 0; j < 51; j++)
      a[i][j] = '*';
}

void printMap() {
  if (inverse) {
    for (int j = 0; j < c; j++) {
      for (int i = 0; i < r; i++) {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  } else {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
}

#define YAY {a[0][0] = 'c'; printMap(); return;}
#define NAH {printf(IMPOSSIBLE); return;}

void process() {
  // Code here!
  cin >> r >> c >> m;
  l = r * c - m;
  // Make c < r
  if (r < c) {
    int u = r; r = c; c = u;
    inverse = true;
  } else inverse = false;
  // Deal with easy cases first
  if (l == 0) NAH;
  if (l == 1) YAY;
  if (c == 1) {
    for (int i = 0; i < l; i++)
      a[i][0] = '.';
    YAY;
  }
  if (l == 2 || l == 3) NAH;
  // For c = 2, 0 in left column implies 0 in right column
  if (c == 2) {
    if (l % 2 == 0) {
      for (int i = 0; i < l/2; i++)
        a[i][0] = a[i][1] = '.';
      YAY;
    } else NAH;
  }
  // For c >= 3, easy cases
  if (l == 5 || l == 7) NAH;
  if (l == 4) {
    a[0][0] = a[0][1] = a[1][0] = a[1][1] = '.';
    YAY;
  }
  if (l == 6) {
    a[0][0] = a[0][1] = a[0][2] = a[1][0] = a[1][1] = a[1][2] = '.';
    YAY;
  }
  if (l == 8) {
    a[0][0] = a[0][1] = a[0][2] = a[1][0] = a[1][1] = a[1][2] 
      = a[2][0] = a[2][1] = '.';
    YAY;
  }
  if (l == 9) {
    a[0][0] = a[0][1] = a[0][2] = a[1][0] = a[1][1] = a[1][2] 
      = a[2][0] = a[2][1] = a[2][2] = '.';
    YAY;
  }
  // For c >= 3, harder cases
  if (l <= 2 * c + 2) {
    for (int j = 0; j < (l-2)/2; j++)
      a[0][j] = a[1][j] = '.';
    a[2][0] = a[2][1] = '.';
    if (l % 2 == 1) a[2][2] = '.';
    YAY;
  } else {
    for (int u = 0; u < l; u++)
      a[u/c][u%c] = '.';
    // Don't have a single hole
    if (l % c == 1) {
      a[l/c][1] = '.';
      a[l/c-1][c-1] = '*';
    }
    YAY;
  }
}

int main() {
  preprocess();
  int times;
  cin >> times;
  for (int i = 1; i <= times; i++) {
    cout << "Case #" << i << ":" << endl;
    clearVars();
    process();
  }
  return 0;
}
