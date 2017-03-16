#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isWon(const vector<string>& board, char mark) {
  bool md = true, sd = true;
  for(int i = 0; i < 4; ++i) {
    bool row = true, col = true;
    for(int j = 0; j < 4; ++j) {
      col &= (board[i][j] == mark || board[i][j] == 'T');
      row &= (board[j][i] == mark || board[j][i] == 'T');
    }
    md &= (board[i][i] == mark || board[i][i] == 'T');
    sd &= (board[i][3 - i] == mark || board[i][3 - i] == 'T');
    if(row || col) return true;
  }
  return md || sd;
}

bool isFull(const vector<string>& board) {
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      if(board[i][j] == '.') return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  ifstream ifs(argv[1]);
  int n;
  ifs >> n;
  for(int i = 0; i < n; ++i) {
    vector<string> board;
    string s;
    getline(ifs, s);
    for(int j = 0; j < 4; ++j) {
      getline(ifs, s);
      board.push_back(s);
    }
    cout << "Case #" << i + 1 << ": ";
    if(isWon(board, 'X')) cout << "X won" << endl;
    else if(isWon(board, 'O')) cout << "O won" << endl;
    else if(isFull(board)) cout << "Draw" << endl;
    else cout << "Game has not completed" << endl;
  }
}
