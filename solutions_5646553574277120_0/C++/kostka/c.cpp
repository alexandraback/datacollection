#include "bits/stdc++.h"

using namespace std;

bool czy[107];

void test()
{
  int c, d, v;
  cin >> c >> d >> v;
  czy[0] = 1;
  for(int i=1; i<=v; i++)
    czy[i] = 0;
  set <int> S;
  for(int i=1; i<=v; i++)
    S.insert(i);
  for(int i=0; i<d; i++)
  {
    int a;
    cin >> a;
    S.erase(a);
    for(int j=0; j<c; j++)
      for(int k=v; k>=a; k--)
        if(czy[k-a]) 
          czy[k] = 1;
  } 
  int ile = 0;
  while(true)
  {
    for(int i=1; i<=v; i++)
      if(czy[i]==0)
      {
        ile++;
        int m = i;
        S.erase(m);
        for(int j=0; j<c; j++)
          for(int k=v; k>=m; k--)
            if(czy[k-m]) 
              czy[k] = 1;
        continue;       
      }
    break;
  }
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
