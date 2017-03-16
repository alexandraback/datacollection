#include <iostream>
#include <set>

int ndigits(unsigned x)
{
  int n = 0;
  while ( x > 0 )
  {
    x /= 10;
    ++n;
  }
  return n;
}


unsigned pow10[] = {1U, 10U, 100U, 1000U, 10000U, 100000U, 1000000U, 10000000U, 100000000U, 1000000000U };


int pairs(unsigned B, unsigned cand)
{
  std::set<unsigned> tried;
  int N = ndigits(B);
  unsigned other = cand;
  for ( int i = 0; i < N - 1; ++i )
  {
    other = (other%10)*pow10[N - 1] + (other/10);
    if ( other > cand and other <= B and
      tried.find(other) == tried.end() )
    {
      tried.insert(other);
    }
  }
  return tried.size();
}


long npairs(unsigned A, unsigned B)
{
  long res = 0;
  for ( unsigned cand = A; cand <= B; ++cand )
    res += pairs(B, cand);
  return res;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    std::cout << "Case #" << t << ": ";
    unsigned A, B;
    std::cin >> A >> B;
    std::cout << npairs(A, B) << '\n';
  }
  return 0;
}
