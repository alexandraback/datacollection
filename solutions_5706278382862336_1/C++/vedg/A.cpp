//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
# include <array>
# include <cassert>
typedef long long L;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        L p, q;
        char tmp;
        cin >> p >> tmp >>q;
        assert(tmp == '/');
        cout << "Case #" << cas << ": ";
        int pw = 0;
        {
            L t = q;
            while (t > 1 && t % 2 == 0) {
                t /= 2;
                ++pw;
            }
            if (p % t != 0) {
                cout << "impossible" << endl;
                continue;
            }
            p /= t;
            q /= t;
        }

        L cur = 1;
        for (int i = 0; i <= 40; ++i, cur *= 2) {
            L a = p, b = q, t = 1;
            while (b > cur) {
                t *= 2;
                b /= 2;
            }
            if (a >= t) {
                cout << i;
                break;
            }
        }



        std::cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    //putchar('\n');
#endif
}
