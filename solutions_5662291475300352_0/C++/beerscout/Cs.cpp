#include <vector>
#include <iostream>


int solve(long D1, long D2, long M1, long M2)
{
  if ( M1 == M2 )
    return 0;
  long x1 = (360 - D1)*M1;
  long x2 = (360 - D2)*M2;
  if ( x1 == x2 )
    return 0;
  if ( x1 < x2 )
  {
    if ( x2 < M1*(720 - D1) )
      return 0;
    else
      return 1;
  }
  if ( x1 < M2*(720 - D2) )
    return 0;
  return 1;
}


int solve1(long D1, long D2, long M1, long M2)
{
  if ( D1 <= D2 )
    return solve(D1, D2, M1, M2);
  else
    return solve(D2, D1, M2, M1);
}



int solve2(int N)
{
  std::vector<long> D, M;
  for ( int i = 0; i < N; ++i )
  {
    long d, h, m;
    std::cin >> d >> h >> m;
    for ( int j = 0; j < h; ++j )
    {
      D.push_back(d);
      M.push_back(m + j);
    }
  }
  if ( D.size() < 2 )
    return 0;
  return solve1(D[0], D[1], M[0], M[1]);
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t=1; t <= T; ++t )
  {
    int N;
    std::cin >> N;
    int k = solve2(N);
    std::cout << "Case #" << t << ": " << k << '\n';
  }
  return 0;
}
