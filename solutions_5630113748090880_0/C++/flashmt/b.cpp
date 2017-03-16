#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << "Running test " << iTest << "..." << endl;
    int n, x, cnt[2555] = {0};
    cin >> n;
    for (int i = 0; i < (2 * n - 1) * n; i++)
    {
      cin >> x;
      cnt[x] ^= 1;
    }
    cout << "Case #" << iTest << ":";
    for (int i = 1; i <= 2500; i++)
      if (cnt[i])
        cout << ' ' << i;
    cout << endl;
  }
}