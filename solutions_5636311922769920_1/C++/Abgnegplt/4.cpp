#include <iostream>
using namespace std;

long long 
int k, c, s;
int t;
int m;
long long tmp;

long long myp(long long a, long long n)
{
	long long ans = 1;
	for (long long i = 0; i < n; ++i)
		ans *= a;
	return ans;
}

int main(int argc, char const *argv[])
{
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> k >> c >> s;

		cout << "Case #" << i+1 << ": ";

		if ( s * c < k )
			cout << "IMPOSSIBLE" << endl;
		else 
		{
			tmp = 0;
			long long x, y;
			for (x = 0, y = c - 1; x < k; ++x, --y)
			{
				tmp += x * myp(k, y);
				if (y == 0)
				{
					tmp ++;
					cout << tmp << ' ';
					tmp = 0;
					y = c;
				}
			}
			if (y < c-1)
			{
				tmp ++;
				cout << tmp << ' ';
			}
			cout << endl;
		}

	}

	return 0;
}
