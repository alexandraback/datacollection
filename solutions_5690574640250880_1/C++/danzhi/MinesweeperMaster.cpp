#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <functional>
#include <hash_map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <math.h>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\MinesweeperMaster";
void reopen(char* a) {
	char input[256], output[256];
	sprintf(input, "%s\\%s", rootdir, a);
	sprintf(output, "%s\\%s", rootdir, a);
	char *p = strstr(output, ".in");
	if (p) sprintf(p, ".out"); 
	else sprintf(&p[strlen(output)], ".out");
	debug(input);
	debug(output);
	freopen(input,"r",stdin);
	if (!test) freopen(output,"w",stdout);
}

const int md = 1000002013;

int cost(int n, int len) {
  int a = n + (n - len + 1);
  int b = len;
  if (a % 2 == 0) a /= 2;
  else b /= 2;
  return (long long)a * b % md;
}

const int MAX = 50;
int T = 0;
int R, C, M;
char a[MAX][MAX];
bool inverted = false;

bool pushed[MAX][MAX];  // whether pushed --- used in verification
queue<int> qrow;
queue<int> qcol;

void showin() {
  if (!test) return;
  printf("%d %d %d\n", R, C, M);
}

void initialize() {
  for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++) a[i][j] = ' ';
  if (R < C) {
    int t = R;
    R = C;
    C = t;
    inverted = true;
  } else {
    inverted = false;
  }
}

void invertBack() {
  if (inverted) {
    int tmp = R;
    R = C;
    C = tmp;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (i >= j) continue;
        char c = a[i][j];
        a[i][j] = a[j][i];
        a[j][i] = c;
      }
    }
    inverted = false;
  }
}

int getDegree(int r, int c) {
  int degree = 0;
  if (r >= 1) {
    if (c >= 1 && a[r-1][c-1] == '*') degree++;
    if (a[r-1][c] == '*') degree++;
    if (c+1 < C&& a[r-1][c+1] == '*') degree++;
  }
  if (c >= 1 && a[r][c-1] == '*') degree++;
  if (c+1 < C&& a[r][c+1] == '*') degree++;
  if (r+1 < R) {
    if (c >= 1 && a[r+1][c-1] == '*') degree++;
    if (a[r+1][c] == '*') degree++;
    if (c+1 < C&& a[r+1][c+1] == '*') degree++;
  }
  return degree;
}

void reveal(int r, int c) {
  if (!pushed[r][c]) {
    qrow.push(r);
    qcol.push(c);
    pushed[r][c] = true;
  }
}

void revealNeighbors(int r, int c) {
  if (r >= 1) {
    if (c >= 1 && a[r-1][c-1] == '.') reveal(r-1, c-1);
    if (a[r-1][c] == '.') reveal(r-1, c);
    if (c+1 < C&& a[r-1][c+1] == '.') reveal(r-1, c+1);
  }
  if (c >= 1 && a[r][c-1] == '.') reveal(r, c-1);
  if (c+1 < C&& a[r][c+1] == '.') reveal(r, c+1);
  if (r+1 < R) {
    if (c >= 1 && a[r+1][c-1] == '.') reveal(r+1, c-1);
    if (a[r+1][c] == '.') reveal(r+1, c);
    if (c+1 < C&& a[r+1][c+1] == '.') reveal(r+1, c+1);
  }
}

void verify() {
  for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++) pushed[i][j] = false;
  int count = 0;
  reveal(0,0);
  // if the revealed cell contains a 0, then all of the neighbors 
  // of the revealed cell are automatically revealed as well, recursively
  while (qrow.size() > 0) {
    int r = qrow.front();
    int c = qcol.front();
    count++;
    qrow.pop();
    qcol.pop();
    
    int degree = getDegree(r, c);
    // printf("(%d,%d) degree:%d count:%3d \n", r ,c, degree, count);
    if (degree == 0) {
      revealNeighbors(r, c);
    }
  }
  if (count != R*C-M) {
    breakpoint++;
  }
  assert(count == R*C - M);
}

