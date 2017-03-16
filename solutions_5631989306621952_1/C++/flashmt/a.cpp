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
    string s, ans = "";
    cin >> s;
    for (auto c : s)
    {
      string t = ans, u = ans;
      t.insert(0, 1, c);
      u += c;
      ans = max(t, u);
    }
    cout << "Case #" << iTest << ": " << ans << endl;
  }
}