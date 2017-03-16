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

//int main16RQ_D()
int main()
{
	ifstream fin("D-small-attempt0.in");
	ofstream fout("D-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		ll K, C, S;
		fin >> K >> C >> S;

		if (C*S < K)
		{
			fout << "Case #" << zz << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			fout << "Case #" << zz << ":";

			ll cur = 0, posToCheck = 0;
			while (posToCheck < K)
			{
				ll pos = 1, mult = 1;
				for (ll i = 0; i < C && posToCheck < K; ++i, ++posToCheck, mult *= K)
				{
					pos += mult * posToCheck;
				}

				fout << " " << pos;
			}

			fout << endl;
		}		
	}

	return 0;
}
