#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long int int64;
typedef vector<int> VI;
#define REP(i,a,b) for (int i=int(a); i<int(b); ++i)
void unittest();

typedef vector<string> VS;
VS board;

bool win(char c) {
  int N = board.size();

  REP(i, 0, N) {
    bool won = true;
    REP(j, 0, N) {
      char b = board[i][j];
      if (b!=c && b!='T') {
        won = false;
        break;
      }
    }
    if (won) return true;
  }
  REP(j, 0, N) {
    bool won = true;
    REP(i, 0, N) {
      char b = board[i][j];
      if (b!=c && b!='T') {
        won = false;
        break;
      }
    }
    if (won) return true;
  }

  // Diag 1
  {
    bool won = true;
    REP(i, 0, N) {
      int j=i;
      char b = board[i][j];
      if (b!=c && b!='T') {
        won = false;
        break;
      }
    }
    if (won) return true;
  }

  // Diag 2
  {
    bool won = true;
    REP(i, 0, N) {
      int j=N-i-1;
      char b = board[i][j];
      if (b!=c && b!='T') {
        won = false;
        break;
      }
    }
    if (won) return true;
  }

  return false;
}

void solve(int caseNum) {
  board.clear();

  while(true) {
    string buf;
    getline(cin, buf);
    if (buf.empty()) break;
    board.push_back(buf);
  }

  string ans;
  if (win('X')) {
    ans = "X won";
  } else if (win('O')) {
    ans = "O won";
  } else {

    bool full = true;
    int N = board.size();
    REP(i, 0, N) {
      REP(j, 0, N) {
        if (board[i][j]=='.') {
          full = false;
        }
      }
    }

    if (full) {
      ans = "Draw";
    } else {
      ans = "Game has not completed";
    }
  }

  printf("Case #%d: %s\n", caseNum, ans.c_str());
}

int main() {
  unittest();

  int caseCount;
  cin>>caseCount;

  string buf; getline(cin, buf);

  REP(i, 1, caseCount+1)
    solve(i);

  return 0;
}

void unittest() {
}

