#include <vector>
#include <iostream>
#include <stdexcept>

struct googler
{
  int sup;
  int reg;
};


googler calc_max(int total)
{
  googler g;
  int r = total%3;
  switch ( r )
  {
    case 0:
      g.reg = total/3;
      if ( total >= 3 )
        g.sup = 2 + (total - 3)/3;
      else
        g.sup = -1;
      break;
    case 1:
      g.reg = 1 + total/3;
      if ( total >= 4 )
        g.sup = 2 + (total - 4)/3;
      else
        g.sup = -1;
      break;
    default:
      g.reg = 1 + total/3;
      g.sup = 2 + total/3;
      break;
  }
  return g;
}


int num_googlers(std::vector<int> const &scores, int S, int p)
{
  int nsup = 0;
  int nreg = 0;
  int nonsup = 0;
  int N = scores.size();
  for ( int i = 0; i < N; ++i )
  {
    googler g = calc_max(scores[i]);
    if ( g.sup == -1 )
    {
      if ( g.reg >= p )
        ++nonsup;
      continue;
    }
    if ( g.reg >= p )
      ++nreg;
    else if ( g.sup >= p )
      ++nsup;
  }
  if ( S > N - nonsup )
  {
    int bads = S - N + nonsup;
    return nsup + nreg + nonsup - bads;
  } 
  return std::min(S, nsup) + nreg + nonsup;
}

int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N, S, p;
    std::cin >> N >> S >> p;
    std::vector<int> scores(N);
    for ( int i = 0; i < N; ++i )
      std::cin >> scores[i];
    std::cout << "Case #" << t << ": "
      << num_googlers(scores, S, p) << '\n';
  }
  return 0;
}
