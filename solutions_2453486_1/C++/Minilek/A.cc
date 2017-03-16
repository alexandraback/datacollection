#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

string grid[4];

char won(char c) {
  int cc, ct;
  for (int i = 0; i < 4; ++i) {
    cc = 0, ct = 0;
    for (int j = 0; j < 4; ++j)
      if (grid[i][j] == 'T')
	++ct;
      else if (grid[i][j] == c)
	++cc;
    if (cc==4 || (cc==3 && ct))
      return 1;
  }
  for (int j = 0; j < 4; ++j) {
    cc = 0, ct = 0;
    for (int i = 0; i < 4; ++i)
      if (grid[i][j] == 'T')
	++ct;
      else if (grid[i][j] == c)
	++cc;
    if (cc==4 || (cc==3 && ct))
      return 1;
  }
  cc = 0, ct = 0;
  for (int i = 0; i < 4; ++i)
    if (grid[i][i] == 'T')
      ++ct;
    else if (grid[i][i] == c)
      ++cc;
  if (cc==4 || (cc==3 && ct))
    return 1;
  cc = 0, ct = 0;
  for (int i = 0; i < 4; ++i)
    if (grid[i][3-i] == 'T')
      ++ct;
    else if (grid[i][3-i] == c)
      ++cc;
  if (cc==4 || (cc==3 && ct))
    return 1;
  return 0;
}

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    string s;
    for (int i = 0; i < 4; ++i)
      getline(cin, grid[i]);
    getline(cin, s);
    if (won('X'))
      printf("Case #%d: X won\n", rr);
    else if (won('O'))
      printf("Case #%d: O won\n", rr);
    else {
      char dot = 0;
      for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	  if (grid[i][j] == '.')
	    dot = 1;
      if (dot)
	printf("Case #%d: Game has not completed\n", rr);
      else
	printf("Case #%d: Draw\n", rr);
    }
  }
  return 0;
}
