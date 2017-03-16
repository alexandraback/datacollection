#include <bits/stdc++.h>
using namespace std;

int f[1000100], tr[1000100];

int rev(int x)
{
  int a[10], l = 0;
  while (x)
  {
    a[l++] = x % 10;
    x /= 10;
  }
  for (int i = 0; i < l; i++)
    x = x * 10 + a[i];
  return x;
}

int main()
{
  f[1] = 1;
  for (int i = 2; i <= 1000000; i++)
  {
    int j = rev(i);
    f[i] = f[i - 1] + 1;
    tr[i] = i - 1;
    if (rev(j) == i && j < i && f[j] + 1 < f[i])
    {
      f[i] = f[j] + 1;
      tr[i] = j;
    }
  }
  
  
  ios::sync_with_stdio(0);
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout);
	int test;
  long long n;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cerr << "Running test " << noTest << endl;
    cin >> n;
		printf("Case #%d: %d\n", noTest, f[n]);
	}
}
