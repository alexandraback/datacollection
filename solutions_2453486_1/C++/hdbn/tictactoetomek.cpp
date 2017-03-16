#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool checkwin(const vector<string> & grid, char c){
  int i, j, cnt;
  for(i = 0; i < 4; i++){
    cnt = 0;
    for(j = 0; j < 4; j++){
      if(grid[i][j] == c || grid[i][j] == 'T') cnt++;
    }
    if(cnt == 4) return true;
  }
  for(j = 0; j < 4; j++){
    cnt = 0;
    for(i = 0; i < 4; i++){
      if(grid[i][j] == c || grid[i][j] == 'T') cnt++;
    }
    if(cnt == 4) return true;
  }
  cnt = 0;
  for(i = 0; i < 4; i++){
    if(grid[i][i] == c || grid[i][i] == 'T') cnt++;
  }
  if(cnt == 4) return true;
  cnt = 0;
  for(i = 0; i < 4; i++){
    if(grid[3-i][i] == c || grid[3-i][i] == 'T') cnt++;
  }
  if(cnt == 4) return true;
  return false;
}


string solve(const vector<string> & grid){
  int i, j, cnt = 0;
  for(i = 0; i < 4; i++){
    for(j = 0; j < 4; j++){
      if(grid[i][j] != '.') cnt++;
    }
  }
  if(checkwin(grid, 'O')) return "O won";
  if(checkwin(grid, 'X')) return "X won";
  if(cnt == 16) return "Draw";
  return "Game has not completed";
}


int main(int argc, char * argv[]){
  int T, i, n;
  cin >> T;
  for(n = 0; n < T; n++){
    string row, result;
    vector<string> grid;
    for(i = 0; i < 4; i++){
      cin >> row;
      grid.push_back(row);
    }
    result = solve(grid);
    cout << "Case #" << (n+1) << ": " << result << endl;
  }
}
