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

int p10[10];
int d[10];
int s[10];

void solve(int tc)
{
    cerr << tc << endl;  
    printf("Case #%d: ", tc);
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    int v[10];
    for (int x = a; x <= b; x++)
    {
        int y = x;
        int k = 0;
        while (y)
        {
            d[k++] = y % 10;
            y /= 10;    
        }    
        reverse(d, d + k);

        int r = 0;
        for (int i = k - 1; i >= 0; i--)
        {
            r += d[i] * p10[k - 1 - i];
            s[i] = r;    
        }

        r = 0;
        int cnt = 0;

        forn(i, k - 1)
        {
            r = r * 10 + d[i];
            int z = r + s[i + 1] * p10[i + 1];

            if (z >= a && z <= b && z != x) v[cnt++] = z;
        }

        sort(v, v + cnt);
        ans += int(unique(v, v + cnt) - v);
    } 

    cout << ans / 2 << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    p10[0] = 1;
    for1(i, 9) p10[i] = p10[i - 1] * 10;
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
