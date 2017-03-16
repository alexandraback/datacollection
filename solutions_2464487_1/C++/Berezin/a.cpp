#include <iostream>
#include <fstream>

using namespace std;

long long rr, tt, T, l, r, s, x, t;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cout << "Case #" << test << ": ";
		cin >> rr >> t;
		l = 1;
		r = 1000000000;
		if (r > 2000000000000000000 / (rr))
			r = 2000000000000000000 / (rr);
		while (l < r)
		{
			s = (l + r) / 2;
			long long k = 2*s*s+2*s*(rr - 1) + s;
			long long k1 = 2*(s - 1)*(s -1) + 2*(s-1)*(rr - 1) + s - 1;
			long long k2 = 2*(s + 1)*(s +1) + 2*(s+1)*(rr - 1) + s + 1;
			if (t >= k)
				if (s == r || t < k2)
				{
					l = r = s;
					break;
				}
				else
					l = s + 1;
			else
				if (t>=k1)
				{
					l = r = s - 1;
					break;
				}
				else
					r = s -1;
		}
		cout << l<< endl;
	}

}