void solve(int t) {
  printf("Case #%d:\n", t);
  initialize();
  assert(R >= C);

  assert(M < R * C && M >= 0);
  int E = R * C - M;  // number of empty/non-mine cells
  if (E == 1) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        a[i][j]='*';
      }
    }
    a[0][0] = 'c';
  } else if (C == 1) {
    // c
    // .
    // .
    // .
    // *
    // *
    for (int i = 0; i < R; i++) {
      if (i >= R-M) a[i][0]='*';
      else a[i][0]='.';
    }
    a[0][0] = 'c';
  } else if (C == 2) {
    assert(R >= 2);  // since R >= C
    if (E % 2 == 1 || E == 2) {
      printf("Impossible\n");
      return;
    } else {
      // c.
      // ..
      // ..
      // **
      // **
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < 2; j++) {
          if (i < E / 2) a[i][j] = '.';
          else a[i][j] = '*';
        }
      }
      a[0][0] = 'c';
    }
  } else {
    assert(R >= 3 && C >= 3);
    assert(E > 1);
    if (E == 2 || E == 3 || E == 5 || E == 7) {
      printf("Impossible\n");
      return;
    } else {
      if (E >= 2* C) {
        // c......
        // .......
        // ...****
        // *******
        int rows = E / C;  // number of rows that are clear of mines
        assert(rows >= 2 && rows <= R);
        // partial rows
        int extra = E % C;
        // If extra is 1, we have to adjust 
        bool end1 = false;
        bool end2 = false;
        if (extra == 1) {
          end1 = true; // appear at the end of previous row
          if (rows <= 2) {
            assert(C-extra >= 3);
            end2 = true;
          }
        }
        for (int i = 0; i < R; i++) {
          if (i < rows) {
            for (int j = 0; j < C; j++) {
              if (i == rows - 2 && end2 && j == C-1) a[i][j] = '*';
              else if (i == rows - 1 && end1 && j == C-1) a[i][j] = '*';
              else a[i][j] = '.';
            }
          } else if (i == rows && extra > 0) {
            for (int j = 0; j < C; j++) {
              if (j < extra) a[i][j] = '.';
              else if (j == extra && end1) a[i][j] = '.';
              else if (j == extra+1 && end2) a[i][j] = '.';
              else a[i][j] = '*';
            }
          } else {
            for (int j = 0; j < C; j++) {
              a[i][j] = '*';
            }
          }
        }
        a[0][0] = 'c';
      } else {
        assert(E <= C * 2);
        if (E % 2 == 0) {
          // c..****
          // ...****
          // *******
          for (int i = 0; i < R; i++) {
            if (i < 2) {
              for (int j = 0; j < C; j++) {
                if (j < E/2) a[i][j] = '.';
                else a[i][j] = '*';
              }
            } else {
              for (int j = 0; j < C; j++) {
                a[i][j] = '*';
              }
            }
          }
          a[0][0] = 'c';
        } else {
          // partition E into 3 * A + 2 * B (A >= 3 and B >= 0)
          int A = 0; 
          int B = 0;
          assert(E >= 9 && E % 2 == 1);
          if (E % 3 == 0) {
            A = E / 3;
            B = 0;
          } else if (E % 3 == 1) {
            // like 13 , 19 etc
            A = (E - 4) / 3;
            B = 2;
          } else {
            assert(E % 3 == 2);
            A = (E - 2) / 3;
            B = 1;
          }
          assert(3*A + 2*B == E);
          assert(A >= 3 && B >= 0);
          assert(A+B <= C);
          // c....**
          // .....**
          // ...****
          // *******
          for (int i = 0; i < R; i++) {
            if (i < 3) {
              for (int j = 0; j < C; j++) {
                if (j < A) a[i][j] = '.';
                else if (i < 2 && j < A+B) a[i][j] = '.';
                else a[i][j] = '*';
              }
            } else {
              for (int j = 0; j < C; j++) {
                a[i][j] = '*';
              }
            }
          }
          a[0][0] = 'c';
        }
      }
    }
  }
  invertBack();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
  verify();
  return;
}


static int tt = 0;
void solve (int r, int c, int m) {
  int e = r * c - m;
  printf("========= %d: R:%d C:%d M:%d E:%d=========\n", ++tt, r, c, m, e);
  assert(m < r * c && m >= 0);
  assert(r >= 1 && c >= 1);
  assert(r < MAX && c < MAX);
  R = r;
  C = c;
  M = m;
  solve(tt);
}

void runTest() {
  // solve(4,4,7);
  for (int r = 45; r < 50 ; r++) {
    for (int c = 45; c < 50; c++) {
      for (int m = 0; m < r * c; m++) {
        solve(r, c, m);
      }
    }
  }
}

int main() {
  // test = true;
  // runTest();

  // reopen("sample.in");
  // reopen("C-small-attempt0.in");
  reopen("C-large.in");
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d %d %d", &R, &C, &M);
    showin();
    solve(t);
  }
  return 0;
}