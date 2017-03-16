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

int d[NMAX][NMAX];
int s, n, p;
int t[NMAX];

void solve(int tc)
{
    printf("Case #%d: ", tc);

    cin >> n >> s >> p;
    forn(i, n) cin >> t[i];

    memset(d, 0, sizeof(d));

    forn(i, n)
    {
        forn(j, s + 1)
        {
            forn(m2, 11)
            {
                for (int m1 = max(0, m2 - 2); m1 <= m2; m1++)
                {
                    for (int m0 = max(0, m2 - 2); m0 <= m1; m0++)
                    {
                        if (m0 + m1 + m2 != t[i]) continue;
                        int nj = j + (m2 == m0 + 2);
                        if (nj > s) continue;
                        int nd = d[i][j] + (m2 >= p);

                        d[i + 1][nj] = max(d[i + 1][nj], nd);                        
                    }
                }
            } 
        }
    }

    cout << d[n][s] << endl;
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
