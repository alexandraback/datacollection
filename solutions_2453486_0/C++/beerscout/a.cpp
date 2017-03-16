#include <iostream>
#include <string>


char board[4][4];


bool occupied(int r, int c, char p)
{
  return board[r][c] == 'T' or board[r][c] == p;
}


bool won(char player)
{
  bool good = true;
  for ( int c = 0; c < 4; ++c )
    if ( !occupied(c, c, player) )
    {
      good = false;
      break;
    }
  if ( good )
    return true;
  good = true;
  for ( int c = 0; c < 4; ++c )
    if ( !occupied(c, 3 - c, player) )
    {
      good = false;
      break;
    }
  if ( good )
    return true;
  for ( int c = 0; c < 4; ++c )
  {
    bool good = true;
    for ( int r = 0; r < 4; ++r )
      if ( !occupied(r, c, player) )
      {
        good = false;
        break;
      }
    if ( good )
      return true;
  }
  for ( int r = 0; r < 4; ++r )
  {
    bool good = true;
    for ( int c = 0; c < 4; ++c )
      if ( !occupied(r, c, player) )
      {
        good = false;
        break;
      }
    if ( good )
      return true;
  }
  return false;
}


bool incomplete()
{
  for ( int r = 0; r < 4; ++r )
    for ( int c = 0; c < 4; ++c )
      if ( board[r][c] == '.' )
        return true;
  return false;
}


void run(int no)
{
  std::string w;
  for ( int i = 0; i < 4; ++i )
  {
    std::cin >> w;
    board[i][0] = w[0];
    board[i][1] = w[1];
    board[i][2] = w[2];
    board[i][3] = w[3];
  }
  std::cout << "Case #" << no << ": ";
  if ( won('X') )
    std::cout << "X won" << std::endl;
  else if ( won('O') )
    std::cout << "O won" << std::endl;
  else if ( incomplete() )
    std::cout << "Game has not completed" << std::endl;
  else
    std::cout << "Draw" << std::endl;
}


int main()
{
  int ncases;
  std::cin >> ncases;
  for ( int i = 1; i <= ncases; ++i )
    run(i);
  return 0;
}
