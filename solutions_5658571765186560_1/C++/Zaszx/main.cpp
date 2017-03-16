#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int T, X, R, C;

int main(void)
{
	scanf(" %d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf(" %d %d %d", &X, &R, &C);

		bool result = true;

		int min = R > C ? C : R;
		int max = R > C ? R : C;

		if (R < X && C < X)
		{
			result = false;
		}
		else if (R * C % X != 0)
		{
			result = false;
		}
		else if ((X + 1) / 2 > min)
		{
			result = false;
		}
		else if (X == 4)
		{
			if (min <= 2)
			{
				result = false;
			}
		}
		else if (X == 5)
		{
			if ((R == 3 && C == 5) || (R == 5 && C == 3))
			{
				result = false;
			}
		}
		else if (X == 6)
		{
			if (min <= 3)
			{
				result = false;
			}
		}
		else if (X >= 7)
		{
			result = false;
		}

		printf("Case #%d: %s\n", i, result ? "GABRIEL" : "RICHARD");
	}
}