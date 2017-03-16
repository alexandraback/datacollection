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

namespace
{
	bool canPlace(int w, int h, int x)
	{
		if (w > h) swap(w, h);

		if (((w*h) % x) != 0)
			return false;

		if (x < 3)
			return true;

		if (x > 6)
			return false;

		if (w == 1)
			return false;

		if (w == 2)
		{
			return x < 4;
		}

		if (w == 3)
		{
			return x < 6;
		}

		return true;
	}
}

//int main15RQ_D()
int main()
{
	ifstream fin("D-small-attempt0.in");
	ofstream fout("D-small-attempt0.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int x, r, c;
		fin >> x >> r >> c;
		bool result = canPlace(r, c, x);

		fout << "Case #" << zz << ": " << (result ? "GABRIEL" : "RICHARD") << endl;
	}

	return 0;
}
