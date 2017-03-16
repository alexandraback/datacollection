#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int T; cin >> T;
  for (int t=0; t<T; t++)
  {
    cout << "Case #" << t+1 << ":";
    
    vector<bool> c(2501, false);
    int n; cin >> n;
    for (int i = 0; i < 2*n-1; i++)
    {
      for (int k = 0; k < n; k++)
      {
        int v; cin >> v;
        c[v] = !c[v];
      }
    }
    
    for (int i = 1; i < c.size(); i++)
    {
      if (c[i]) cout << " " << i;
    }
    cout << endl;
  }
  return 0;
}