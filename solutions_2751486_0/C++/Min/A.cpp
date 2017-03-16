// CodeJam 2013
// Autor: Benjamín de la Fuente Ranea

#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

#include "BigIntegerLibrary.hh"

#define FILE_INPUT	"A-small-attempt3"

bool isVowel(char _c)
{
	return _c == 'a' || _c == 'e' || _c == 'i' || _c == 'o' || _c == 'u';
}

int findConsonants(const string& _name, int _ndx, int _n)
{
	int count = 0;
	for (unsigned i = _ndx; i < _name.length(); ++i)
	{
		if (!isVowel(_name[i]))
		{
			++count;
			if (count == _n)
				return i - _n + 1;
		}
		else
			count = 0;
	}

	return -1;
}

int nValue(const string& _name, int _n)
{
	int ndx = -1;
	set<pair<int, int> >	substrs;
	const int nameLasNdx = _name.length()-1;
	do
	{
		ndx = findConsonants(_name, ndx+1, _n);
		if (ndx != -1)
		{
			for (int j = 0; j <= ndx; ++j)
				for (int i = ndx + _n - 1; i <= nameLasNdx; ++i)
					substrs.insert(make_pair(j, i));

			for (int j = nameLasNdx; j > ndx + _n; --j)
				for (int i = 0; i <= ndx; ++i)
					substrs.insert(make_pair(i, j));
		}
	} while (ndx != -1);

	return substrs.size();
}

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	int numCases;
	scanf("%d\n", &numCases);
	for (int i = 1; i <= numCases; ++i)
	{
		int n;
		char name[1000001];
		scanf("%s %d\n", name, &n);

		printf("Case #%d: %d\n", i, nValue(name, n));
	}
}
