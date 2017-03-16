#include <iostream>
#include <deque>
#include <algorithm>


int n_points1(std::deque<double> n_blocks, std::deque<double> k_blocks)
{
  int n = 0;
  while ( not n_blocks.empty() )
  {
    if ( n_blocks.front() > k_blocks.front() )
    {
      ++n;
      k_blocks.pop_front();
      n_blocks.pop_front();
    }
    else
    {
      k_blocks.pop_back();
      n_blocks.pop_front();
    }
  }
  return n;
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
  std::deque<double> n_blocks, k_blocks;
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
    std::cout << "Case #" << t << ": " << n_points1(n_blocks, k_blocks)
      << ' ' << n_points2(n_blocks, k_blocks) << '\n';
  }
  return 0;
}

