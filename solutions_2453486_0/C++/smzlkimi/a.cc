#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

vector<string> split(const string& s, const string& delim =" ");
vector<int> splitInt(const string& s, const string& delim =" ");
vector<double> splitDouble(const string& s, const string& delim =" ");

int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./program input output\n");
    return -1;
  }
  ifstream fin(argv[1]);
  if (!fin) {
    printf("open %s failed\n", argv[1]);
    return -1;
  }
  FILE *fp = fopen(argv[2], "w");

  string buffer_line;
  getline(fin, buffer_line);
  int case_num = atoi(buffer_line.c_str());

  for (int case_i = 0; case_i < case_num; ++case_i) {
    if (case_i != 0) {
      // empty line..
      getline(fin, buffer_line);
    }
    char board[4][4];
    for (int i = 0; i < 4; ++i) {
      getline(fin, buffer_line);
      for (int j = 0; j < 4; ++j) {
        board[i][j] = buffer_line[j];
      }
    }
    int num_x = 0;
    int num_o = 0;
    int num_t = 0;
    int num_dot = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (board[i][j] == 'X') {
          num_x++;
        } else if (board[i][j] == 'O') {
          num_o++;
        } else if (board[i][j] == 'T') {
          num_t++;
        } else if (board[i][j] == '.') {
          num_dot++;
        } else {
          printf("WTF\n");exit(1);
        }
      }
    }
    // 0 for X, 1 for O
    int turn = 0;
    char need_check = 'X';
    if (num_x == num_o) {
      turn = 1;
      need_check = 'O';
    } else {
      turn = 0;
      need_check = 'X';
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (board[i][j] == 'T') {
          if (turn == 0) {
            board[i][j] = 'X';
          } else {
            board[i][j] = 'O';
          }
        }
      }
    }
    bool win = false;
    // printf("need_check %c\n", need_check);
    // check dig
    if (board[0][0] == need_check
      &&board[1][1] == need_check
      &&board[2][2] == need_check
      &&board[3][3] == need_check) {
      win = true;
    } else if (board[0][3] == need_check
             &&board[1][2] == need_check
             &&board[2][1] == need_check
             &&board[3][0] == need_check) {
      win = true;
    } else {
      for (int i = 0; i < 4; ++i) {
        if (board[i][0] == need_check && board[i][1] == need_check
        &&  board[i][2] == need_check && board[i][3] == need_check) {
          win = true;
          break;
        }
        if (board[0][i] == need_check && board[1][i] == need_check
        &&  board[2][i] == need_check && board[3][i] == need_check) {
          win = true;
          break;
        }
      }
    }
    if (win) {
      if (need_check == 'X') {
        fprintf(fp, "Case #%d: X won\n", case_i+1);
      } else if (need_check == 'O') {
        fprintf(fp, "Case #%d: O won\n", case_i+1);
      } else {
        printf("WTF");
        exit(1);
      }
    } else {
      if (num_dot == 0) {
        fprintf(fp, "Case #%d: Draw\n", case_i+1);
      } else {
        fprintf(fp, "Case #%d: Game has not completed\n", case_i+1);
      }
    }
  }

  fclose(fp);
}









vector<string> split(const string& s, const string& delim) {
  vector<string> res;
  string t;
  for (int i = 0 ; i != s.size() ; i++) {
    if (delim.find( s[i] ) != string::npos) {
      if (!t.empty()) {
        res.push_back(t);
        t = "";
      }
    } else {
      t += s[i];
    }
  }
  if (!t.empty()) {
    res.push_back(t);
  }
  return res;
}

vector<int> splitInt(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<int> res;
  for (int i = 0 ; i != tok.size(); i++)
    res.push_back(atoi(tok[i].c_str()));
  return res;
}

vector<double> splitDouble(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<double> res;
  for (int i = 0 ; i != tok.size(); i++)
    res.push_back(atof(tok[i].c_str()));
  return res;
}
