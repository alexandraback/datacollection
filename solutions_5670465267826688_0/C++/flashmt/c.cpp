#include <bits/stdc++.h>
using namespace std;

int n, m, l[50100], r[50100];
string s;

int mult(int x, int y)
{
  int sign = (x < 0) ^ (y < 0) ? -1 : 1;
  x = abs(x);
  y = abs(y);
  if (x == 1) return y * sign;
  if (y == 1) return x * sign;
  if (x == y) return -1 * sign;
  if ((x - 1) % 3 == (y - 2) % 3) return (9 - x - y) * sign;
  return (x + y - 9) * sign ;
}

int power(int x, long long y)
{
  if (!y) return 1;
  int res = power(x, y / 2);
  res = mult(res, res);
  if (y % 2) res = mult(res, x);
  return res;
}

int check(int prefix, int suffix)
{
  int x = 1, y = 1, z = 1;
  for (int i = 0; i < prefix; i++) x = mult(x, s[i % n] - 'i' + 2);
  for (int i = 0; i < n * m - prefix - suffix; i++) y = mult(y, s[(prefix + i) % n] - 'i' + 2);
  for (int i = 0; i < suffix; i++) z = mult(z, s[(m * n - suffix + i) % n] - 'i' + 2);
  return x == 2 && y == 3 && z == 4;
}

int main()
{
	freopen("c.in", "r", stdin); 
	freopen("c.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cin >> n >> m >> s;
    
    l[0] = r[0] = 1;
    long long firstL = m * n + 1, firstR = firstL;
    for (int i = 0; i < n * 5; i++)
    {
      l[i + 1] = mult(l[i], s[i % n] - 'i' + 2);
      if (l[i + 1] == 2) firstL = min(firstL, i + 1LL);
      r[i + 1] = mult(s[(n * 3 - 1 - i) % n] - 'i' + 2, r[i]);
      if (r[i + 1] == 4) firstR = min(firstR, i + 1LL);
    }
    
		printf("Case #%d: ", noTest);
    if (power(l[n], m) == -1 && firstL + firstR < m * n)
    {
      assert(check(firstL, firstR) == 1);
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
	}
}
