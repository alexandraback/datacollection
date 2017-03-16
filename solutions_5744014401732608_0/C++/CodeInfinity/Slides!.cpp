#include <iostream>
#include <cmath>

void fun(long long M, int cnt)
{
  if ( !cnt ) return;
  fun(M >> 1, cnt - 1);
  std::cout << (M & 1);
}

int main()
{
  int T, B;
  long long M;

  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
    {
      std::cin >> B >> M;
      std::cout << "Case #" << t << ": ";

      long long max_ways = 1;
      if ( B != 1 ) max_ways = (long long)pow(2, B - 2);
      if ( max_ways < M )
	std::cout << "IMPOSSIBLE" << std::endl;
      else
	{
	  std::cout << "POSSIBLE" << std::endl;
	  if ( max_ways == M )
	    {
	      std::cout << '0';
	      for ( int j = 2; j <= B; ++j )
		std::cout << '1';
	    }
	  else
	    {
	      std::cout << '0';
	      fun(M, B - 2);
	      std::cout << '0';
	    }
	  std::cout << std::endl;
	  for ( int i = 2; i <= B; ++ i )
	    {
	      for ( int j = 0; j < i; ++j )
		std::cout << '0';
	      for ( int j = i; j < B; ++j )
		std::cout << '1';
	      std::cout << std::endl;
	    }
	}
    }
  return 0;
}
