#include "bits/stdc++.h"

using namespace std;

void test()
{
  int r, c, w;
  cin >> r >> c >> w;
  int ile = r*ceil(1.0*c/w) + (w-1);
  cout << ile;
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
  {
    cout << "Case #" << tti << ": ";
    test();
    cout << "\n";
  }
}
