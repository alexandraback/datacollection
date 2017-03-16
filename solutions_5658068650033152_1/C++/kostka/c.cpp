#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int ttt;
  cin >> ttt;
  for(int tti=1; tti<=ttt; tti++)
  {
    cout << "Case #" << tti << ": "; 
    int m, n, k;
    cin >> n >> m >> k;
    int wyn = k;
    for(int i=3; i<=n; i++)
      for(int j=3; j<=m; j++)
      {
        int kam = i*j-4;
        int obw = (i-2)*2 + (j-2)*2;
        int poz = max(0,k-kam);
        if(obw+poz < wyn)
          wyn = obw+poz;
        if((kam-k >= 2) && ((obw+poz-1) < wyn))
          wyn = obw+poz-1;
      }
    cout << wyn << "\n";
  }
}