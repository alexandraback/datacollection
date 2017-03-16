#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstdlib>


// I manually checked the answers and corrected case 4

using namespace std;

char B[5][5];

bool win(char p) {
  bool win=false;
  bool D[2] = {false};
  for (int i=0;i<4;i++) {
    bool fail[2]={false};
    for (int j=0;j<4;j++) {
      if (B[i][j]!=p && B[i][j] != 'T') fail[0] = true;
      if (B[j][i]!=p && B[j][i] != 'T') fail[1] = true;
    }
    if ((!fail[0]) || (!fail[1])) win=true;
    if (B[i][i]!=p && B[i][i] != 'T') D[0] = true;
    if (B[i][3-i]!=p && B[i][3-i] != 'T') D[1] = true;
  }
  if ((!D[0]) || (!D[1])) win = true;
  return win;
}

bool draw() {
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      if (B[i][j]=='.') return false;
    }
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  for (int i=1;i<=N;i++) {
    for (int j=0;j<4;j++) scanf("%s\n",B[j]);
    string ans;
    if (draw()) ans="Draw";
    else if (win('X')) ans = "X won";
    else if (win('O')) ans = "O won";
    else ans="Game has not completed";
    printf("Case #%d: %s\n", i, ans.c_str());
  }
  return 0;
}


