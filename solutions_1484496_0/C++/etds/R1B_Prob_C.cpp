#include "stdafx.h"

#define PROBLEM_NAME "R1B_Prob_C"
#define PROBLEM_SMALL_INPUT "C-small-attempt1"
#define PROBLEM_LARGE_INPUT "R1B-C-large"

vector<__int64> val;

struct sumset
{
	char a[20], b[20];
	__int64 sum_a, sum_b;
};

bool find_sumset(sumset& curr, int i)
{
	if (i >= val.size())
		return false;

	__int64 curval = val[i];

	if (curr.sum_a + curval == curr.sum_b)
	{
		curr.a[i] = 1;
		return true;
	}
	if (curr.sum_b + curval == curr.sum_a)
	{
		curr.b[i] = 1;
		return true;
	}

	sumset c_a = curr, c_b = curr, c_none = curr;
	c_a.a[i] = 1;
	c_a.sum_a += curval;
	c_b.b[i] = 1;
	c_b.sum_b += curval;

	if (find_sumset(c_a, i+1))
	{
		curr = c_a;
		return true;
	}
	if (find_sumset(c_b, i+1))
	{
		curr = c_b;
		return true;
	}
	if (find_sumset(c_none, i+1))
	{
		curr = c_none;
		return true;
	}
	return false;
}




int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_SMALL_INPUT ".in", PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_LARGE_INPUT ".in", PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;

	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		val.clear();
		__int64 sum = 0;
		for (int i=0; i<N; ++i)
		{
			__int64 v;
			fin >> v;
			val.push_back(v);
			sum += v;
		}

		sumset curr_a, curr_none;
		memset(&curr_a, 0, sizeof(sumset));
		memset(&curr_none, 0, sizeof(sumset));

		curr_a.a[0] = 1;
		curr_a.sum_a += val[0];

		fout << "Case #" << cases << ": " << endl;

		if (find_sumset(curr_a, 1))
		{
			for (int i=0; i<N; ++i)
			{
				if (curr_a.a[i])
					fout << val[i] << " ";
			}
			fout << endl;
			for (int i=0; i<N; ++i)
			{
				if (curr_a.b[i])
					fout << val[i] << " ";
			}
			fout << endl;
		}
		else if (find_sumset(curr_none, 1))
		{
			for (int i=0; i<N; ++i)
			{
				if (curr_none.a[i])
					fout << val[i] << " ";
			}
			fout << endl;
			for (int i=0; i<N; ++i)
			{
				if (curr_none.b[i])
					fout << val[i] << " ";
			}
			fout << endl;
		}
		else
		{
			fout << "Impossible" << endl;
		}

	}

	return 0;
}
