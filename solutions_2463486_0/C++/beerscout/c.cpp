#include <cmath>
#include <iostream>

unsigned long xpow10(unsigned x)
{
  unsigned long r = 1;
  while ( x-- > 0 )
  {
    r *= 10;
  }
  return r;
}


int digits(unsigned long A)
{
  if ( A == 0 )
    return 1;
  int r = 0;
  while ( A > 0 )
  {
    ++r;
    A /= 10;
  }
  return r;
}


bool good(unsigned long X)
{
  if ( X == 0 )
    return true;
  char d[20];
  int i = 0;
  while ( X > 0 )
  {
    d[i++] = X%10;
    X /= 10;
  }
  for ( int j = 0; j < i/2; ++j )
    if ( d[j] != d[i - 1 - j] )
      return false;
  return true;
}


unsigned long makep(unsigned long X)
{
  unsigned long Y = X;
  unsigned long r = 0;
  unsigned sc = 1;
  while ( Y > 0 )
  {
    r *= 10;
    r += Y%10;
    Y /= 10;
    sc *= 10;
  }
  return X*sc + r;
}


unsigned long makep_odd(unsigned long X)
{
  unsigned long Y = X/10;
  unsigned long r = 0;
  unsigned sc = 1;
  while ( Y > 0 )
  {
    r *= 10;
    r += Y%10;
    Y /= 10;
    sc *= 10;
  }
  return X*sc + r;
}


int count_even(unsigned long A, unsigned long B, int n_digits)
{
  unsigned long lb = xpow10(n_digits/2 - 1);
  unsigned long ub = lb*10 - 1;
  int r = 0;
  for ( unsigned long i = lb; i <= ub; ++i )
  {
    unsigned long x = makep(i);
    unsigned long y = x*x;
    if ( A <= y && y <= B && good(y) )
    {
      r += 1;
    }
  }
  return r;
}


int count_odd(unsigned long A, unsigned long B, int n_digits)
{
  unsigned long lb = xpow10(n_digits/2);
  unsigned long ub = lb*10 - 1;
  int r = 0;
  for ( unsigned long i = lb; i <= ub; ++i )
  {
    unsigned long x = makep_odd(i);
    unsigned long y = x*x;
    if ( A <= y && y <= B && good(y) )
    {
      r += 1;
    }
  }
  return r;
}




int count_all(unsigned long A, unsigned long B)
{
  int A1 = int(std::sqrt(A));
  int B1 = int(std::sqrt(B)) + 1;
  int dA = digits(A1);
  int dB = digits(B1);
  int r = 0;
  for ( int d = dA; d <= dB; ++d )
  {
    if ( d%2 == 0 )
      r += count_even(A, B, d);
    else
      r += count_odd(A, B, d);
  }
  return r;
}


void run(int no)
{
  unsigned long A, B;
  std::cin >> A >> B;
  std::cout << "Case #" << no << ": " << count_all(A, B) << std::endl;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
    run(t);
  return 0;
}
