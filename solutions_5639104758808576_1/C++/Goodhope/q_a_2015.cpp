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

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

char s[1005];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 cs = 1; cs <= cases; ++cs)
	{
		uint64 n;
		cin >> n >> s;

        uint r = 0,
             c = 0;

        for (uint i = 0; i <= n; ++i)
        {
            if (c < i)
            {
                r += i - c;
                c = i;
            }
            c += s[i] - '0';
        }

        cout << "Case #" << cs << ": " << r << "\n";
	}

	return 0;
}
