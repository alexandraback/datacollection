#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

long long ans;
int main ()
{
    long long T, r , newR;
    double t;
    long double area, ante;

    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A.out","w",stdout);
    cin >> T;

    for (int tc = 0 ; tc < T ; tc ++)
    {
        cin >> r >> t;
        t *= 1.0;
        ans = 0;
        newR = r + 1;
        ante = r * 1.0 * r * 1.0;
        area = (newR * 1.0 * newR * 1.0);
        //cout << ante << " " << area << endl;
        while (t >= (area - ante))
        {
            t -= (area - ante);
           // cout << t << endl;
            ans ++;
            ante = ((newR + 1) * 1.0 * (newR + 1) * 1.0);;
            newR += 2;
            area = (newR * newR);

        }

        cout << "Case #"<< tc + 1 << ": " << ans << endl;


    }


    return 0;
}










