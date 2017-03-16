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

#define NMAX 20
#define VMAX 100005

int n;
int a[NMAX];
int m[NMAX * VMAX];

void print(int mask)
{
    bool f = true;
    forn(i, n)
    {
        if (mask & (1 << i))
        {
            if (!f) printf(" ");
            f = false;
            printf("%d", a[i]);
        }
    }
    printf("\n");
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d:\n", tc);

    memset(m, 255, sizeof(m));
    cin >> n;
    forn(i, n) cin >> a[i];

    for1(mask, (1 << n) - 1)
    {
        int sum = 0;
        forn(i, n) if (mask & (1 << i)) sum += a[i];

        if (m[sum] != -1)
        {
            print(mask);
            print(m[sum]);
            return;
        }

        m[sum] = mask;
    }

    printf("Impossible\n");
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
