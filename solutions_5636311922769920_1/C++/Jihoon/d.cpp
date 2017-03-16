#include <iostream>
#include <vector>

#define SUBMIT 1

#if SUBMIT
	#define print(stream) \
		cout << stream;
	#define dbg(stream) 0;
#else
	#define print(stream) 0;
	#define dbg(stream) \
		cout << stream;
#endif

using namespace std;

void solve(unsigned K, unsigned C, unsigned S)
{
	if (C == 1 || K == 1)
	{
		if (S >= K)
		{
			for (unsigned i = 0; i < K; ++i)
				print(" " << (i+1));
		}
		else
			print(" IMPOSSIBLE");

		return;
	}

	vector<string> strs;
	vector<string> c2strs;
	strs.resize(K);
	c2strs.resize(K);

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			if (i == j)
				strs[i] += 'G';
			else
				strs[i] += 'L';
		}

		for (int j = 0; j < K; ++j)
		{
			if (i == j)
			{
				for (int k = 0; k < K; ++k)
				{
					c2strs[i] += 'G';
				}
			}
			else
			{
				c2strs[i] += strs[i];
			}
		}
		dbg(c2strs[i] << endl);
	}

	int end = K * K;
	int min_c = -1;
	for (int i = 0; i < end; ++i)
	{
		int c = 0;
		for (int j = 0; j < K; ++j)
		{
			if (c2strs[j][i] == 'L')
			{
				++c;
			}
		}

		if (min_c == -1 || c < min_c)
			min_c = c;
	}

	dbg("min_c: " << min_c << endl);

	if (min_c >= S)
		print(" IMPOSSIBLE")
	else
	{
		int numPrinted = 0;
		for (int i = 0; i < end; ++i)
		{
			int c = 0;
			for (int j = 0; j < K; ++j)
			{
				if (c2strs[j][i] == 'L')
				{
					++c;
				}
			}

			if (c < S)
			{
				print(" " << i + 1);
				if (++numPrinted >= S)
					break;
			}
		}
	}
}

int main()
{
	unsigned numInputs = 0;
	
	cin >> numInputs;

	for (size_t i=0; i< numInputs; ++i)
	{
		unsigned K, C, S;
		cin >> K >> C >> S;

		print("Case #" << i + 1 << ":");
		solve(K, C, S);
		print(endl);
	}	

	return 0;
}
