#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#include <boost/math/distributions/binomial.hpp>

void solve()
{
  uint n;
  int x, y;
  cin >> n >> x >> y;

  x = abs(x);
  int pos_layer = (x + y) / 2;
  
  double delta = 1 + 8 * n;
  double root = (1.0 + sqrt(delta)) / 4.0 - 1.0;
  int layer = root;
  int next_layer = layer + 1;
  int rem_diamonds = n - (2 * next_layer * next_layer - next_layer);
  
  if(pos_layer <= layer)
  {
    cout << 1.0;
  }
  else if(rem_diamonds > 0 && pos_layer <= next_layer)
  {
    int side = 2 * next_layer;
    if(y >= side || y >= rem_diamonds)
    {
      cout << 0.0;
      return;
    }
    
    cout << cdf(complement(boost::math::binomial(rem_diamonds, 0.5), y));
  }
  else
  {
    cout << 0.0;
  }
}

int main(int argc, char *argv[])
{
  int N;
  cin >> N;

  cout.precision(7);
  cout << showpoint;
  for(int i = 1; i <= N; i++)
  {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
  
  return 0;
}


