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

int pow2(ll& p)
{
    ll x = 0;
    int res = 0;
    while (p)
    {
        res++;
        x += p % 2;
        p /= 2;        
    }
    p = x;
    return res;
}

ll gcd(ll a, ll b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}
void solve(int test)
{
    printf("Case #%d: ", test);

    ll p, q;
    scanf("%I64d/%I64d\n", &p, &q);

    ll d = gcd(p, q);
    p /= d;
    q /= d;

    int q1 = pow2(q);
    if (q != 1)
    {
        printf("impossible\n");
        return;
    }

    int p1 = pow2(p);

    cout << q1 - p1 << endl;
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
