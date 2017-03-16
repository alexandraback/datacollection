#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

long rev(long x)
{
	long r = 0;
	while(x)
	{
		r *= 10;
		r += x%10;
		x /= 10;
	}
	return r;
}

int dig(long x)
{
	return (int)log10((double)x) + 1;
}

int ld(long x)
{
	return x / pow(10, dig(x)-1);
}

long say(long n)
{
	long r = 0;
	long cur = 0;
	long revn = rev(n);
	if (n < 10)
	{
		return n;
	}
	while(cur < n)
	{
		if (dig(cur) == dig(n))
		{
			if (ld(cur) == ld(n))
			{
				return r + n - cur;
			}
			else
			{
				long a = 0;
				long b = 0;
				int x = ld(n) - (cur%10);
				if (x < 0)
					x += 10;
				if (rev(cur+x) > n)
				{
					a = LONG_MAX;
				}
				else
				{
					a = x + 1 + n - rev(cur+x);
				}
				x = (n%10) - (cur%10);
				if (x < 0)
					x += 10;
				if (rev(cur+x) > revn)
				{
					b = LONG_MAX;
				}
				else
				{
					b = x + 1 + revn - rev(cur+x) + 1;
				}
				return r+min(a, b);
			}
		}
		else
		{
			if (cur < 10)
			{
				cur += 10;
				r += 10;
				continue;
			}
			r += 10 - (cur % 10);
			cur = rev(cur / 10 * 10 + 9);
			long tmp = (long)pow(double(10), (double)dig(cur));
			r += tmp - cur;
			cur = tmp;
		}
	}
	return min(r, n);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	for (int c = 1; c <= t; ++c)
	{
		long n;
		cin >> n;
		cout << "Case #" << c << ": " << say(n) << endl;
	}
	return 0;
}