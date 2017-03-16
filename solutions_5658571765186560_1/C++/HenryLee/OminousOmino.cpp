#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int t;

	cin >> t;

	for (int i=1; i<=t; i++)
	{
		int x, r, c;
		bool gabriel;

		cin >> x >> r >> c;

		gabriel = true;

		if ((r * c) % x != 0)
		{
			gabriel = false;
		}
		else if (x > max(r, c))
		{
			gabriel = false;
		}
		else if (x >= 7)
		{
			gabriel = false;
		}
		else if (x == 3)
		{
			if (min(r, c) <= 1)
				gabriel = false;
		}
		else if (x == 4)
		{
			if (min(r, c) <= 2)
				gabriel = false;
		}
		else if (x == 5)
		{
			if ((max(r, c) == 5) && (min(r, c) <= 3))
				gabriel = false;
		}
		else if (x == 6)
		{
			if (min(r, c) <= 3)
				gabriel = false;
		}

		if (gabriel)
			printf("Case #%d: GABRIEL\n", i);
		else
			printf("Case #%d: RICHARD\n", i);
	}

	return 0;
}
