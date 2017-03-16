#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_dot(const vector<string> & map) {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (map[i][j] == '.') {
        return true;
      }
    }
  }
  return false;
}

void get_case(const vector<string> & map, vector<string> & cases) {
  cases.clear();
  for (int i=0; i<4; i++) {
    cases.push_back(map[i]);
  }
  for (int i=0; i<4; i++) {
    string str;
    for (int j=0; j<4; j++) {
      str += map[j][i];
    }
    cases.push_back(str);
  }
  string d1;
  string d2;
  for (int i=0; i<4; i++) {
    d1 += map[i][i];
    d2 += map[i][3-i];
  }
  cases.push_back(d1);
  cases.push_back(d2);
}

void find_T(const vector<string> & map, int & row, int & col) {
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      if (map[i][j] == 'T') {
        row = i;
        col = j;
        return;
      }
    }
  }
}

int main(int argc, char * argv[]) {
  string res[] = {"X won",
                  "O won",
                  "Draw",
                  "Game has not completed"};
  int num;
  cin >> num;
  for (int i=0; i<num; i++) {
    cout << "Case #" << i+1 << ": ";
    vector<string> map;
    for (int j=0; j<4; j++) {
      string line;
      cin >> line;
      map.push_back(line);
    }

    int row, col;
    row = 100;
    find_T(map, row, col);

    int winner = 2;
    vector<string> cases;
    if (row<4) {
      map[row][col] = 'X';
    }
    get_case(map, cases);
    for (int j=0; j<cases.size(); j++) {
      if (cases[j] == "XXXX") {
        winner = 0;
        break;
      }
    }
    if (row<4) {
      map[row][col] = 'O';
    }
    get_case(map, cases);
    for (int j=0; j<cases.size(); j++) {
      if (cases[j] == "OOOO") {
        winner = 1;
        break;
      }
    }

    if (winner == 2 && check_dot(map)) {
      winner = 3;
    }
    cout << res[winner] << endl;
  }
  return 0;
}



