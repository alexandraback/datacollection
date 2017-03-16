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

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 cs = 1; cs <= cases; ++cs)
	{
		uint64 x, r, c;
		cin >> x >> r >> c;
        uint64 v = r * c;

        bool g = false;
        switch (x)
        {
        case 1:
            g = true;
            break;
        case 2:
            g = (v % 2 == 0);
            break;
        case 3:
            g = (v % 3 == 0) && (r > 1 && c > 1);
            break;
        case 4:
            g = (v % 4 == 0) && (r > 2 && c > 2);
            break;
        }
        cout << "Case #" << cs << ": " << (g ? "GABRIEL" : "RICHARD") << "\n";
	}

	return 0;
}
