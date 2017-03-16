#include <iostream>
#include <deque>
#include <algorithm>


int np[1<<10][1<<10];
std::deque<double> n_blocks, k_blocks;


int n_pointsr1(int nm, int km)
{
  if ( nm == 0 )
    return 0;
  if ( np[nm][km] >= 0 )
    return np[nm][km];
  int N = n_blocks.size();
  int best = 0;
  for ( int n = 0; n < N; ++n )
    if ( nm & (1<<n) )
    {
      int first = -1;
      for ( int k = 0; k < N; ++k )
        if ( km & (1<<k) )
        {
          if ( first < 0 )
            first = k;
          if ( n_blocks[n] < k_blocks[k] )
            best = std::max(best, n_pointsr1(nm & ~(1<<n), km & ~(1<<k)));
        }
      for ( int k = N - 1; k >= 0; --k )
        if ( km & (1<<k) )
        {
          if ( k_blocks[k] < n_blocks[n] )
            best = std::max(best, 1 + n_pointsr1(nm & ~(1<<n), km & ~(1<<first)));
        }
    }
  np[nm][km] = best;
  return best;
}



int n_points1()
{
  int N = n_blocks.size();
  for ( int n = 0; n < 1<<N; ++n )
    for ( int k = 0; k < 1<<N; ++k )
      np[n][k] = -1;
  return n_pointsr1((1<<N)-1, (1<<N)-1);
}


int n_points2(std::deque<double> n_blocks, std::deque<double> k_blocks)
{
  int n = 0;
  while ( not n_blocks.empty() )
  {
    double x = n_blocks.front();
    n_blocks.pop_front();
    for ( size_t k = 0; k != k_blocks.size(); ++k )
      if ( k_blocks[k] > x )
      {
        k_blocks.erase(k_blocks.begin() + k);
        goto next;
      }
    k_blocks.pop_front();
    ++n;
  next:;
  }
  return n;
}
  

int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    std::cin >> N;
    n_blocks.resize(N);
    k_blocks.resize(N);
    for ( int i = 0; i < N; ++i )
      std::cin >> n_blocks[i];
    for ( int i = 0; i < N; ++i )
      std::cin >> k_blocks[i];
    std::sort(n_blocks.begin(), n_blocks.end());
    std::sort(k_blocks.begin(), k_blocks.end());
    std::cout << "Case #" << t << ": " << n_points1()
      << ' ' << n_points2(n_blocks, k_blocks) << '\n';
  }
  return 0;
}

