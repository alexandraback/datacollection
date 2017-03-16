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

uint s[1001][1000],
	 ns[1001],
	 nv[1001];
bool f[1001];

uint n;

bool dfs(uint c)
{
	if (f[c])
		return true;

	f[c] = true;
	for (uint i = 0; i < ns[c]; ++i)
	{
		if (dfs(s[c][i]))
			return true;

		if (0 == c)
			fill(f, f + n + 1, false);
	}

	return false;
}

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 0; i < cases; ++i)
	{
		cin >> n;

		for (uint j = 1; j <= n; ++j)
		{
			cin >> nv[j];
			for (uint k = 0; k < nv[j]; ++k)
			{
				uint u;
				cin >> u;
				s[u][ns[u]++] = j;
			}
		}

		for (uint j = 1; j <= n; ++j)
		{
			if (0 == nv[j])
				s[0][ns[0]++] = j;
		}

		bool ok = dfs(0);
		cout << "Case #" << i + 1 << ": " << (ok ? "Yes" : "No") << endl;

		fill(f, f + n + 1, false);
		for (uint j = 0; j <= n; ++j)
			fill(s[j], s[j] + ns[j], 0);
		fill(ns, ns + n + 1, 0);
		fill(nv, nv + n + 1, 0);

	}

	return 0;
}
