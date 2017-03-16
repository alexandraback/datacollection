#include "stdafx.h"

#define PROBLEM_NAME "R1B_Prob_A"
#define PROBLEM_SMALL_INPUT "A-small-attempt5"
#define PROBLEM_LARGE_INPUT "A-large"

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_SMALL_INPUT ".in");
//	set_fio(PROBLEM_SMALL_INPUT ".in", PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_LARGE_INPUT ".in");
	set_fio(PROBLEM_LARGE_INPUT ".in", PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;

	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		vector<int> judges;
		vector<char> noneed;
		int sum = 0;
		for (int i=0; i<N; ++i)
		{
			int v;
			fin >> v;
			judges.push_back(v);
			noneed.push_back(0);
			sum+=v;
		}
/*
		int NN = N;
		for (int i=0; i<N; ++i)
		{
			if (2*sum - N*judges[i] < 0)
			{
				NN--;
			}
		}

		double guarantee_score = 2*sum / static_cast<double>(N);

		vector<double> frac;
		double one_over_N = 1 / static_cast<double>(N);
		double one_over_sum = 1 / static_cast<double>(sum);
		double sum_over_N = static_cast<double>(sum) / static_cast<double>(N);
		double dsum = 0;
		for (int i=0; i<N; ++i)
		{
//			//double d = one_over_N * one_over_sum * (2*sum - N*judges[i]) * 100;
//			double d = one_over_N * one_over_sum * (base - N*judges[i]) * 100;
//			frac.push_back(d);
//			dsum += d;

			if (2*sum - N*judges[i] < 0)
			{
				frac.push_back(0);
			}
			else
			{
				double d = one_over_N * one_over_sum * (2*sum - N*judges[i]) * 100;
				frac.push_back(d);
				dsum += d;
			}
		}

		if (dsum - 100 > 0.001 || dsum - 100 < -0.001)
		{
			for (int i=0; i<N; ++i)
			{
//				frac[i] = frac[i] * 100 / dsum;
			}
		}
*/

		int sum2 = 2*sum;

		int NN = N;
		for (int i=0; i<N; ++i)
		{
			if (2*sum - N*judges[i] < 0)
			{
				NN--;
				sum2 -= judges[i];
				noneed[i] = 1;
			}
		}

		double guarantee_score = sum2 / static_cast<double>(NN);

		vector<double> frac;
		double one_over_N = 1 / static_cast<double>(N);
		double one_over_sum = 1 / static_cast<double>(sum);
		double sum_over_N = static_cast<double>(sum) / static_cast<double>(N);
		double dsum = 0;
		for (int i=0; i<N; ++i)
		{
			if (noneed[i])
			{
				frac.push_back(0);
			}
			else
			{
				double d = (guarantee_score - judges[i]) / static_cast<double>(sum) * 100;
				frac.push_back(d);
				dsum += d;
			}
		}

		if (dsum - 100 > 0.001 || dsum - 100 < -0.001)
		{
			for (int i=0; i<N; ++i)
			{
//				frac[i] = frac[i] * 100 / dsum;
			}
		}

		fout << "Case #" << cases << ":";
		char str[256];
		for (int i=0; i<N; ++i)
		{
			sprintf(str, " %.6f", frac[i]);
			fout << str;
		}
		fout << endl;
	}

	return 0;
}
