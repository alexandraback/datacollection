#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	int N;
	vector<int> keysGiven[200];
	int keyNeeded[200];
	int keyCount[200];
	int dp[1<<20];
	int canGo[1<<20];

	int go(int mask)
	{
		int& ret = dp[mask];
		if (ret >= 0) return ret;

		ret = 0;
		for (int i=0; i<N; ++i)
		{
			const int bit = 1<<i;
			if ((bit & mask) == 0 && keyCount[keyNeeded[i]] > 0)
			{
				// Remove key, add new ones
				--keyCount[keyNeeded[i]];
				const vector<int>& newKeys = keysGiven[i];
				for (size_t j=0; j<newKeys.size(); ++j)
					++keyCount[newKeys[j]];

				int nextRet = go(mask | bit);
				ret = max(ret, nextRet);

				// Reverse
				++keyCount[keyNeeded[i]];
				for (size_t j=0; j<newKeys.size(); ++j)
					--keyCount[newKeys[j]];

				if (nextRet > 0)
					canGo[mask] |= bit;
			}
		}

		return ret;
	}
}

//int main13QD()
int main()
{
	ifstream fin("D-small-attempt0.in");
	ofstream fout("D-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		for (int i=0; i<200; ++i)
			keysGiven[i].clear();

		memset(keyNeeded, 0, sizeof(keyNeeded));
		memset(keyCount, 0, sizeof(keyCount));
		memset(dp, -1, sizeof(dp));
		memset(canGo, 0, sizeof(canGo));

		int K;
		fin >> K >> N;
		dp[(1<<N)-1] = 1;

		for (int i=0; i<K; ++i)
		{
			int x; fin >> x;
			++keyCount[x-1];
		}

		for (int i=0; i<N; ++i)
		{
			int Ti, Ki;
			fin >> Ti >> Ki;

			keyNeeded[i] = Ti - 1;

			for (int j=0; j<Ki; ++j)
			{
				int x; fin >> x;
				keysGiven[i].push_back(x-1);
			}
		}

		int ret = go(0);
		if (ret == 0)
		{
			fout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			fout << "Case #" << zz << ":";

			int mask(0);
			while (mask + 1 != (1<<N))
			{
				int nextMove = 0;
				while ((canGo[mask] & (1<<nextMove)) == 0)
					++nextMove;

				fout << " " << (nextMove + 1);
				mask |= (1<<nextMove);
			}

			fout << endl;
		}		
	}

	return 0;
}