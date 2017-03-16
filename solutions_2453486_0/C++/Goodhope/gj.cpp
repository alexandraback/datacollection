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

char q[4][4];

bool check(char c)
{
	bool ok = true;
	for (uint j = 0; j < 4; ++j)
	{
		ok = true;
		for (uint k = 0; k < 4; ++k)
		{
			if (q[j][k] != c && q[j][k] != 'T')
			{
				ok = false;
				break;
			}
		}

		if (ok)
			return true;
	}

	for (uint j = 0; j < 4; ++j)
	{
		ok = true;
		for (uint k = 0; k < 4; ++k)
		{
			if (q[k][j] != c && q[k][j] != 'T')
			{
				ok = false;
				break;
			}
		}

		if (ok)
			return true;
	}

	ok = true;
	for (uint j = 0; j < 4; ++j)
	{
		if (q[j][j] != c && q[j][j] != 'T')
		{
			ok = false;
			break;
		}
	}
	if (ok)
		return true;

	ok = true;
	for (uint j = 0; j < 4; ++j)
	{
		if (q[j][3 - j] != c && q[j][3 - j] != 'T')
		{
			ok = false;
			break;
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
		bool ne = false;

		for (uint j = 0; j < 4; ++j)
		{
			for (uint k = 0; k < 4; ++k)
			{
				cin >> q[j][k];
				if (q[j][k] == '.')
					ne = true;
			}
		}

		if (check('X'))
			cout << "Case #" << i << ": X won" << endl;
		else if (check('O'))
			cout << "Case #" << i << ": O won" << endl;
		else if (ne)
			cout << "Case #" << i << ": Game has not completed" << endl;
		else
			cout << "Case #" << i << ": Draw" << endl;
	}

	return 0;
}
