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
typedef long long ll;
typedef pair<int,int> pii;

//int main12R1PB()
int main()
{
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	int N;

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		fin >> N;

		vector<pii> all(N);
		for (int i=0; i<N; ++i)
		{
			fin >> all[i].first >> all[i].second;
		}

		sort(all.begin(), all.end());

		int nextSmall = 0;
		bool good = true;

		int result = 0, score = 0;
		multiset<int> unused, used;
		while (good)
		{
			while (nextSmall < N && all[nextSmall].first <= score)
				unused.insert(all[nextSmall++].second);

			if (unused.empty() && used.empty())
			{
				if (nextSmall < N) good = false;
				break;
			}

			if (!unused.empty() && score >= *unused.begin())
			{
				++result;
				score += 2;
				unused.erase(unused.begin());
			}
			else if (!used.empty() && score >= *used.begin())
			{
				++result;
				++score;
				used.erase(used.begin());
			}
			else if (!unused.empty())
			{
				int next = *unused.rbegin();
				++result;
				++score;
				used.insert(next);
				unused.erase(unused.find(next));
			}
			else
			{
				good = false;
			}
		}

		if (good)
			fout << "Case #" << zz << ": " << result << endl;
		else
			fout << "Case #" << zz << ": " << "Too Bad" << endl;
	}

	return 0;
}