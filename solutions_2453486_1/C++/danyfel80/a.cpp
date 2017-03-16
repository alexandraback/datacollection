#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <cstring>
#include <string>
#include <iterator>
#include <cstdio>

using namespace std;

int main()
{
  int cases, caseno = 1;
  cin >> cases;

  vector<string>board;
  string cad;
  while(cases--)
  {
    cout << "Case #" << caseno++ << ": ";
    board.clear();
    for(int i = 0; i < 4; i++)
    {
      cin >> cad;
      board.push_back(cad);
    }

    //check row i
    int llenos = 0;
    bool wonX = false;
    bool wonO = false;
    for(int i=0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
        if(board[i][j] != '.')
          llenos++;
      //check cell 0, i vertically each column
      if ((board[0][i] == 'X' || board[0][i] == 'T') && (board[1][i] == 'X' || board[1][i] == 'T') && (board[2][i] == 'X' || board[2][i] == 'T') && (board[3][i] == 'X' || board[3][i] == 'T'))
        wonX = true;
      if ((board[0][i] == 'O' || board[0][i] == 'T') && (board[1][i] == 'O' || board[1][i] == 'T') && (board[2][i] == 'O' || board[2][i] == 'T') && (board[3][i] == 'O' || board[3][i] == 'T'))
        wonO = true;
      //check cell i, 0 horizontally each column
      if ((board[i][0] == 'X' || board[i][0] == 'T') && (board[i][1] == 'X' || board[i][1] == 'T') && (board[i][2] == 'X' || board[i][2] == 'T') && (board[i][3] == 'X' || board[i][3] == 'T'))
        wonX = true;
      if ((board[i][0] == 'O' || board[i][0] == 'T') && (board[i][1] == 'O' || board[i][1] == 'T') && (board[i][2] == 'O' || board[i][2] == 'T') && (board[i][3] == 'O' || board[i][3] == 'T'))
        wonO = true;
    }
    //check cell 0, 0 diagonally each column
    if ((board[0][0] == 'X' || board[0][0] == 'T') && (board[1][1] == 'X' || board[1][1] == 'T') && (board[2][2] == 'X' || board[2][2] == 'T') && (board[3][3] == 'X' || board[3][3] == 'T'))
      wonX = true;
    if ((board[0][0] == 'O' || board[0][0] == 'T') && (board[1][1] == 'O' || board[1][1] == 'T') && (board[2][2] == 'O' || board[2][2] == 'T') && (board[3][3] == 'O' || board[3][3] == 'T'))
      wonO = true;
    //check cell 0, 0 diagonally each column
    if ((board[0][3] == 'X' || board[0][3] == 'T') && (board[1][2] == 'X' || board[1][2] == 'T') && (board[2][1] == 'X' || board[2][1] == 'T') && (board[3][0] == 'X' || board[3][0] == 'T'))
      wonX = true;
    if ((board[0][3] == 'O' || board[0][3] == 'T') && (board[1][2] == 'O' || board[1][2] == 'T') && (board[2][1] == 'O' || board[2][1] == 'T') && (board[3][0] == 'O' || board[3][0] == 'T'))
      wonO = true;

    if(llenos == 16 && wonX==wonO)
    {
      cout << "Draw";
    }else if(llenos < 16 && wonX==wonO)
    {
      cout << "Game has not completed";
    }else if(wonX)
    {
      cout << "X won";
    } else
    {
      cout << "O won";
    }
    cout << endl;
  }

  return 0;
}
