#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

#define NMAX 105

int a[NMAX][NMAX];
int n, m;

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    cin >> n >> m;
    forn(i, n) forn(j, m) cin >> a[i][j];

    for (int h = 1; h < 100; h++)
    {
        forn(i, n)
        {
            bool f = true;
            forn(j, m)
            {
                if (a[i][j] > 0 && a[i][j] != h) f = false;
            }

            if (f)
            {
                forn(j, m) a[i][j] = 0;
            }
        }

        forn(i, m)
        {
            bool f = true;
            forn(j, n)
            {
                if (a[j][i] > 0 && a[j][i] != h) f = false;
            }

            if (f)
            {
                forn(j, n) a[j][i] = 0;
            }
        }

        forn(i, n)
        {
            forn(j, m)
            {
                if (a[i][j] == h)
                {
                    puts("NO");
                    return;
                }
            }
        }
    }

    puts("YES");
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
