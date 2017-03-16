#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

fstream 	f, g;

int64_t solve(int64_t r,  int64_t t)
{
	int64_t a = 1;
	int64_t b, b1 = sqrt(t/2), b2 = t / (2*r - 1);
	int64_t m, val, good = 0;

	b = (b1 < b2) ?  b1 : b2;

	while (a <= b)
	{
		m 	= (a + b) / 2;
		val = m*(2*m + 2*r - 1);

		if (val == t) return m;

		if (val > t)
		{
			b = m - 1;
		}
		else
		{
			good = m;
			a = m + 1;
		}
	}

	return good;
}



int main()
{
	int			T;
	int64_t		r, t;

	f.open("in.txt",  ios :: in);
	g.open("out.txt", ios:: out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> r >> t;
		g << "Case #" << test << ": " << solve(r, t) << endl;
	}

	f.close();
	g.close();

	return 0;
}
