#include <iostream>
#include <vector>


bool possible(std::vector< std::vector<int> > const &lawn)
{
  int R = lawn.size();
  int C = lawn[0].size();
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
    {
      int v = lawn[r][c];
      bool good = true;
      for ( int i = 0; i < C; ++i )
        if ( lawn[r][i] > v )
        {
          good = false;
          break;
        }
      if ( good )
        continue;
      for ( int i = 0; i < R; ++i )
        if ( lawn[i][c] > v )
        {
          return false;
        }
    }
  return true;
}


void run(int no)
{
  int R, C;
  std::cin >> R >> C;
  std::vector< std::vector<int> > lawn(R);
  for ( int r = 0; r < R; ++r )
  {
    lawn[r].resize(C);
    for ( int c = 0; c < C; ++c )
      std::cin >> lawn[r][c];
  }
  std::cout << "Case #" << no << ": ";
  if ( possible(lawn) )
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
    run(t);
  return 0;
}
