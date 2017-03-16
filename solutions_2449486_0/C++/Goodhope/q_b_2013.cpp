// gj.cpp
//

#include <assert.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

uint q[100][100];
uint n, m;

bool check(uint r, uint c)
{
	bool ok = true;
	for (uint j = 0; j < m; ++j)
	{
		if (q[r][c] < q[r][j])
		{
			ok = false;
			break;
		}
	}

	if (!ok)
	{
		ok = true;
		for (uint j = 0; j < n; ++j)
		{
			if (q[r][c] < q[j][c])
			{
				ok = false;
				break;
			}
		}
	}

	return ok;
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		cin >> n >> m;

		for (uint j = 0; j < n; ++j)
			for (uint k = 0; k < m; ++k)
				cin >> q[j][k];

		bool ok = true;
		for (uint j = 0; ok && j < n; ++j)
		{
			for (uint k = 0; ok && k < m; ++k)
			{
				ok = check(j, k);
			}
		}

		cout << "Case #" << i << (ok ? ": YES" : ": NO") << endl;
	}

	return 0;
}
