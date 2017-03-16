#include <iostream>

using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ": ";
    
    int b; long long m; cin >> b >> m;
    long long one = 1;
    long long rest = 0;
    bool print = true;
    if ((one << (b-2)) < m)
    {
      cout << "IMPOSSIBLE" << endl;
      print = false;
    }
    else if ((one << (b-2)) == m)
    {
      cout << "POSSIBLE" << endl;
      rest = 2 * m - 1;
    }
    else
    {
      cout << "POSSIBLE" << endl;
      rest = 2 * m;
    }
    
    if (print)
    {
      for (int i = 0; i < b; i++)
      {
        for (int k = 0; k <= i; k++)
        {
          cout << "0"; 
        }
        for (int k = i+1; k < b-1; k++)
        {
          cout << "1"; 
        }
        if (i < b-1) 
        {
          cout << (rest & (one << i) ? "1" : "0"); 
        }
        cout << endl;
      }
    }
  }
  return 0;
}