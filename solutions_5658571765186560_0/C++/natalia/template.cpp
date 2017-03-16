#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

#define pi 3.14159265358979323846

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int n, k;

void solve(int test)
{
    printf("Case #%d: ", test + 1);

    int x, r, c; cin >> x >> r >> c;

    if (x >= 7 || x > max(r, c) || (r * c) % x != 0)
    {
        cout << "RICHARD\n";
        return;
    }

    if ((x >= 3 && min(r, c) == 1) || (x == 4 && min(r, c) == 2))
    {
        cout << "RICHARD\n";
        return;
    }

    cout << "GABRIEL\n"; 
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; cin >> tc;
    forn(it, tc) solve(it);

    return 0;
}

