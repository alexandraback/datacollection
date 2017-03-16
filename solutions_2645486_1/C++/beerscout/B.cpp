#include <algorithm>
#include <vector>
#include <iostream>


long max_nb(std::vector<long> const &v, long R, long E)
{
  std::vector<long> e(v.size());
  std::vector<long> a(v.size());
  a[0] = e[0] = E;
  long best = e[0]*v[0];
  for ( size_t i = 1; i < v.size(); ++i )
  {
    a[i] = e[i] = std::min(R, E);
    best += e[i]*v[i];
  }
  bool change = true;
  while ( change )
  {
    change = false;
    for ( size_t i = 1; i < v.size(); ++i )
    {
      if ( a[i] < E and e[i - 1] > 0 and v[i] > v[i - 1] 
          and a[i - 1] - e[i - 1] + R + 1 <= E )
      {
        long k;
        if ( a[i - 1] + R < E )
          k = e[i - 1];
        else
          k = E - a[i - 1] + e[i - 1] - R;
        long na = std::min(a[i - 1] - e[i - 1] + R + k, E);
        if ( na > a[i] )
        {
          a[i] = na;
          e[i - 1] -= k;
          e[i] += k;
          best += k*(v[i] - v[i - 1]);
          change = true;
        }
      }
    }
  }
  return best;
}



int main()
{
  long T;
  std::cin >> T;
  for ( long t = 1; t <= T; ++t )
  {
    long R, E, N;
    std::cin >> E >> R >> N;
    std::vector<long> v(N);
    for ( long i = 0; i < N; ++i )
      std::cin >> v[i];
    std::cout << "Case #" << t << ": " << max_nb(v, R, E) << std::endl;
  }
  return 0;
}
