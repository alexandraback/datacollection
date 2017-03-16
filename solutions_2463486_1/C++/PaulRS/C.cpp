#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long A, B;

long long good(long long x)
{
	long long y = x * x;
	if ( y < A || y > B)	return 0;
	vector <int> d;
	while (y > 0)
		d.push_back(y % 10), y /= 10;
	for (int i = 0; i < d.size() / 2; i++)
		if ( d[i] != d[d.size()-1-i])
			return 0;
	return 1;
}

int main(void)
{
	int T; 
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cin >> A >> B;
		long long ans = 0;
		for (int a = 1; a <= 9; a++)
		{
			long long R = a + 10 * a;
			long long S = a;
			ans += good(R) + good(S);
			for (int b = 0; b <= 9; b++)
			{
				long long X = a + 10 * b + 100 * b + 1000 * a;
				long long Y = a + 10 * b + 100 * a;
				ans += good(X) + good(Y);
				for (int c = 0; c <= 9; c++)
				{
					long long p = a  + 10 *b + 100 *c + 1000 * c + 10000 * b + 100000 * a;
					long long q = a  + 10 *b + 100 *c + 1000 * b + 10000 * a;
					ans += good(p) + good(q);
					for (int d = 0; d <= 9; d++)
					{
						long long t = a  + 10ll *b + 100ll *c + 1000ll * d + 10000ll * c + 100000ll * b + 1000000ll * a;
						ans += good(t);
					}
				}
			}
		}
		cout << "Case #" << C << ": " << ans << endl;
	}
	return 0;
}
