#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  char buff[16];
  cin.getline(buff, 10);

  for (int t=1; t<=T; t++)	{
    char game[5][6];
	  for (int i=0; i<4; i++) {
      cin.getline(game[i], 5);
      game[i][4] = game[i][0];
      game[4][i] = game[0][i];
    }
    cin.getline(buff, 10);

    cout << "Case #" << t << ": ";

    bool compl(true);
    char diag1(game[0][0]), diag2(game[0][3]);
        
    for (int i=0; i<4; i++) 
      for (int j=0; j<4; j++) {
        if (game[i][j] == '.') {
          compl=false;
          game[4][j] = '.';
          game[i][4] = '.';
          if (i==j) diag1 = '.';
          if (i==3-j) diag2 = '.';
        }
        if (game[i][j] == 'X' || game[i][j] == 'O') {
          if (game[4][j] != game[i][j]) game[4][j] = game[4][j] == 'T' ? game[i][j] : '.';
          if (game[i][4] != game[i][j]) game[i][4] = game[i][4] == 'T' ? game[i][j] : '.';
          if (i==j && diag1 != game[i][j]) diag1 = diag1 == 'T' ? game[i][j] : '.';
          if (i==3-j && diag2 != game[i][j]) diag2 = diag2 == 'T' ? game[i][j] : '.';
        }
      }

    bool x(diag1 == 'X' || diag2 == 'X');
    bool o(diag1 == 'O' || diag2 == 'O');

    for (int i=0; i<4; i++)
      if (game[i][4] == 'X' || game[4][i] == 'X') x = true;
      else if (game[i][4] == 'O' || game[4][i] == 'O') o = true;

    if (x)
      cout << "X won" << endl;
    else if (o)
      cout << "O won" << endl;
    else if (!compl) 
      cout << "Game has not completed" << endl;
    else
      cout << "Draw" << endl;
	}
  
	return 0;
}
