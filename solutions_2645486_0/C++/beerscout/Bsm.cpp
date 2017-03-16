#include <algorithm>
#include <vector>
#include <iostream>


int max_brute(std::vector<int> const &v, 
    std::vector<int> &r, int R, int E, int current, size_t st)
{
  if ( st >= v.size() )
  {
    int gain = 0;
    for ( size_t i = 0; i != v.size(); ++i )
      gain += v[i]*r[i];
    return gain;
  }
  int best = 0;
  for ( int spent = 0; spent <= current; ++spent )
  {
    r[st] = spent;
    best = std::max(best, max_brute(v, r, R, E, std::min(current - spent + R, E), st + 1));
  }
  return best;
}



int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int R, E, N;
    std::cin >> E >> R >> N;
    std::vector<int> v(N), r(N);
    for ( int i = 0; i < N; ++i )
      std::cin >> v[i];
    std::cout << "Case #" << t << ": " << max_brute(v, r, R, E, E, 0) << std::endl;
  }
  return 0;
}
