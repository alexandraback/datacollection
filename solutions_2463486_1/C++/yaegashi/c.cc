#define __STDC_FORMAT_MACROS
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#include <iostream>
#include <sstream>
#include <string>
#include <set>


using namespace std;

set<uint64_t> fairset;

bool
fair(uint64_t x)
{
        char s[32];
        snprintf(s, sizeof(s), "%" PRIu64, x);
        int a = 0;
        int b = strlen(s) - 1;
        while (a < b) {
                if (s[a] != s[b])
                        return false;
                a++;
                b--;
        }
        return true;
}


int
scan(uint64_t a, uint64_t b)
{
        int c = 0;
        uint64_t smin = sqrt(a);
        uint64_t smax = sqrt(b);
        assert(smin*smin <= a);
        assert((smin+1)*(smin+1) > a);
        assert(smax*smax <= b);
        assert((smax+1)*(smax+1) > b);
        for (uint64_t s = smin; s <= smax; s++) {
                if (!fair(s))
                        continue;
                uint64_t ss = s * s;
                if (ss < a)
                        continue;
                if (fair(ss)) {
                        fairset.insert(ss);
                        c++;
                }
        }
        return c;
}


int
main(int argc, char **argv)
{
        scan(1, 1000000000000000);

        int T;
        string  lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {
                string lineAB;
                getline(cin, lineAB);
                stringstream ssAB(lineAB);
                uint64_t a, b;
                ssAB >> a >> b;
                int c = 0;
                for (set<uint64_t>::iterator it = fairset.begin();
                                it != fairset.end(); it++) {
                        if (a <= (*it) && (*it) <= b)
                                c++;
                }
                cout << "Case #" << i+1 << ": " << c << endl;
        }

        return 0;
}
