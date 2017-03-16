#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int tt=0; tt<T; ++tt)
  {
    printf("Case #%d: ", tt+1);
    char t[4][4];
    // Read input
    for (int i=0; i<4; ++i)
      for (int j=0; j<4; j++)
        cin >> t[i][j];
    // Solve
    bool full = true;
    bool has_winner = false;
    // Check straight
    for (int i=0; i<4; ++i)
    {
      bool winrx = true, winro = true;
      bool wincx = true, winco = true;
      for (int k = 0; k < 4; ++k)
      {
        if (t[i][k] == '.')
        {
          full = false;
          winrx = winro = false;
        }
        if (t[k][i] == '.')
        {
          full = false;
          wincx = winco = false;
        }
        if (t[i][k] == 'O') winrx = false;
        if (t[i][k] == 'X') winro = false;
        if (t[k][i] == 'O') wincx = false;
        if (t[k][i] == 'X') winco = false;
      }
      if (winrx || wincx)
      {
        printf("X won\n");
        has_winner = true;
        break;
      }
      if (winro || winco)
      {
        printf("O won\n");
        has_winner = true;
        break;
      }
    }
    if (!has_winner)
    {
      bool win1x = true, win1o = true, win2x = true, win2o = true;
      for (int i=0; i<4; ++i)
      {
        if (t[i][i] == '.') win1x = win1o = false;
        if (t[i][3-i] == '.') win2x = win2o = false;
        if (t[i][i] == 'X') win1o = false;
        if (t[i][i] == 'O') win1x = false;
        if (t[i][3-i] == 'X') win2o = false;
        if (t[i][3-i] == 'O') win2x = false;
      }
      if (win1x || win2x)
      {
        printf("X won\n");
        has_winner = true;
      } else if (win1o || win2o)
      {
        printf("O won\n");
        has_winner = true;
      } else if (!has_winner)
      {
        if (full) printf("Draw\n");
        else printf("Game has not completed\n");
      }
    }
  }
}
