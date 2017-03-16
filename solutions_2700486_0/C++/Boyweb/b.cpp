#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

double C(long n, long m)
{
	double r = 1;
	for (int i = n - m + 1; i <= n; i++)
	{
		r *= i;
	}
	for (int i = 1; i <= m; i++)
	{
		r /= i;
	}

	return r;
}

int main()
{
	std::ifstream fin("B-small-attempt1.in");
	std::ofstream fout("out.txt");

	int t;
	fin >>t;
	for (int i = 1; i <= t; i++)
	{
		long n, x, y;
		fin >>n >>x >>y;
		
		long layer = (std::abs(x) + y) / 2 + 1;
		long nL = ((layer - 1) * 2 - 1) * (layer - 1);
		long nN = (layer - 1) * 2 + 3;
		long nY = layer * 2 - 1 + y;

		double p = 0.0;

		if (n >= nL + nY)
		{
			p = 1.0;
		}
		else if (n < nL + y + 1 && y < layer)
		{
			p = 0.0;
		}
		else if (y == layer && n < nL + nN)
		{
			p = 0.0;
		}
		else
		{
			long more = n - nL;
			if (more > layer + 1)
			{
				for (int j = y + 1; j <= layer + 1 ; j++)
				{
					p += C(more, j) / (double)std::pow(2, more);
				}
			}
			else
			{
				for (int j = y + 1; j <= more ; j++)
				{
					p += C(more, j) / (double)std::pow(2, more);
				}
			}
		}

		fout <<"Case #" <<i <<": " <<std::showpoint <<p <<std::endl;
	}

	return 0;
}