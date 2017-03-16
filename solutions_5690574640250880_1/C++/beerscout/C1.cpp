#include <iostream>


const int dr[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
const int dc[] = { -1,  0,  1, -1, 1, -1, 0, 1 };


struct Board
{
  char b[50][50];
  bool vis[50][50][50*50 + 1];
  int R, C, M;
  bool ok(int r, int c) const
  {
    return r >= 0 and r < R and c >= 0 and c < C;
  }
  void clear();
  void print();
  int n_bombs(int r, int c) const;
  bool search(int r, int c, int left);
};


int Board::n_bombs(int r, int c) const
{
  int n = 0;
  for ( int i = 0; i < 8; ++i )
  {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if ( ok(nr, nc) and b[nr][nc] == '*' )
      ++n;
  }
  return n;
}
  

void Board::clear()
{
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
      b[r][c] = '*';
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
      for ( int m = 0; m <= R*C; ++m )
        vis[r][c][m] = false;
}


void Board::print()
{
  for ( int r = 0; r < R; ++r )
  {
    for ( int c = 0; c < C; ++c )
      std::cout << b[r][c];
    std::cout << '\n';
  }
}


bool Board::search(int r, int c, int left)
{
  //std::cerr << "s(" << r << ',' << c << ',' << left << std::endl;
  bool &stat = vis[r][c][left];
  if ( stat )
    return false;
  stat = true;
  if ( left == 0 )
  {
    return true;
  }
  int nb = n_bombs(r, c);
  if ( left == 1 )
  {
    if ( b[r][c] == '*' )
    {
      b[r][c] = '.';
      return true;
    }
  }
  if ( b[r][c] == '*' )
    ++nb;
  if ( left >= nb )
  {
    int rx[9], cx[9];
    int d = 0;
    if ( b[r][c] == '*' )
    {
      b[r][c] = '.';
      rx[d] = r; cx[d] = c;
      ++d;
    }
    for ( int i = 0; i < 8; ++i )
    {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if ( ok(nr, nc) and b[nr][nc] == '*' )
      {
        b[nr][nc] = '.';
        rx[d] = nr; cx[d] = nc;
        ++d;
      }
    }
    for ( int i = 0; i < 8; ++i )
    {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if ( ok(nr, nc) and search(nr, nc, left - nb) )
      {
        return true;
      }
    }
    for ( int i = 0; i < d; ++i )
    {
      int nr = rx[i];
      int nc = cx[i];
      b[nr][nc] = '*';
    }
  }
  return false;
}


bool find(Board &B)
{
  int left = B.R*B.C - B.M;
  B.clear();
  for ( int r = 0; r < B.R; ++r )
    for ( int c = 0; c < B.C; ++c )
      if ( B.search(r, c, left) )
      {
        B.b[r][c] = 'c';
        return true;
      }
  return false;
}


void read_case()
{
  Board B;
  std::cin >> B.R >> B.C >> B.M;
  if ( not find(B) )
  {
    std::cout << "Impossible\n";
  }
  else
  {
    B.print();
  }
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    std::cout << "Case #" << t << ":\n";
    read_case();
  }
  return 0;
}
