#include <cmath>
#include <iostream>
using namespace std;

int m[1000001];

int rev(int n)
{
  int r = 0;
  while(n != 0)
    r = r * 10 + n % 10, n /= 10;
    
  return r;
}

int main()
{
  m[1] = 1;
  for(int i = 2, r, rr; i < 1000001; ++i)
  {
    r = rev(i);
    rr = rev(r);
    
    if(r < i && i == rr)
      m[i] = min(m[i - 1], m[r]) + 1;
    else
      m[i] = m[i - 1] + 1;
  }
    
  int Case;
  cin >> Case;
  
  int N;
  for(int c = 1; c <= Case; ++c)
  {
    cin >> N;
    cout << "Case #" << c << ": " << m[N] << endl;
  }
    
  return 0;
}
