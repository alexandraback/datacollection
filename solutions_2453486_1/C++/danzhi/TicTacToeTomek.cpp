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

const char rootdir[] = "C:\\CodeJam\\TicTacToeTomek";
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

int T = 0;
char a[10][10];

void showin() {
	if (!test) return;
  for (int i = 0; i < 4; i++) {
    printf("%s\n", a[i]);
  }
  printf("\n");
}

inline bool isXT(char c) {
  return c == 'X' || c == 'T';
}

inline bool isOT(char c) {
  return c == 'O' || c == 'T';
}

bool xWin(char c[4]) {
  return isXT(c[0]) && isXT(c[1]) && isXT(c[2]) && isXT(c[3]);
}

bool oWin(char c[4]) {
  return isOT(c[0]) && isOT(c[1]) && isOT(c[2]) && isOT(c[3]);
}

void solve(int cn) {
  char c[4];
  char d1[4];
  char d2[4];
  bool xwin = false;
  bool owin = false;
  bool over = true;
  d1[0] = a[0][0];
  d1[1] = a[1][1];
  d1[2] = a[2][2];
  d1[3] = a[3][3];
  d2[0] = a[0][3];
  d2[1] = a[1][2];
  d2[2] = a[2][1];
  d2[3] = a[3][0];
  if (xWin(d1) || xWin(d2)) {
    printf("Case #%d: X won\n", cn);
    return;
  } else if (oWin(d1) || oWin(d2)) {
    printf("Case #%d: O won\n", cn);
    return;
  }
  for (int i = 0; i < 4; i++) {
    c[0] = a[0][i];
    c[1] = a[1][i];
    c[2] = a[2][i];
    c[3] = a[3][i];
    if (xWin(a[i]) || xWin(c)) {
      printf("Case #%d: X won\n", cn);
      return;
    } else if (oWin(a[i]) || oWin(c)) {
      printf("Case #%d: O won\n", cn);
      return;
    }
    if (c[0] == '.' || c[1] == '.' || c[2] == '.' || c[3] == '.') over = false;
  }
  if (over) {
    printf("Case #%d: Draw\n", cn);
  } else {
    printf("Case #%d: Game has not completed\n", cn);
  }
}

int main(int argc, char* argv[]) {
	// reopen("sample.in");
  // reopen("A-small-attempt0.in");
  reopen("A-large.in");
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
    for (int i = 0; i < 4; i++) {
      scanf("%s", a[i]);
    }
    // showin();
    solve(t);
  }
 	return 0;
}