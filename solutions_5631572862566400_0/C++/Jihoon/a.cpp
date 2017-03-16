#include <iostream>
#include <vector>

using namespace std;

unsigned backtrack(unsigned old_n, vector<unsigned>& bf, vector<bool>& included, unsigned N)
{
	vector<bool> localIncluded = included;

	unsigned largest = 0;
	for (unsigned j = 1; j <= N; ++j)
	{
		unsigned count = 0;
		if (bf[j] == old_n && included[j] == false)
		{
			++count;
			localIncluded[j] = true;

			count += backtrack(j, bf, localIncluded, N);
		}

		if (count > largest)
		{
			largest = count;
			included = localIncluded;
		}

	}
	return largest;
}

unsigned solve(vector<unsigned>& bf, unsigned N)
{
	unsigned longest = 0;

	for (unsigned i = 1; i <= N; ++ i)
	{
		vector<bool> included;
		included.reserve(N+1);

		for (unsigned  j = 0; j <= N; ++j)
			included.push_back(false);

		unsigned limit = N;
		unsigned n = i;
		unsigned count = 0;

		bool circled = false;
		while (++count <= N)
		{
			included[n] = true;	
			unsigned old_n = n;
			n = bf[n];

			if (included[n] == true)
			{
				if (n != i && bf[n] != old_n)
					break;

				if (bf[n] == old_n)
				{
					count += backtrack(old_n, bf, included, N);
					/*
					while (true)
					{
						bool found = false;
						for (unsigned j = 1; j <= N; ++j)
						{
							if (bf[j] == old_n && included[j] == false)
							{
								++count;
								included[j] = true;
								found = true;
								old_n = j;
	
								break;
							}
						}
						if (found == false)
							break;

					}
					*/
				}
				circled = true;
				break;
			}
		}

		if (circled == true && count > longest)
			longest = count;
	}

	return longest;
}

int main()
{
	unsigned numInputs = 0;

	cin >> numInputs;

	for (unsigned i=0; i< numInputs; ++i)
	{
		vector<unsigned> bf;

		unsigned N;
		cin >> N;

		bf.reserve(N+1);
		bf.push_back(0);
		for (unsigned j = 1 ; j <= N; ++j)
		{
			unsigned n;
			cin >> n;

			bf.push_back(n);
		}

		cout << "Case #" << i + 1 << ": " << solve(bf, N) << endl;
	}
	return 0;
}

