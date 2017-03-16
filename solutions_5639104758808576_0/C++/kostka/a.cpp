#include "bits/stdc++.h"

using namespace std;

long long test()
{
  int n;
  cin >> n;
  string x;
  cin >> x;
  long long ile = 0, res = 0;
  for(int i=0; i<=n; i++)
  {
    if(ile < i)
    {
      res += i-ile;
      ile += i-ile;
    }
    ile += x[i]-'0';
  }
  return res;
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
    cout << "Case #" << tti << ": " << test() << "\n";
}
