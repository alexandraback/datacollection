#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool c(long long i)
{
	long long a = i, b = 0;
	
	while (a > 0)
	{
		b = b * 10 + a % 10;
		a = a / 10;
	}
	if (b == i)
		return true;
	else
		return false;
}

int main()
{
	long long t, i, j, a, b, tt, r;

	cin >> t;
	for (tt = 1; tt <= t; ++tt)
	{
		cin >> a >> b;
//		cout << a << endl;
		r = 0;
		j = sqrt(b);
		i = sqrt(a);
		if (i * i < a)
			++i;
		for (; i <= j; ++i)
		{
			if (c(i))
				if (c(i*i))
				{
					r++;
//					cout << i * i << endl;
				}
			if (i % 10 > 3)
				i += 9 - (i % 10);
			if (i % 100 > 22)
				i += 99 - (i % 100);
		}
//		cout << b << endl;
		cout << "Case #" << tt << ": " << r << endl;
	}

	return 0;
}
