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


//int main15RQ_B()
int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int d;
		fin >> d;
		vector<int> v(d);
		for (int i = 0; i < d; ++i)
			fin >> v[i];

		int result = 9999;

		for (int target = 1; target <= 1000; ++target)
		{
			int cost = target;
			for (int i = 0; i < d; ++i)
			{
				cost += (v[i] - 1) / target;
			}

			result = min(result, cost);
		}

		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
