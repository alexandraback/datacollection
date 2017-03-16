// ProblemA.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iostream>

using namespace std;

int count (long long p, long long q)
{
	int cnt = 0;
	while (p < q)
	{
		p *= 2;
		cnt++;
	}
	return cnt;
}

int check(long long p, long long q)
{
	int res = count(p, q);

	int cnt = 0;
	while ((cnt <= 40) && (p > 0))
	{
		long long x = 1;
		while (p < q)
		{
			p = p*2;
			x = x*2;
			cnt++;
		}
		p = (p - q) / x;
		q = q / x;
	}
	if (cnt > 40)
		return -1;
	return res;
}

int main()
{
	ifstream fi("A-large.in");
	ofstream fo("a.out");

	int t;
	fi >> t;

	for(int i = 0; i < t; i++)
	{
		char c;
		long long p,q;
		fi >> p >> c >> q;

		fo << "Case #" << i+1 << ": ";

		bool is_correct = true;
		long long x = q;
		while (x > 1)
		{
			if (x % 2 != 0)
			{
				if (p % x == 0)
				{
					p = p / x;
					q = q / x;
				}
				else
				{
				    is_correct = false;
				}
				break;
			}
			x = x/2;
		}

		if (!is_correct)
		{
			fo << "impossible" << endl;
		}
		else
		{
			int count = check(p, q);
			if (count < 0)
			{
				fo << "impossible" << endl;
			}
			else 
			{
				fo << count << endl;
			}
		}
	}

	fi.close();
	fo.close();

	return 0;
}

