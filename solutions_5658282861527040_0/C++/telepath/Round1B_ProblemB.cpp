#include "include\preCompile\KL_PreCompile.hpp"

#define INPUT_FILE_PATH "D:\\DUMP\\input.in"
#define OUTPUT_FILE_PATH "D:\\DUMP\\output.out"


void init()
{
}

int main()
{
	clock_t time1;
	time1 = clock();

	freopen(INPUT_FILE_PATH, "r", stdin);
	freopen(OUTPUT_FILE_PATH, "w", stdout);


	int T;
	cin >> T;


	long long int total = 0, A, B, K, lo, hi;
	for (long long int caseNum = 1; caseNum <= T; caseNum++)
	{
		total = 0;
		cout << "Case #" << caseNum << ": ";

		// read3 (A, B, K);

		cin >> A >> B >> K;

		lo = (A < B? A : B);
		hi = (A < B? B : A);


		//else if (lo < K && K < hi)
		//{
		//	total += lo*K;
		//}

		if (K > hi || (lo < K && K < hi) )
		{
			total += hi*lo;

			cout << total << endl;

			continue;
		}
		else
		{
			total += K*K + 2*K*(lo - K) + K*(hi - lo);
		}


		// Now try the extra ones
		KL_FOR(i, K+1, hi, 1)
		{
			long long int tmp = i < lo? i : lo;

			KL_FOR(j, K, tmp, 1)
			{
				if ( (i & j) < K)
				{
					if (i < lo)
						total += 2;
					else
						total += 1;
				}
			}
		}
		cout << total << endl;
	}

#if 0
	clock_t time2, timeTaken;
	time2 = clock();
	timeTaken = time2 - time1;
	long long int seconds = timeTaken/CLOCKS_PER_SEC;
	long long int minutes = seconds/60;
	seconds %= 60;

	/*	-------- BEWARE - DON'T cout while doing freopen()	-------- 	*/
	cout << minutes << "min" << seconds << "sec";
#endif
}
