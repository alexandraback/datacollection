#include <iostream>


long cases(int A, int B, int K)
{
  long g = 0;
  for ( int a = 0; a < A; ++a )
    for ( int b = 0; b < B; ++b )
      if ( (a&b) < K )
        ++g;
  return g;
}


long solve()
{
  int A, B, K;
  std::cin >> A >> B >> K;
  return cases(A, B, K);
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    long x = solve();
    std::cout << "Case #" << t << ": " << x << '\n';
  }
  return 0;
}
