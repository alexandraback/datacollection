#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int T;
string board[4];

vector<int> stat(char ch,char opp) {
  vector<int> v(2);
  v[0] = v[1] = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) if (board[i][j] == ch) v[1]++;
  v[0] = 100;  
  // row
  for (int i = 0; i < 4; i++) {
    int myCount = 0,oppCount = 0;
    for (int j = 0; j < 4; j++)
      if (board[i][j] == ch || board[i][j] == 'T') myCount++;
    else if (board[i][j] == opp) oppCount++;
    if (oppCount) continue;
    v[0] = min(v[0],4 - myCount);
  }
  // col
  for (int j = 0; j < 4; j++) {
    int myCount = 0,oppCount = 0;
    for (int i = 0; i < 4; i++)
      if (board[i][j] == ch || board[i][j] == 'T') myCount++;
    else if (board[i][j] == opp) oppCount++;
    if (oppCount) continue;
    v[0] = min(v[0],4 - myCount);
  }
  // first diagonal
  int myCount = 0,oppCount = 0;
  for (int i = 0; i < 4; i++)
    if (board[i][i] == ch || board[i][i] == 'T') myCount++;
  else if (board[i][i] == opp) oppCount++;
  if (!oppCount) v[0] = min(v[0],4 - myCount);

  // second diagonal
  myCount = oppCount = 0;
  for (int i = 0; i < 4; i++)
    if (board[i][3 - i] == ch || board[i][3 - i] == 'T') myCount++;
  else if (board[i][3 - i] == opp) oppCount++;
  if (!oppCount) v[0] = min(v[0],4 - myCount);
  return v;
}

string determine(vector<int> Xstat,vector<int> Ostat) {
  if (Xstat[0] == 0) return "X won";
  if (Ostat[0] == 0) return "O won";
  int blanks = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) if (board[i][j] == '.') blanks++;
  if (Xstat[1] == Ostat[1]) {
    // X's turn
    // X may win
    if (Xstat[0] <= (blanks - Xstat[0]) + 1) return "Game has not completed";
    // O may win
    if (Ostat[0] <= (blanks - Ostat[0])) return "Game has not completed";
  }
  else {
    // O's turn
    // X may win    
    if (Xstat[0] <= (blanks - Xstat[0])) return "Game has not completed";
    // O may win
    if (Ostat[0] <= (blanks - Ostat[0]) + 1) return "Game has not completed";
  }
  return "Draw";
}

void solveCase(int it) {
  for (int i = 0; i < 4; i++) cin >> board[i];
  vector<int> Xstat = stat('X','O'),Ostat = stat('O','X');
  string outcome = determine(Xstat,Ostat);
  printf("Case #%d: ", it);
  cout << outcome << endl;
}

int main() {
  scanf("%d", &T);
  for (int it = 1; it <= T; it++) solveCase(it);
}
