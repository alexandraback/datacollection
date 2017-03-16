
#include "bind.h"
#include <algorithm>
using namespace std;

int main()
{
	bind("B-large");
	int t, n, s, p;
	inf >> t;
	for (int k = 0; k < t; k++)
	{
		inf >> n >> s >> p;
		int judge = p * 3 - 3, number = 0;
		for (int i = 0; i < n; i++)
		{
			int c;
			inf >> c;
			if (p <= 1)
			{
				if (c >= p)
					number++;
			}
			else
			{
				if (c > judge)
					number++;
				else
					if (c >= judge - 1 && s > 0)
						number++, s--;
			}
		}
		ouf << "Case #" << k + 1 << ":" << " " << number << "\n";
	}
}
