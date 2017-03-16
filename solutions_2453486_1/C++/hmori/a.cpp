// 4*4 boarh game 
// start: empty + 'T'
// two player X and O
// 4 of symbols or 3 + 'T' -> win & game ends

#include <iostream>
using namespace std;
void emitB(char b[][4]){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      cout << b[i][j];
    }
    cout << endl;
  }
}

void solve(char b[][4], int t){
  string outStr;
  char line[4];
  // test 10 lines (row, col, diag)
  bool x = false, o = false;

  for(int i = 0; i < 10; i++){

    for(int j = 0; j < 4; j++){
      if(i < 4){ line[j] = b[i][j]; }
      else if(i < 8){ line[j] = b[j][i-4]; }
      else if( i == 8 ){ line[j] = b[j][j]; }
      else if( i == 9 ){ line[j] = b[j][3-j]; }
    }
    // test the line
    bool tmpX = true, tmpO = true;
    for(int j = 0; j < 4; j++){
      if(line[j] == 'X'){
	tmpO = false;
      }else if(line[j] == 'O'){
	tmpX = false;
      }else if(line[j] == '.'){
	tmpX = false;
	tmpO = false;
      }
    }
    if(tmpX){ x = true; break;}
    else if(tmpO){ o = true; break;}
  }
  if(x){outStr = "X won";}
  else if(o){outStr = "O won";}
  else{
    bool full = true;
    // check empty (if full  draw else non-complete)
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
	if(b[i][j] == '.'){
	  full = false;
	}
      }
    }
    if(full){outStr = "Draw";}
    else{outStr = "Game has not completed";}
  }
  cout << "Case #" << t+1 << ": "  << outStr << endl;
}  

int main(){
  int T;
  cin >> T;
  for(int t = 0; t < T; t++){
    char board[4][4];
    string row;
    for(int r = 0; r < 4; r++){
      cin >> row;
      for(int c = 0; c < 4; c++){
	board[r][c] = row[c];
      }
    }
    solve(board, t);
  }
  return 0;
  
}



