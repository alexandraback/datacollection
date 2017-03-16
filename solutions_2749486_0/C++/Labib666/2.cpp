/*
ID: Labib Rashid
LANG: C++
TASK:
*/

#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cmath>
#include <cstdlib>
#include <ctime>
# include <cstring>
# include <queue>
# define ll long long
# define pb push_back
# define x first
# define y second
# define inf 1000000007
# define pi 2*asin(1)

using namespace std;

int main()
{
    //freopen (".txt","r",stdin);
    freopen ("B-small-attempt2.in","r",stdin);
    freopen ("B-small-attempt2.txt","w",stdout);

    ll t, tc = 0, i, j, k, dx, dy;
    string s;

    cin >> t;
    while (tc < t)
    {
        ++tc;
        s.empty();

        cin >> dx >> dy;
        //cout << dx << " " << dy << endl;

        if (dx != 0){
            for (i = 0; i < abs(dx)-1; i++)
                s += "EW";
            if (dx > 0) s += "E";
        }

        if (dy != 0){
            if (dy > 0){
                for (i = 0; i < abs(dy); i++)
                    s += "SN";
            }
            if (dy < 0){
                for (i = 0; i < abs(dy); i++)
                    s += "NS";
            }
        }


        printf ("Case #%d: ", tc);
        cout << s << endl;
    }

    return 0;
}

