// gj.cpp
//

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

uint b[100],
	 m[100];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 0; i < cases; ++i)
	{
		uint n, s, p;
		cin >> n >> s >> p;
		for (uint j = 0; j < n; ++j)
			cin >> b[j];

		uint res = 0;
		for (uint j = 0; j < n; ++j)
		{
			uint c = b[j] / 3,
				 r = b[j] % 3;
			m[j] =  r ? c + 1 : c;

			if (s && b[j] && m[j] == p - 1 && r != 1)
			{
				--s;
				++m[j];
			}

			if (m[j] >= p)
				++res;
		}

		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}
