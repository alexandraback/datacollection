#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void solve(vector<ull> & v, int k, int c)
{
  int pos = k - 1;
  
  while (pos >= 0)
  {
    ull n = 0;
    for (int i = 0; i < c; i++)
    {
      n = k * n + (pos >= 0 ? pos : 0);
      pos--;
    }
    v.push_back(n + 1);
  }
}

int main()
{
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; i++)
  {
    int k, c, s;
    cin >> k >> c >> s;
    cout << "Case #" << i << ": ";
    if (s < (k + c - 1) / c)
      cout << "IMPOSSIBLE";
    else
    {
      vector<ull> v;
      solve(v, k, c);
      cout << v[0];
      for (int i = 1; i < v.size(); i++)
        cout << " " << v[i];
    }
    cout << endl;
  }
  
  return 0;
}
