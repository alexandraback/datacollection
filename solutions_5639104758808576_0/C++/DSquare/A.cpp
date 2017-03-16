#include<iostream>
#include<sstream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int friends = 0;
    int smax;
    cin >> smax;
    
    int ac = 0;
    for (int k = 0; k < smax + 1; ++k)
    {
      char c;
      cin >> c;
      int np = c - '0';
      
      if (friends + ac < k) friends = k - ac;
      ac += np;
    }
    cout << "Case #" << t << ": " << friends << endl;
  }
  
  return 0;
}