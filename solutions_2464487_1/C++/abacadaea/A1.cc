#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const double PI = acos (-1.0), EPS = 1e-9;
const int INF = 1e9, MOD = 1e9 + 7;
const int mx [] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

ld sq (ld a)
{
    return a * a;
}

void go (int T)
{
    ll r, t;
    cin >> r >> t;
    ll f = 2 * r + 1;
    ll res = (ll)(sqrt ((ld)t / 2.0 + sq((ld)(f - 2.0) / 4.0)) - ((ld)(f - 2.0) / 4.0) + EPS);
    printf ("Case #%d: ", T); 
    printf ("%llu\n", res);
}

int main()
{
    int T; cin >> T;
    for (int i=0; i<T; i++)
    {
	go (i + 1);
    }
}
