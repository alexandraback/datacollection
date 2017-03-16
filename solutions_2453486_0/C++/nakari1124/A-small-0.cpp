#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long i64;
typedef int int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size)
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

const int O = 1;
const int X = 2;
const int T = 3;

bool check_O(int v) {
  return v == O || v == T;
}
bool check_X(int v) {
  return v == X || v == T;
}

bool check4(int v1, int v2, int v3, int v4) {
  if(check_O(v1) && check_O(v2) && check_O(v3) && check_O(v4)) {
    cout << "O won";
    return true;
  }
  else if(check_X(v1) && check_X(v2) && check_X(v3) && check_X(v4)) {
    cout << "X won";
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {

  i64 C;
  cin >> C;
  i64 n;
  i64 i, j;

  REP(0, C, n) {
    cout << "Case #" << n + 1 << ": ";

    bool empty_exist = false;

    vvi board(4, vi(4, 0));
    string line;
    getchar();
    REP(0, 4, i) {
      getline(cin, line);
      REP(0, 4, j) {
	switch(line[j]) {
	case 'O':
	  board[i][j] = O;
	  break;
	case 'X':
	  board[i][j] = X;
	  break;
	case 'T':
	  board[i][j] = T;
	  break;
	case '.':
	  board[i][j] = 0;
	  empty_exist = true;
	  break;
	}
      }
    }

    bool status = false;
    REP(0, 4, i) {
      if(!status)
	status = check4(board[i][0], board[i][1], board[i][2], board[i][3]);
      if(!status)
	status = check4(board[0][i], board[1][i], board[2][i], board[3][i]);
    }

    if(!status)
      status = check4(board[0][0], board[1][1], board[2][2], board[3][3]);
    if(!status)
      status = check4(board[0][3], board[1][2], board[2][1], board[3][0]);

    if(!status) {
      if(empty_exist) {
	cout << "Game has not completed";
      }
      else {
	cout << "Draw";
      }
    }

    cout << endl;
  }

  return 0;
}
