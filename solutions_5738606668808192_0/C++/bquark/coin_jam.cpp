#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int num_t;

num_t divisor(num_t n)
{
	for (num_t k = 2; k <= num_t(sqrt(double(n)) + 0.5); ++k)
	{
		if ((n % k) == 0)
			return k;
	}
	return 0;
}

int main()
{
	ifstream fi("C-small-attempt0.in");
	ofstream fo("C-small-attempt0.out");

	int T, N, J;
	fi >> T;
	for (int t = 0; t < T; ++t)
	{
		fo << "Case #" << t+1 << ":" << endl;
		fi >> N >> J;
		int count = 0;
		vector<int> digits(N, 1);
		vector<num_t> divisors(9);
		int imax = pow(2, N-2);
		for (int i = 0; i < imax; ++i)
		{
			fill(digits.begin(), digits.end(), 1);
			for (int k = 1; k < N-1; ++k)
			{
				if (((i>>(k-1)) & 1) == 0)
					digits[k] = 0;
			}
			bool found = true;
			for (int b = 2; b < 11; ++b)
			{
				num_t n = 1 + pow(b, N-1);
				for (int k = 1; k < N-1; ++k)
				{
					if (digits[k])
						n += pow<num_t>(b, k);
				}
				divisors[b-2] = divisor(n);
				if (divisors[b-2] == 0)
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				for_each(digits.rbegin(), digits.rend(), [&](int d){ fo << d; });
				for_each(divisors.begin(), divisors.end(), [&](int d){ fo << " " << d; });
				fo << endl;
				++count;
				if (count == J)
					break;
			}
		}
	}
	return 0;
}
