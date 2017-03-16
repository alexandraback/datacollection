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

//int main16R1A_B()
int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int N;
		fin >> N;

		map<int, int> m;
		for (int i = 0; i < 2 * N - 1; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int x;
				fin >> x;
				++m[x];
			}
		}

		int result = 999;
		fout << "Case #" << zz << ":";
		for (auto p : m)
		{
			if (p.second % 2)
				fout << " " << p.first;
		}
		fout << endl;
	}

	return 0;
}
