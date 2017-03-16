#include <iostream>
#include <string>

using namespace std;

inline void print_result(int case_no, string& result) {
  cout << "Case #" << case_no << ": " << result << endl;
}

const int STATUS_START = 0;
const int STATUS_O = 1;
const int STATUS_X = 2;
const int STATUS_NOT_COMPLETE = 3;
const int STATUS_DRAW = 4;

int test_status(char c, int status) {
  switch(c) {
  case 'X':
    if (status == STATUS_O)
      return STATUS_DRAW;
    else
      return STATUS_X;
  case 'O':
    if (status == STATUS_X)
      return STATUS_DRAW;
    else
      return STATUS_O;
  case '.':
    return STATUS_NOT_COMPLETE;
  case 'T':
    return status;
  }
  return STATUS_NOT_COMPLETE;
}

const int X_WON = 0;
const int O_WON = 1;
const int DRAW = 2;
const int NOT_COMPLETE = 3;

int test_win(char a, char b, char c, char d) {
  char cc[4] = {a, b, c, d};   
  int status = STATUS_START;
  for (int i = 0; i < 4; i++) {
    char p = cc[i];
    status = test_status(p, status);
    switch(status) {
    case STATUS_NOT_COMPLETE:
      return NOT_COMPLETE;
    case STATUS_DRAW:
      return DRAW;
    }
  }
  if (status == STATUS_X)
    return X_WON;
  return O_WON;
}

string result_x = "X won";
string result_o = "O won";
string result_draw = "Draw";
string result_not = "Game has not completed";

void test_game(int case_no) {
  char game[4][4];

  for (int i = 0; i < 4; i++) {
    string str;
    cin >> str;
    game[i][0] = str[0];
    game[i][1] = str[1];
    game[i][2] = str[2];
    game[i][3] = str[3];
  }

  bool not_complete = false;
  int status = -1;
  for (int i = 0; i < 4; i++) {
    status = test_win(game[i][0], game[i][1], game[i][2], game[i][3]); 
    if (status == X_WON) {
      print_result(case_no, result_x);
      return;
    }
    if (status == O_WON) {
      print_result(case_no, result_o);
      return;
    }
    if (status == NOT_COMPLETE) {
      not_complete = true;
    }
  }
  for (int i = 0; i < 4; i++) {
    status = test_win(game[0][i], game[1][i], game[2][i], game[3][i]); 
    if (status == X_WON) {
      print_result(case_no, result_x);
      return;
    }
    if (status == O_WON) {
      print_result(case_no, result_o);
      return;
    }
    if (status == NOT_COMPLETE) {
      not_complete = true;
    }
  }

  status = test_win(game[0][0], game[1][1], game[2][2], game[3][3]); 
  if (status == X_WON) {
    print_result(case_no, result_x);
    return;
  }
  if (status == O_WON) {
    print_result(case_no, result_o);
    return;
  }
  if (status == NOT_COMPLETE) {
    not_complete = true;
  }

  status = test_win(game[0][3], game[1][2], game[2][1], game[3][0]); 
  if (status == X_WON) {
    print_result(case_no, result_x);
    return;
  }
  if (status == O_WON) {
    print_result(case_no, result_o);
    return;
  }
  if (status == NOT_COMPLETE) {
    not_complete = true;
  }

  if (not_complete) {
    print_result(case_no, result_not);
    return;
  }
  print_result(case_no, result_draw);
}

int main(int argc, char** argv) {
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {
    test_game(i + 1);
  }
  return 0;
}
