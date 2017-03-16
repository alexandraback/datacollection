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

char ss[10001],
     s[120001];

int lr[120001],
    rl[120001];

int w[4][4] = {
    { 1,  2,  3,  4 },
    { 2, -1,  4, -3 },
    { 3, -4, -1,  2 },
    { 4,  3, -2, -1 }
};

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 cs = 1; cs <= cases; ++cs)
	{
		uint64 l, x;
		cin >> l >> x >> ss;

        uint64 cp = 4 + x % (uint64)4;
        if (cp > x)
            cp = x;

        s[0] = 0;
        for (uint64 i = 0; i < cp; ++i)
            strcat(s, ss);

        l *= cp;

        for (char* p = s; *p; ++p)
        {
            switch (*p)
            {
            case 'i':
                *p = 2;
                break;
            case 'j':
                *p = 3;
                break;
            case 'k':
                *p = 4;
                break;
            }
        }

        int pr = 0;
        bool neg = false;

        for (uint64 i = 0; i < l; ++i)
        {
            lr[i] = w[pr][s[i] - 1];
            if (neg)
                lr[i] = -lr[i];

            pr = abs(lr[i]) - 1;
            neg = lr[i] < 0;
        }

        pr = 0;
        neg = false;
        for (uint64 i = l - 1; i != -1; --i)
        {
            rl[i] = w[s[i] - 1][pr];
            if (neg)
                rl[i] = -rl[i];

            pr = abs(rl[i]) - 1;
            neg = rl[i] < 0;
        }

        uint64 fl = 0,
               fr = l - 1;

        bool ok = false;
        while (fl < fr && lr[fl] != 2)
            ++fl;

        while (fl < fr && rl[fr] != 4)
            --fr;

        if (fl < fr && lr[fr - 1] == 4)
            ok = true;

        cout << "Case #" << cs << ": " << (ok ? "YES" : "NO") << "\n";
	}

	return 0;
}
