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

//("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

uint a[256];

uint v[1000],
     vn;

int main(int argc, char* argv[])
{
	uint64 cases;
    cin >> cases;

    for (uint64 cs = 1; cs <= cases; ++cs)
    {
		string s;
		cin >> s;

		uint sz = s.size();
		vn = 0;
		for (uint i = 0; i < sz; ++i)
			++a[s[i]];

		// 0
		for (; a['Z']; --a['Z'])
		{
			v[vn++] = 0;
			--a['E'];
			--a['R'];
			--a['O'];
		}

		// 2
		for (; a['W']; --a['W'])
		{
			v[vn++] = 2;
			--a['T'];
			--a['O'];
		}

		// 6
		for (; a['X']; --a['X'])
		{
			v[vn++] = 6;
			--a['S'];
			--a['I'];
		}

		// 8
		for (; a['G']; --a['G'])
		{
			v[vn++] = 8;
			--a['E'];
			--a['I'];
			--a['H'];
			--a['T'];
		}

		// 3
		for (; a['T']; --a['T'])
		{
			v[vn++] = 3;
			--a['H'];
			--a['R'];
			--a['E'];
			--a['E'];
		}

		// 4
		for (; a['U']; --a['U'])
		{
			v[vn++] = 4;
			--a['F'];
			--a['O'];
			--a['R'];
		}

		// 5
		for (; a['F']; --a['F'])
		{
			v[vn++] = 5;
			--a['I'];
			--a['V'];
			--a['E'];
		}

		// 1
		for (; a['O']; --a['O'])
		{
			v[vn++] = 1;
			--a['N'];
			--a['E'];
		}

		// 7
		for (; a['V']; --a['V'])
		{
			v[vn++] = 7;
			--a['S'];
			--a['E'];
			--a['E'];
			--a['N'];
		}

		// 9
		for (; a['I']; --a['I'])
		{
			v[vn++] = 9;
			--a['N'];
			--a['N'];
			--a['E'];
		}

		sort(v, v + vn);
		cout << "Case #" << cs << ": ";

		for (uint i = 0; i < vn; ++i)
			cout << v[i];
		cout << '\n';
    }

    return 0;
}
