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

	vector<int> can(int x, int y, int z)
	{
		if (z == 1)
		{
			return vector<int>(1, 1);
		}

		if (x == 1)
		{
			return vector<int>(1, z);
		}

		if (y == 1)
		{
			return vector<int>(z, 1);
		}

		if (z < 4)
		{
			return vector<int>();
		}

		for (int width = 2; width <= y; ++width)
		{
			int baseRows = z / width, leftOver = z%width;
			if (baseRows < 2) continue;

			if (leftOver > 0 && width == 2)
				continue;
			
			int numRows = (z + width - 1) / (width);
			if (numRows > x || numRows == 0) continue;

			vector<int> ret(baseRows, width);
			if (leftOver == 1)
			{
				if (baseRows == 2)
					continue;

				--ret.back();
				++leftOver;
			}

			if (leftOver > 0)
				ret.push_back(leftOver);

			return ret;
		}

		return vector<int>();
	}

	
}

//int main14RQ_C()
int main()
{
	ifstream fin("C-small-attempt2.in");
	ofstream fout("C-small-attempt2.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int x, y, z;
		fin >> x >> y >> z;
		z = x*y - z;

		vector<int> v = can(x, y, z);

		fout << "Case #" << zz << ": " << endl;
		if (v.empty())
		{
			fout << "Impossible" << endl;
		}
		else
		{
			vector<string> w(x, string(y, '*'));
			for (int i = 0; i < v.size(); ++i)
			{
				fill(w[i].begin(), w[i].begin() + v[i], '.');
			}

			w[0][0] = 'c';
			for (int i = 0; i < w.size(); ++i)
				fout << w[i] << endl;
		}
	}

	return 0;
}
