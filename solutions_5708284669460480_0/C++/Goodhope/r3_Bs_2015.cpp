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

char sk[20],
     sl[20];

uint64 v[10];

char sr[20];
uint64 si[20];

uint64 k, l, s;

bool next()
{
    ++si[0];
    uint i = 0;
    while (si[i] >= k && i < s)
    {
        si[i] = 0;
        ++i;
        if (i < s)
            ++si[i];
    }

    if (s == i)
        return false;

    for (uint j = 0; j < s; ++j)
        sr[j] = sk[si[j]];
    return true;
}

void cnt()
{
    uint n = 0;
    char* p = sr;
    while (p = strstr(p, sl))
    {
        ++p;
        ++n;
    }
    ++v[n];
}

int main(int argc, char* argv[])
{
    uint64 cases;
    cin >> cases;

    for (uint64 cs = 1; cs <= cases; ++cs)
    {
        cin >> k >> l >> s >> sk >> sl;

        fill(v, v + s + 1, 0);
        fill(si, si + s + 1, 0);
        fill(sr, sr + s, sk[0]);
        sr[s] = 0;

        uint all = 0;
        do
        {
            cnt();
            ++all;
        } while (next());

        uint64 mxb = s;
        while (v[mxb] == 0)
            --mxb;

        double res = 0;
        for (uint64 i = 1; i <= s; ++i)
            res += (double)i * v[i] / (double)all;

        cout << "Case #" << cs << ": " << fixed << setprecision(7) << (double)mxb - res << "\n";
    }

    return 0;
}
