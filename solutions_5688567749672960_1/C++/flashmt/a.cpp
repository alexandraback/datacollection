#include <bits/stdc++.h>
using namespace std;

long long p[15];

long long rev(long long x)
{
  int a[20], l = 0;
  while (x)
  {
    a[l++] = x % 10;
    x /= 10;
  }
  for (int i = 0; i < l; i++)
    x = x * 10 + a[i];
  return x;
}

int getLen(long long x)
{
  return x < 10 ? 1 : getLen(x / 10) + 1;
}

int main()
{
  p[0] = 1;
  for (int i = 1; i <= 14; i++) p[i] = p[i - 1] * 10;
  
	freopen("a-large.in", "r", stdin); 
  freopen("a-large.out", "w", stdout);
	int test;
  long long n;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cerr << "Running test " << noTest << endl;
    cin >> n;
    long long ans = 0;
    
    while (1)
    {
      if (n <= 20) 
      {
        ans += n;
        break;
      }
      
      int l = getLen(n);
      long long target = n - n % p[(l + 1) / 2] + 1;
      if (rev(target) >= target || target > n)
      {
        target -= p[(l + 1) / 2];
        if (getLen(target) < l)
          target = p[l - 1] - p[l / 2] + 1;
      }

      ans += n - target;
      n = target;
      if (rev(n) < n)
      {
        n = rev(n);
        ans++;
      }
    }
    cout << "Case #" << noTest << ": " << ans << endl;
	}
}
