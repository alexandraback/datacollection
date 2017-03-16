#include <iostream>


long gcd(long a, long b)
{
  while ( b>0 )
  {
    long r = a % b;
    a = b; b = r;
  }
  return a;
}


int which_p2(long q)
{
  long p2 = 1;
  for ( int i = 0; i <= 41; ++i )
  {
    if ( q == p2 )
      return i;
    p2 *= 2;
  }
  return -1;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    char c;
    long p, q;
    std::cin >> p >> c >> q;
    long g = gcd(p, q);
    q /= g;
    p /= g;
    int p2 = which_p2(q);
    if ( p2 <= 0 )
    {
      std::cout << "Case #" << t << ": impossible\n";
    }
    else
    {
      int k = 1;
      while ( p2 > 0 )
      {
        long m = 1UL<<(p2 - 1);
        if ( p & m )
          break;
        --p2;
        ++k;
      }
      if ( p2 == 0 or k > 40 )
      {
        std::cout << "Case #" << t << ": impossible\n";
      }
      else
      {
        std::cout << "Case #" << t << ": " << k << '\n';
      }
    }
  }
  return 0;
}
