//
//  Q_A.cpp
//  Topcoder
//
//  Created by Charlene Jiang on 4/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> board;

string deal()
{
  int cntX, cntO, cntT;
  bool isFull = true;
  
  // row
  for (int i = 0; i < 4; i ++) {
    cntX = 0, cntO = 0, cntT = 0;
    
    for (int j = 0; j < 4; j ++) {
      if (board[i][j] == 'O') {
        cntO ++;
      } else if (board[i][j] == 'X') {
        cntX ++;
      } else if (board[i][j] == 'T') {
        cntT ++;
      } else {
        isFull = false;
      }
    }
    
    if (cntX == 4 || (cntX == 3 && cntT == 1)) {
      return "X won";
    } else if (cntO == 4 || (cntO == 3 && cntT == 1)){
      return "O won";
    }
  }
  
  // column
  for (int i = 0; i < 4; i ++) {
    cntX = 0, cntO = 0, cntT = 0;
    
    for (int j = 0; j < 4; j ++) {
      if (board[j][i] == 'O') {
        cntO ++;
      } else if (board[j][i] == 'X') {
        cntX ++;
      } else if (board[j][i] == 'T') {
        cntT ++;
      } else {
        break;
      }
    }
    
    if (cntX == 4 || (cntX == 3 && cntT == 1)) {
      return "X won";
    } else if (cntO == 4 || (cntO == 3 && cntT == 1)){
      return "O won";
    }
  }
  
  //
  cntX = 0, cntO = 0, cntT = 0;
  for (int i = 0; i < 4; i ++) {
    if (board[i][i] == 'O') {
      cntO ++;
    } else if (board[i][i] == 'X') {
      cntX ++;
    } else if (board[i][i] == 'T') {
      cntT ++;
    } else {
      break;
    }
  }
  
  if (cntX == 4 || (cntX == 3 && cntT == 1)) {
    return "X won";
  } else if (cntO == 4 || (cntO == 3 && cntT == 1)){
    return "O won";
  }
  
  //
  cntX = 0, cntO = 0, cntT = 0;
  for (int i = 0; i < 4; i ++) {
    if (board[i][3 - i] == 'O') {
      cntO ++;
    } else if (board[i][3 - i] == 'X') {
      cntX ++;
    } else if (board[i][3 - i] == 'T') {
      cntT ++;
    } else {
      break;
    }
  }
  
  if (cntX == 4 || (cntX == 3 && cntT == 1)) {
    return "X won";
  } else if (cntO == 4 || (cntO == 3 && cntT == 1)){
    return "O won";
  }
  
  
  if (!isFull) {
    return "Game has not completed";
  } else {
    return "Draw";
  }
  
}

int main()
{
  freopen("/Users/yingjiang/TopCoder/Codejam/a.in", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/a.out", "w", stdout);
  
  int T;
  cin >> T;
  
  
  for (int cases = 1; cases <= T; cases ++) {
    board.resize(4);
    for (int i = 0; i < 4; i ++) {
      cin >> board[i];
    }
    
    cout << "Case #" << cases << ": " << deal() << endl;
  }
}
