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

bool db[40];
uint64 dv[10];

int main(int argc, char* argv[])
{
    uint64 cases;
    cin >> cases;

    for (uint64 cs = 1; cs <= cases; ++cs)
    {
        uint64 c, d, v;
        cin >> c >> d >> v;

        fill(db, db + v + 1, false);

        for (uint64 i = 0; i < d; ++i)
        {
            cin >> dv[i];
            db[dv[i]] = true;
        }

        uint r = 0;
        for (uint i = 1; i <= v; i *= 2)
        {
            if (!db[i])
                ++r;
        }

        cout << "Case #" << cs << ": " << r << "\n";
    }

    return 0;
}
