#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxN = 1100000;

int s[MaxN], n, x, y, t;
long double f[5000][5000];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("B-large.in.txt", "r", stdin);
    freopen("B-large.out.txt", "w", stdout);
    #endif
    int TestCase;
    cin >> TestCase;
    for (int i = 1; i <= 1000; ++i)
        s[i] = 2*i*i-i;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": " << setprecision(10) << fixed;
        cin >> n >> x >> y;
        t = x > 0 ? (x+y >> 1)+1 : (y-x >> 1)+1;
        if (x == 0 && y == 0)
            cout << 1.0 << endl;
        else if (t > 1000)
            cout << 0.0 << endl;
        else if (n >= s[t])
            cout << 1.0 << endl;
        else if (n <= s[t-1])
            cout << 0.0 << endl;
        else if (x == 0)
            cout << 0.0 << endl;
        else
        {
            long double Ans = 0;
            n -= s[t-1];
            int m = (s[t]-s[t-1]-1)/2;
            memset(f, 0, sizeof(f));
            f[0][0] = 1.0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j <= i && j <= m; ++j)
                    if (j == m)
                        f[i+1][j] += f[i][j];
                    else if (i-j == m)
                        f[i+1][j+1] += f[i][j];
                    else
                    {
                        f[i+1][j] += f[i][j]/2;
                        f[i+1][j+1] += f[i][j]/2;
                    }
            for (int i = y+1; i <= n && i <= m; ++i)
                Ans += f[n][i];
            cout << Ans << endl;
        }
    }
	return 0;
}
