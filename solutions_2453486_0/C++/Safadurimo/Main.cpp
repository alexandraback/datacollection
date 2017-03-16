#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned ui;

// data representation for gameboard
char matrix[4][4];
bool emptyCell;

bool checkWinner(char c){
  char ownmatrix[4][4];
  for(ui i=0;i<4;i++)
    for(ui j=0;j<4;j++)
      if(matrix[i][j]=='T')
        ownmatrix[i][j]=c;
      else
        ownmatrix[i][j]=matrix[i][j];

  string winning(4,c);
  string mainDiagonal(4,'x');mainDiagonal[0]=ownmatrix[0][0];mainDiagonal[1]=ownmatrix[1][1];
                            mainDiagonal[2]=ownmatrix[2][2];mainDiagonal[3]= ownmatrix[3][3];
  string antiDiagonal(4,'x');antiDiagonal[0]=ownmatrix[0][3];antiDiagonal[1]=ownmatrix[1][2];
                            antiDiagonal[2]=ownmatrix[2][1];antiDiagonal[3]= ownmatrix[3][0];
  if(winning==mainDiagonal || winning ==antiDiagonal)
    return true;

  // check rows and columns
  for(ui i=0;i<4;i++){
    string row(4,'x');row[0]=ownmatrix[0][i];row[1]=ownmatrix[1][i];
                      row[2]=ownmatrix[2][i];row[3]= ownmatrix[3][i];
    if(row==winning) return true;
    string col(4,'x');col[0]=ownmatrix[i][0];col[1]=ownmatrix[i][1];
                      col[2]=ownmatrix[i][2];col[3]= ownmatrix[i][3];
    if(col==winning) return true;
  }
  return false;
}

int main()
{
  
  int T;
  string s,output;
  
  cin >> T;

  for(ui t=1;t<=T;t++){
    
    // read the gameboard
    emptyCell=false;
    for(ui i=0;i<4;i++){
      cin >> s;
      assert(s.size()==4);
      for(ui j=0;j<s.size();j++){
        matrix[i][j] = s[j];
        if(s[j]=='.') emptyCell=true;
      }
    }

    // check the game result
    if(checkWinner('X'))
      output = "X won";
    else if(checkWinner('O'))
      output = "O won";
    else if(emptyCell)
      output = "Game has not completed";
    else
      output = "Draw";

    // Output the result
    cout << "Case #" << t << ": " << output << endl;

  }
}
