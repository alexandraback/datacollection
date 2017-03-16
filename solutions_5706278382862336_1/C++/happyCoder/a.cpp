#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
  while (b)
  {
    long long t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int log2(long long x)
{
  int r = 0;
  while (x >>= 1) ++r;
  return r;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    char c;
    long long P, Q;
    cin >> P >> c >> Q;
    
    cout << "Case #" << i << ": "; 
    
    long long x = gcd(P, Q);
    P /= x;
    Q /= x;
    
    if (Q & (Q-1))
      cout << "impossible" << endl;
    else
      cout << log2(Q)-log2(P) << endl;
    
  }
  return 0;
}
