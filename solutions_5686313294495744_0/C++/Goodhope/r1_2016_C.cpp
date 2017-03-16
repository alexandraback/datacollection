// gj.cpp
//

#include <assert.h>

#include <fstream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

vector<string> fw, sw;
set<string> fs, ss;

uint cov(uint n)
{
	uint e = 1 << n;

	uint mn = -1;
	for (uint i = 1; i < e; ++i)
	{
		set<string> cs, cf;
		uint o = 0;
		for (uint j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				cf.insert(fw[j]);
				cs.insert(sw[j]);
				++o;
			}
		}

		if (cs == ss && cf == fs)
		{
			if (o < mn)
			{
				mn = o;
				if (mn == max(cs.size(), cf.size()))
					break;
			}
		}
	}

	return mn;
}

int main(int argc, char* argv[])
{
	uint64 cases;
    cin >> cases;

    for (uint64 cs = 1; cs <= cases; ++cs)
    {
		uint n;
		cin >> n;

		fw.clear();
		sw.clear();
		fs.clear();
		ss.clear();
		for (uint i = 0; i < n; ++i)
		{
			string f, s;
			cin >> f >> s;

			fw.push_back(f);
			sw.push_back(s);

			fs.insert(f);
			ss.insert(s);
		}

		uint r = cov(n);

		cout << "Case #" << cs << ": " << n - r << '\n';
    }

    return 0;
}
