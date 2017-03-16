//#pragma comment (linker, "/STACK:263108864")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const li lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

int TESTS = -1, TEST_NOW = 1;

void start ()
{
    freopen ("problem.in", "r", stdin);
    freopen ("problem.out", "w", stdout);
    cin >> TESTS;
}

int main ()
{
    if (TESTS < 0)
        start ();
    if (TEST_NOW > TESTS)
        return 0;
    cout << "Case #" << TEST_NOW << ": ";

    double prod = 2;
    double C, F, X;
    double time = 0, ans;
    cin >> C >> F >> X;
    ans = X;
    while (time + X / prod < ans)
    {
        ans = time + X / prod;
        time += C / prod;
        prod += F;
    }
    printf ("%.7lf\n", ans);

case_end:
    ++TEST_NOW;
    main ();
}
