#include <bits/stdc++.h>
using namespace std;

int n;

int match(int x, string s)
{
  for (int i = s.size() - 1; i >= 0; i--)
  {
    int d = x % 10;
    x /= 10;
    if (s[i] != '?' && s[i] != char('0' + d))
      return 0;
  }
  return 1;
}

int len(long long x)
{
  return x < 10 ? 1 : len(x / 10) + 1;
}

void write(long long x)
{
  for (int i = len(x); i < n; i++)
    cout << 0;
  cout << x;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test, p[4] = {0, 10, 100, 1000};
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << "Running test " << iTest << "..." << endl;
    string a, b;
    int x = 1 << 30, y = 0;
    cin >> a >> b;
    n = a.size();
    for (int i = 0; i < p[n]; i++)
      if (match(i, a))
        for (int j = 0; j < p[n]; j++)
          if (match(j, b))
          {
            if (abs(i - j) < abs(x - y))
              x = i, y = j;
          }
    cout << "Case #" << iTest << ": ";
    write(x); cout << ' ';
    write(y); cout << endl;
  }
}