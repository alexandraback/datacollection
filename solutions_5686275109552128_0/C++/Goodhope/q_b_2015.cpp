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

void add(map<uint, uint>& v, uint a, uint q)
{
    map<uint, uint>::iterator it = v.lower_bound(a);
    if (it != v.end() && it->first == a)
        it->second += q;
    else
        v.insert(it, make_pair(a, q));
}

int main(int argc, char* argv[])
{
    uint64 cases;
    cin >> cases;

    for (uint64 cs = 1; cs <= cases; ++cs)
    {
        uint64 d;
        cin >> d;

        map<uint, uint> v;
        for (uint i = 0; i < d; ++i)
        {
            uint a;
            cin >> a;

            add(v, a, 1);
        }

        uint r = 0,
            rr = v.rbegin()->first;

        while (v.rbegin()->first > 1)
        {
            map<uint, uint>::reverse_iterator jt = v.rbegin(),
                pt = jt;

            ++pt;
            uint x = (pt == v.rend()) ? 0 : pt->first,
                sc = 1;

            uint cr = -1;

            for (uint i = 1; i < jt->first; ++i)
            {
                uint hh = (jt->first + i - 1) / i,
                    sx = jt->second * (i - 1) + hh;
                if (sx <= cr)
                {
                    cr = sx;
                    sc = i;
                }
            }

            if (sc > 1)
            {
                uint hh = (jt->first + sc - 1) / sc,
                    hl = jt->first / sc;
                add(v, hh, 1);
                add(v, hl, jt->first / hl - 1);

                if (r + cr < rr)
                    rr = r + cr;

                r += cr - hh;

                map<uint, uint>::iterator et = v.end();
                --et;
                v.erase(et);
            }
            else
            {
                break;
            }
        }

        cout << "Case #" << cs << ": " << rr << "\n";
    }

    return 0;
}
