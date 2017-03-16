//this is the default for Google code jam only
#include <string>
#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pii pair<int, int>

using namespace std;

ifstream fi("A-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("in");
ofstream fo("out");

int test;
string a[4];
int frow[3][4];
int fcol[3][4];
int fd[3][2];
int res;
bool full;

void input();
void solve();
void output();

int main() {
  int ntest;
  fi >> ntest;
  for (test = 1; test <= ntest; test ++) {
    input();
    solve();
    output();
  }
  fi.close();
  fo.close();
  return 0;
}

void input() {
  //start code here
  for (int i = 0; i < 4; i ++) fi >> a[i];
}

void solve() {
  full = true;
  for (int p = 0; p < 3; p ++)
    for (int i = 0; i < 4; i ++) {
      frow[p][i] = 0;
      fcol[p][i] = 0;      
    }
  for (int p = 0; p < 3; p ++)
    for (int i = 0; i < 2; i ++) {
      fd[p][i] = 0;
    }
  for (int i = 0; i < 4; i ++)
    for (int j = 0; j < 4; j ++) {
      if (a[i][j] == 'X') {
	frow[0][i] ++;
	fcol[0][j] ++;
	if (i == j) fd[0][0] ++;
	if (i + j == 3) fd[0][1] ++;
      }
      else if (a[i][j] == 'O') {
	frow[1][i] ++;
	fcol[1][j] ++;
	if (i == j) fd[1][0] ++;
	if (i + j == 3) fd[1][1] ++;
      }
      else if (a[i][j] == 'T') {
	frow[2][i] ++;
	fcol[2][j] ++;
	if (i == j) fd[2][0] ++;
	if (i + j == 3) fd[2][1] ++;
      }
      else if (a[i][j] == '.') {
	full = false;
      }
    }
  // check X
  for (int i = 0; i < 4; i ++)
    if (frow[0][i] + frow[2][i] == 4) {
      res = 1;
      return;
    }
  for (int j = 0; j < 4; j ++)
    if (fcol[0][j] + fcol[2][j] == 4) {
      res = 1;
      return;
    }
  if (fd[0][0] + fd[2][0] == 4) {
    res = 1;
    return;
  }
  if (fd[0][1] + fd[2][1] == 4) {
    res = 1;
    return;
  }
  // check 0
  for (int i = 0; i < 4; i ++)
    if (frow[1][i] + frow[2][i] == 4) {
      res = 2;
      return;
    }
  for (int j = 0; j < 4; j ++)
    if (fcol[1][j] + fcol[2][j] == 4) {
      res = 2;
      return;
    }
  if (fd[1][0] + fd[2][0] == 4) {
    res = 2;
    return;
  }
  if (fd[1][1] + fd[2][1] == 4) {
    res = 2;
    return;
  }
  if (full) {
    res = 3;
    return;
  }
  else {
    res = 4;
    return;
  }
}

void output() {
  fo << "Case #" << test << ": ";
  if (res == 1) {
    fo << "X won" << endl;
  }
  else if (res == 2) {
    fo << "O won" << endl;
  }
  else if (res == 3) {
    fo << "Draw" << endl;
  }
  else if (res == 4) {
    fo << "Game has not completed" << endl;
  }
}
