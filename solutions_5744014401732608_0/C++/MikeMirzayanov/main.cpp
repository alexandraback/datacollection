#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n;
long long k;

int main(int argc, char* argv[])
{
    int testCount;
    cin >> testCount;

    forn(test, testCount)
    {
        cin >> n >> k;

        long long cnts[100] = {0LL};
        cnts[0] = cnts[1] = 1LL;
        for (int i = 2; i < n; i++)
        {
            cnts[i] = 2 * cnts[i - 1];
            if (cnts[i] > k)
                cnts[i] = k + 1;
        }

        vector<string> f(n, string(n, '0'));
        forn(i, n - 1)
            for (int j = i + 1; j < n - 1; j++)
                f[i][j] = '1';

        for (int i = n - 2; i >= 0; i--)
            if (cnts[i] <= k && k > 0)
            {
                f[i][n - 1] = '1';
                k -= cnts[i];
            }

        cout << "Case #" << (test + 1) << ": ";
        if (k == 0)
        {
            cout << "POSSIBLE" << endl;
            forn(i, n)
                cout << f[i] << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }



    return 0;
}
