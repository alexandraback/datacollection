#include <deque>
#include <tuple>
#include <iostream>


const int dr[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
const int dc[] = { -1,  0,  1, -1, 1, -1, 0, 1 };


struct Board
{
  char b[5][5];
  int R, C, M;
  int enc() const;
  void dec(int e);
  int n_shown(int r, int c);
  bool n_shown(int left);
  int n_bombs(int r, int c) const;
  bool ok(int r, int c) const
  {
    return r >= 0 and r < R and c >= 0 and c < C;
  }
  void clear();
  void print();
};



void Board::clear()
{
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
      if ( b[r][c] != '*' )
        b[r][c] = '.';
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


int Board::enc() const
{
  int e = 0, m = 1;
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
    {
      if ( b[r][c] == '*' )
        e |= m;
      m <<= 1;
    }
  return e;
}


void Board::dec(int e)
{
  int m = 1;
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
    {
      if ( e & m )
        b[r][c] = '*';
      else
        b[r][c] = '.';
      m <<= 1;
    }
}


int Board::n_shown(int r, int c)
{
  if ( b[r][c] == '*' )
    return 0;
  std::deque<std::pair<int, int>> Q;
  Q.push_back(std::make_pair(r, c));
  int n = 0;
  while ( not Q.empty() )
  {
    std::tie(r, c) = Q.front();
    Q.pop_front();
    if ( b[r][c] != '.' )
      continue;
    ++n;
    b[r][c] = n_bombs(r, c) + '0';
    if ( b[r][c] == '0' )
    {
      for ( int i = 0; i < 8; ++i )
      {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if ( ok(nr, nc) and b[nr][nc] == '.' )
          Q.push_back(std::make_pair(nr, nc));
      }
    }
  }
  return n;
}


bool Board::n_shown(int left)
{
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
      if ( b[r][c] == '.' and n_bombs(r, c) == 0 )
      {
        if ( n_shown(r, c) == left )
        {
          clear();
          b[r][c] = 'c';
          return true;
        }
      }
  return false;
}


void read_case()
{
  Board B;
  std::cin >> B.R >> B.C >> B.M;
  int N = B.R*B.C, m = 1<<N;
  if ( B.M >= N )
  {
    std::cout << "Impossible\n";
    return;
  }
  int s = (1<<B.M) - 1;
  int left = N - B.M;
  if ( left == 1 )
  {
    B.dec(s);
    B.b[B.R - 1][B.C - 1] = 'c';
    B.print();
    return;
  }
  while (!(s & m))
  {
    B.dec(s);
    if ( B.n_shown(left) )
    {
      B.print();
      return;
    }
    int lo = s & ~(s - 1);   
    int lz = (s + lo) & ~s; 
    s |= lz;               
    s &= ~(lz - 1);       
    s |= (lz / lo / 2) - 1;
  }
  std::cout << "Impossible\n";
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
