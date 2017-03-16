#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main()
{
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; i++)
  {
    ull b;
    ull m;
  
    cin >> b >> m;
    
    cout << "Case #" << i << ": ";
    
    ull max = 1ULL << (b - 2);
    
    if (m > max)
      cout << "IMPOSSIBLE" << endl;
    else
    {
      cout << "POSSIBLE" << endl;
    
      vector<int> v(b, 0);
      
      v[b - 1] = 1;
      m--;
      
      int j = b - 2;

      while (m > 0)
      {
        if (m & 1)
          v[j] = 1;
        m = m / 2;
        j--;
      }
      
      for (int k = 0; k < b; k++)
        cout << v[k];
      cout << endl;
      
      for (int l = 1; l < b; l++)
      {
        for (int k = 0; k < b; k++)
          if (k <= l)
            cout << '0';
          else
            cout << '1';
        cout << endl;
      }
    }
  }
  
  return 0;
}
