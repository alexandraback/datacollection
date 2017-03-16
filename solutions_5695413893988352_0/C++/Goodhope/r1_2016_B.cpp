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

char sa[20],
     sb[20];

uint pa[20],
     pb[20];

uint npa, npb;

bool add(char* s, uint* p, uint np)
{
	uint i = np - 1;
	while (i != -1)
	{
		++s[p[i]];
		if (s[p[i]] > '9' )
		{
			s[p[i]] = '0';
			--i;
		}
		else
			break;
	}

	return i != -1;
}

int main(int argc, char* argv[])
{
	uint64 cases;
    cin >> cases;

    for (uint64 cs = 1; cs <= cases; ++cs)
    {
		cin >> sa >> sb;

		npa = npb = 0;
		uint i = 0;
		for (char* p = sa; *p; ++p, ++i)
		{
			if (*p == '?')
			{
				*p = '0';
				pa[npa++] = i;
			}
		}

		i = 0;
		for (char* p = sb; *p; ++p, ++i)
		{
			if (*p == '?')
			{
				*p = '0';
				pb[npb++] = i;
			}
		}

		int mn = 100000;
		string sca,
			   scb;
		do
		{
			int x = atoi(sa);

			do
			{
				int y = atoi(sb);
				if (abs(x - y) < mn)
				{
					mn = abs(x - y);
					sca = sa;
					scb = sb;
				}
			}
			while (add(sb, pb, npb));
		}
		while (add(sa, pa, npa));

		cout << "Case #" << cs << ": " << sca << ' ' << scb << '\n';
    }

    return 0;
}
