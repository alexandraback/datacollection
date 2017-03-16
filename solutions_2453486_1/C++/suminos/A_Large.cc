#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define all(c) (c).begin(), (c).end()

const int patterns[][4][2] = {
  { {0,0}, {1,0}, {2,0}, {3,0} },
  { {0,1}, {1,1}, {2,1}, {3,1} },
  { {0,2}, {1,2}, {2,2}, {3,2} },
  { {0,3}, {1,3}, {2,3}, {3,3} },
  { {0,0}, {0,1}, {0,2}, {0,3} },
  { {1,0}, {1,1}, {1,2}, {1,3} },
  { {2,0}, {2,1}, {2,2}, {2,3} },
  { {3,0}, {3,1}, {3,2}, {3,3} },
  { {0,0}, {1,1}, {2,2}, {3,3} },
  { {3,0}, {2,1}, {1,2}, {0,3} },
};

bool won(char player, string line) {
  return count(all(line), player) + count(all(line), 'T') == 4;
}

string solve(vector<string> board) {
  rep(i, 10) {
    string line = "";
    rep(j, 4) line += board[patterns[i][j][1]][patterns[i][j][0]];
    if(won('X', line)) return "X won";
    if(won('O', line)) return "O won";
  }

  rep(i, 4) rep(j, 4) if(board[i][j] == '.') return "Game has not completed";
  return "Draw";
}

int main() {
  int T; cin >> T;
  for(int t=1; t<=T; t++) {
    vector<string> board(4); rep(i, 4) cin >> board[i];
    cout << "Case #" << t << ": " << solve(board) << endl;
  }
}
