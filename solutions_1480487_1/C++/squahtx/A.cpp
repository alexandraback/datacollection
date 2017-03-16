#include <algorithm>
#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdlib.h>
#include <string>

unsigned int n;
double scores [200];
double sortedscores [200];
double totalscore;

double fractionbelow (double exclude, double limit)
{
	double sumbelow = 0;
	bool excluded = false;
	for (unsigned int i = 0; i < n; i++)
	{
		double score = sortedscores [i];
		if (score == exclude && !excluded) { excluded = true; continue; }
		if (score >= limit) { break; }
		sumbelow += limit - score;
	}
	return sumbelow / totalscore;
}

int main ()
{
	std::ifstream in ("a.in");
	std::ofstream out ("a.out");
	out.precision (10);

	unsigned int tests;
	in >> tests;

	for (unsigned int i = 0; i < tests; i++)
	{
		in >> n;

		totalscore = 0;
		for (unsigned int j = 0; j < n; j++)
		{
			in >> scores [j];
			sortedscores [j] = scores [j];
			totalscore += scores [j];
		}

		std::sort (sortedscores, sortedscores + n);

		out << "Case #" << (i + 1) << ":";

		for (unsigned int j = 0; j < n; j++)
		{
			double score = scores [j];
			double min = 0;
			double max = 1;
			
			double adjscorelow = score;
			double frlow = fractionbelow (score, adjscorelow);
			double adjscorehigh = score + totalscore;
			double frhigh = fractionbelow (score, adjscorehigh);
			double adjscoremid = (adjscorelow + adjscorehigh) / 2;
			double frmid = fractionbelow (score, adjscoremid);
			while (max - min > 0.00000001)
			{
				double mid = (max + min) / 2;
				adjscoremid = score + totalscore * mid;
				frmid = fractionbelow (score, adjscoremid);

				if (frlow + min >= 1)
				{
					max = min;
				}
				else if (frmid + mid >= 1)
				{
					// 1st half
					max = mid;
					frhigh = frmid;
				}
				else if (frhigh + max >= 1)
				{
					// 2nd half
					min = mid;
					frlow = frmid;
				}
			}

			out << " " << (max + min) / 2 * 100;
		}

		out << std::endl;
	}

	return 0;
}