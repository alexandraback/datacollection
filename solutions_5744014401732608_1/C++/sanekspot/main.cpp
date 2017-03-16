#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <utility>
#include <ctime>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

// template end

const int MAX_B = 55;
int matr[MAX_B][MAX_B];

void solve()
{
    ll b, m;
    cin >> b >> m;

    ll max_ways = 1LL << (b - 2);

    if (m > max_ways)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE" << endl;
    ZERO(matr);

    for (int i = 1; i < b; ++i)
    {
        for (int j = i + 1; j < b; ++j)
        {
            matr[i][j] = 1;
        }
    }

    matr[0][b - 1] = 1;
    --m;
    for (int i = 0; i < b; ++i)
    {
        if ((m >> i) & 1)
        {
            matr[0][b - i - 2] = 1;
        }
    }

    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            cout << matr[i][j];
        }
        cout << endl;
    }

}

int main()
{
#ifdef XXX
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#elif defined CONTEST
    freopen(CONTEST".in", "r", stdin);
    freopen(CONTEST".out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; ++tc)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}