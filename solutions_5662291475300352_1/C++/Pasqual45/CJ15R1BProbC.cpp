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
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

//int main15R1B_C()
int main()
{
	ifstream fin("C-small-2-attempt0.in");
	ofstream fout("C-small-2-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int n;
		fin >> n;
		vector<ll> loc, time;
		for (int i = 0; i < n; ++i)
		{
			int d, h, m;
			fin >> d >> h >> m;
			for (int j = 0; j < h; ++j)
			{
				loc.push_back(d);
				time.push_back(m + j);
			}
		}

		ll result = 999999;
		for (int i = 0; i < loc.size(); ++i)
		{
			ll tFinish = time[i] * (360 - loc[i]);

			ll cur = 0;
			for (int j = 0; j < loc.size(); ++j)
			{
				ll thisFinish = time[j] * (360 - loc[j]);
				if (thisFinish > tFinish)
				{
					// Overtake this guy once
					++cur;
				}
				else
				{
					ll timeLeft = tFinish - thisFinish;
					ll completeLaps = timeLeft / (time[j] * 360);
					cur += completeLaps;
				}
			}

			result = min(result, cur);
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
