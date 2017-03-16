#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long r, t;

bool check(long long y)
{
	return (y * (2 * r + 1) + 2 * y * (y - 1) <= t);
}

int main()
{
	long long x, a, b, y, tt;
	
	cin >> tt;
	for (x = 1; x <= tt; ++x)
	{
		cin >> r >> t;
		a = 1;
		b = min((long long)sqrt(t + 1) + 1, t / (2 * r + 1) + 1);
		while (a + 1 < b)
		{
			y = (a + b) / 2;
			if (check(y))
				a = y;
			else
				b = y;
		}
		cout << "Case #" << x << ": " << a << endl;
	}

	return 0;
}
