#include <iostream>

using namespace std;


int a[20];
long long p10[20];

long long rev(long long x)
{
	long long ans = 0;
	while (x)
	{
		ans = ans * 10 + x % 10;
		x /= 10;
	}
	return ans;
}

int main()
{
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++)
	{
		long long n;
		cin >> n;
		cout << "Case #" << tc << ": ";
		long long tmp = n;
		int dc = 0;
		while (tmp)
		{
			a[dc++] = tmp % 10;
			tmp /= 10;
		}
		if (dc == 1)
			cout << n << endl;
		else
		{	
			long long ans = 10;
			long long cur = 10;
			p10[0] = 1;
			for (int i = 1; i <= dc; i++)
				p10[i] = p10[i - 1] * 10;
			for (int i = 2; i < dc; i++)
			{
				ans += p10[i / 2] - 1 + p10[(i + 1) / 2] - 1 + 1 + 1 - 1;
				cur *= 10;
			}
			long long ans2 = n - cur;
			for (int j = dc - 1; j > 0; j--)
			{
				long long n1 = 0;
				for (int k = dc - 1; k >= j; k--)
					n1 = n1 * 10 + a[k];
				long long n2 = 0;
				for (int k = j - 1; k >= 0; k--)
					n2 = n2 * 10 + a[k];
				if (n2 > 0)
					ans2 = min(ans2, rev(n1) + 1 + n2 - 1);
				long long q = 1;
				for (int k = 0; k < j; k++)
					q *= 10;
				ans2 = min(ans2, rev(n1 - 1) + 1 + n2 + q - 1);
			}
			cout << ans + ans2 << endl;
				
		}
	}
}
