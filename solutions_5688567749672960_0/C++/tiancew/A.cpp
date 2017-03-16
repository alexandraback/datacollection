#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
//#include<vector>
//#include<set>
//#include<climit>
#include<cmath>
//#include<cstdlib>  rand()

using namespace std;

long long reversen(long long N)
{
	long long a = 0;
	while (N > 0)
	{
		a = a * 10 + N % 10;
		N = N / 10;
	}
	return a;
}

int main()
{
	ofstream outfile("D:\\codejam\\2015\\R2\\output.txt");
	ifstream infile("D:\\codejam\\2015\\R2\\testcase.txt");

	int T;
	infile >> T;

	for (int casenum = 1; casenum <= T; casenum++)
	{
		long long N;
		long long ans = 0;
		infile >> N;
		string s = to_string(N);
		int sdigits = s.length();
		if (N <= 20)
		{
			ans = N;
		}
		else if (sdigits == 2)
		{
			int lastdigit = N % 10;
			if (lastdigit == 0)
			{
				ans = 19 + N / 10;

			}
			else
			{
				ans = lastdigit + 10 + N / 10;
			}
		}
		else // at least 3 digits
		{
			ans = 10;		// get to 10
			long long current = 10;
			for (int i = 2; i < sdigits; i++)
			{
				ans = ans + pow(10, i / 2) + pow(10, (i - i / 2)) - 1;
				current = current * 10;
			}
				// reach 10000....000

			if (N != current)		// N is not a power of 10
			{
				long long rhalf = (long long)pow(10, sdigits / 2);
				long long a = N % rhalf;		// a = right half of N
				if (a > 0)
				{
					N = N - a + 1;		// N = xxxx0001
					long long revN = reversen(N);
					if (revN < N)
						ans += a;
					else
						ans = ans + a - 1;
					ans = ans + (revN % (rhalf * 10));
				}
				else
				{
					N--; ans++;
					a = N % rhalf;
					N = N - a + 1;		// N = xxxx0001
					long long revN = reversen(N);
					if (revN < N)
						ans += a;		// rotate 
					else
						ans = ans + a - 1;		// no rotation
					ans = ans + (revN % (rhalf * 10));

				}
			}
			
		}


		outfile << "Case #" << casenum << ": " << ans << endl;
	}


	infile.close();
	outfile.close();
	return 0;
}
