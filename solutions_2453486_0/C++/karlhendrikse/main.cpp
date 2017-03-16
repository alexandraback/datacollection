
#include <cassert>
#include <cstdio>

char match(
  char a,
  char b,
  char c,
  char d)
{
  char matchTo = '\0';
  bool tUsed = false;

  if(a == '.')
  {
    return '\0';
  }
  else if(a == 'T')
  {
    if(tUsed)
    {
      //more than one 'T'
      return '\0';
    }
    tUsed = true;
  }
  else if(matchTo == '\0')
  {
    matchTo = a;
  }
  else if(a != matchTo)
  {
    return '\0';
  }

  if(b == '.')
  {
    return '\0';
  }
  else if(b == 'T')
  {
    if(tUsed)
    {
      //more than one 'T'
      return '\0';
    }
    tUsed = true;
  }
  else if(matchTo == '\0')
  {
    matchTo = b;
  }
  else if(b != matchTo)
  {
    return '\0';
  }

  if(c == '.')
  {
    return '\0';
  }
  else if(c == 'T')
  {
    if(tUsed)
    {
      //more than one 'T'
      return '\0';
    }
    tUsed = true;
  }
  else if(matchTo == '\0')
  {
    matchTo = c;
  }
  else if(c != matchTo)
  {
    return '\0';
  }

  if(d == '.')
  {
    return '\0';
  }
  else if(d == 'T')
  {
    if(tUsed)
    {
      //more than one 'T'
      return '\0';
    }
    tUsed = true;
  }
  else if(matchTo == '\0')
  {
    matchTo = d;
  }
  else if(d != matchTo)
  {
    return '\0';
  }

  return matchTo;
}

int main()
{
  //assert(match('X', 'X', 'X', 'T') == 'X');

  int t;
  std::scanf("%d", &t);
  for(int tt = 0; tt < t; ++tt)
  {
    char board[5][5];
    for(int y = 0; y < 4; ++y)
    {
      std::scanf("%s", board[y]);
    }

    char winner;

    do
    {
      for(int i = 0; i < 4; ++i)
      {
        winner = match(board[i][0], board[i][1], board[i][2], board[i][3]); if(winner != '\0') break;
        winner = match(board[0][i], board[1][i], board[2][i], board[3][i]); if(winner != '\0') break;
      }
      if(winner != '\0') break;
      winner = match(board[0][0], board[1][1], board[2][2], board[3][3]); if(winner != '\0') break;
      winner = match(board[0][3], board[1][2], board[2][1], board[3][0]); if(winner != '\0') break;
    } while(false);

    const char *output;
    if(winner == 'X') output = "X won";
    else if(winner == 'O') output = "O won";
    else
    {
      bool dot = false;
      for(int y = 0; y < 4; ++y)
      {
        for(int x = 0; x < 4; ++x)
        {
          if(board[y][x] == '.')
          {
            dot = true;
            break;
          }
        }
      }
      output = dot ? "Game has not completed" : "Draw";
    }
    std::printf("Case #%d: %s\n", tt + 1, output);
  }
}
