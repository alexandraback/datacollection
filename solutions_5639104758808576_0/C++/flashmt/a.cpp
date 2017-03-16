#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
    int n, ans = 0;
    string s;
		cin >> n >> s;
    for (int i = 0, sum = 0; i <= n; i++)
    {
      if (sum < i) 
      {
        ans += i - sum;
        sum = i;
      }
      sum += s[i] - '0';
    }
		printf("Case #%d: %d\n", noTest, ans);
	}
}
