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

using namespace std;

typedef long double D;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        D farmPrice, farmRate, goal;
        cin >> farmPrice >> farmRate >> goal;
        D rate = 2;
        D ans = 0;

        while (true) {
            const D straightAhead = goal / rate;
            const D buyFarm = farmPrice / rate + goal / (rate + farmRate);
            if (straightAhead <= buyFarm) {
                ans += straightAhead;
                break;
            }
            ans += farmPrice / rate;
            rate += farmRate;
        }

        cout << "Case #" << cas << ": ";
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(10);
        cout << ans << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}
