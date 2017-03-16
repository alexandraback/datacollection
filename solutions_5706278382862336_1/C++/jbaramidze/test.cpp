#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <string.h>
#include <climits>
#include <limits>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FORE(i, a, b) for(int i=a; i<=b; i++)
#define ll long long
#define mp make_pair
#define mtriple(a, b, c) make_pair(a, make_pair(b, c))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define tripleii pair<int, pair<int ,int> >
#define triplell pair<long long, pair<long long ,long long> >
#define PI 3.14159265359
#define mod 1000000007
#define ceil(a, b) ((a)/(b) + ((a)%(b)!=0))
#define square(a) ((a)*(a))
#define debug3(names, a, b, c) cout << names << a << ", " << b << ", " << c << endl;
#define debug2(names, a, b) cout << names << a << ", " << b << endl;
#define debug1(names, a) cout << names << a << endl;

#define maxN 100000+6

ll gcd(ll u, ll v)
{
    return (v != 0) ? gcd(v, u % v) : u;
}

int main()
{

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ll p, q, T;
    char c;
    cin >> T;
    FOR(awt, 0, T)
    {
        cin >> p >> c >> q;

        ll rr = gcd(p, q);
        p /= rr;
        q /= rr;
        if ((q & (q - 1)) != 0)
        {
            printf("Case #%d: impossible\n", awt + 1);
            continue;
        }
        ll i = 1;
        for (q /= 2; q >= 1; q /= 2)
        {
            if (p >= q)
            {
                printf("Case #%d: %d\n", awt + 1, i);
                break;
            }
            i++;
            if (i > 40)
            {
                printf("Case #%d: impossible\n", awt + 1);
                break;
            }
        }

    }

    return 0;
}