#include <iostream>
#include <cmath>

using namespace std;

long gcd(long a, long b)
{
	if(a == 0)
	{
		return b;
	}
	return (gcd((b % a), a));
}

int main()
{
	int cases;
	cin >> cases;

	for(int i = 0; i < cases; i++)
	{
		long a, b, gcd_ab;
		char tmpchar;
		cin >> a;
		cin >> tmpchar;
		cin >> b;
		if (a == 0 || b == 0)
		{
			cout << "Case #" << (i + 1) << ": impossible" << endl;
			continue;
		}

		gcd_ab = gcd(a, b);
		a /= gcd_ab;
		b /= gcd_ab;

		if ((b & (b - 1)) != 0)
		{
			cout << "Case #" << (i + 1) << ": impossible" << endl;
			continue;
		}
		
		long count = 0;
		while(a >>= 1)
		{
			count++;
		}

		b /= pow(2, count);

		count = 0;
		while(b >>= 1)
		{
			count++;
		}

		cout << "Case #" << (i + 1) << ": " << count << endl;
	}
	return 0;
}
