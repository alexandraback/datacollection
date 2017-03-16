#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		double c, f, x, r = 2.0, b, q = 0.0;

		printf("Case #%d: ", i);
		cin >> c >> f >> x;
		b = x / r;

		for (int i = 0; i < 10000000; i++)
		{
			q += c / r;
			r += f;
			if (b > q + x / r)
				b = q + x / r;
		}
		printf("%.7f\n", b);
		
	}
}