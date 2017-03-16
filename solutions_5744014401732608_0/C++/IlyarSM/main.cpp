#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <memory>
#include <bitset>
#include <functional>
using namespace std;

#define fori(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(x, y) make_pair((x), (y))

using llg = long long;
using ldb = long double;

const int maxn = 55;

int matrix[maxn][maxn];

void solve()
{

    fori(i, maxn)
    {
        fori(j, maxn)
        {
            if (j > i)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }


    int n;
    llg m;
    cin >> n >> m;

    fori(i, n)
        matrix[i][n - 1] = 0;

    if (m > (1LL << (n - 2)))
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;

    m--;
    matrix[0][n - 1] = 1;
    int pos = 1;
    while (m > 0)
    {
        if ((m & 1))
            matrix[pos][n - 1] = 1;
        pos++;
        m >>= 1;
    }
    fori(i, n)
    {
        fori(j, n)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    fori(i, tests)
    {
        cout << "Case #" << to_string(i + 1) << ": ";
        solve();
    }

    return 0;
}