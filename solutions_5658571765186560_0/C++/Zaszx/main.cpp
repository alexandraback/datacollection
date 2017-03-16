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

		bool result = false;

		if (X == 1)
		{
			result = true;
		}
		else if (X == 2)
		{
			if ((R * C) % 2 == 0)
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
		else if (X == 3)
		{
			if (R > 1 && C > 1 && (R * C) % 3 == 0 )
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}
		else if (X == 4)
		{
			if (R > 2 && C > 2  && ((R * C) % 4 == 0))
			{
				result = true;
			}
			else
			{
				result = false;
			}
		}

		printf("Case #%d: %s\n", i, result ? "GABRIEL" : "RICHARD");
	}
}