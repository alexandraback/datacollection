#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;

double v[2][1004];

void solve()
{
  int k1=0, k2=0;
  sort(v[0], v[0]+n);
  sort(v[1], v[1]+n);
  int l=0, r=n-1;
  for (int i=n-1; i>=0; i--) {
    if (v[1][i] > v[0][r]){k2++;l++;}
    else r--;
  }
  l=0; r=n-1;
  for (int i=0; i<n; i++) {
    if (v[1][i] > v[0][l]){
      k1++;
      l++;
    } else {
      r--;
    }

  }
  cout << k1 << " " << k2 << "\n";
}

int main()
{
  int t;
  cin >> t;
  for (int i=1; i<=t; i++) {
    cin >> n;
    for (int j=0; j<2; j++)
      for(int i=0; i<n; i++)cin>>v[1-j][i];

    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
