#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <cassert>
#include <cmath>
#include <queue>

using namespace std;

const double pi = acos(-1);

int main()
{
    freopen("out.txt", "w", stdout);
    int tcas, cas = 0;
    scanf("%d", &tcas);
    while(tcas --)
    {
        long long r, t;
        cin >> r >> t;
        unsigned long long lef = 1, rig = t, mid = -1, ans = -1;
        while(lef <= rig)
        {
            mid = (lef + rig) / 2;
            double x = mid;
            double tmp = 2 * r * x + 2 * x * x - x;
            //cout << x << " " << tmp << endl;
            if(tmp <= t)
            {
                long long value = tmp;
                //if(t % value == 0)
                    ans = mid;
                lef = mid + 1;
            }
            else
                rig = mid - 1;
        }
        cout << "Case #" << ++cas << ": " << ans << endl;
    }
    return 0;
}
