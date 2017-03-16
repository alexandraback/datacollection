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

long long dp [15][15];

int main ()
{

    long long T , e , r , n, num, pos;

    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("b.out","w",stdout);

    cin >> T;

    for (int tc = 0; tc < T ; tc ++)
    {
        cin >> e >> r >> n;
        memset (dp , -1 ,sizeof (dp));

        dp [0][e] = 0;
        for (int i = 0 ; i < n ; i ++)
        {
            cin >> num;

            for (int j = 0; j <= e; j ++)
            {
                if (dp [i][j] != -1)
                {
                    for (int k = j ; k >= 0 ; k --)
                    {
                        if ((j - k ) + r > e)
                        {
                            pos = e;
                        }else
                            pos = (j - k ) + r;
                        dp [i + 1][pos] = max (dp [i + 1][pos], dp [i][j] +  (k * num));
                    }
                }
            }

        }

      /*  for (int i = 0 ; i < 5 ; i ++)
        {
            for (int j = 0 ; j < 6 ; j ++)
                cout << dp [i][j] << " ";
            cout << endl;
        }
*/
        long long may = 0;
        for (int i = 0; i <= e; i ++)
        {
            may = max (may , dp [n][i]);
        }
        cout << "Case #" << tc + 1 << ": " << may << endl;
    }

    return 0;
}










