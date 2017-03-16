#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair


const int N = 100;
int a[N][N];

void solve(int test)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    bool ok = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            bool row = true;
            bool col = true;
            for (int k = 0; k < m; ++k)
                if (a[i][k] > a[i][j])
                    row = false;
            for (int k = 0; k < n; ++k)
                if (a[k][j] > a[i][j])
                    col = false;
            if (!row && !col)
                ok = false;
        }

    cout << "Case #" << test << ": ";
    cout << (ok ? "YES" : "NO") << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        solve(i);

    return 0;
}
