#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

void solve(int test)
{
    printf("Case #%d: ", test);

    int n, m, k;
    cin >> n >> m >> k;

    if (n <= 2 || m <= 2 || k < 5)
    {
        cout << k << endl;
        return;        
    }

    if (n > m) swap(n, m);

    if (n == 3)
    {
        if (m == 6 && k >= 14) cout << k - 4;
        else if (m >= 5 && k >= 11) cout << k - 3;
        else if (m >= 4 && k >= 8) cout << k - 2;
        else cout << k - 1;
    }
    else //n = 4
    {
        if (m == 5 && k >= 16) cout << k - 6;
        else if (m == 5 && k >= 14) cout << k - 5;
        else if (k >= 12) cout << k - 4;
        else if (k >= 10) cout << k - 3;
        else if (k >= 8) cout << k - 2;
        else cout << k - 1;
    }
    cout << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
