#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <list>
#include <ctime>

#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> lint;

const int N = (int)(1e2) + 7;
const ll MD = 1000000000;
const int KOL = 9;
const int M = (int)(1e6) + 7;
const ll INF = (ll)(1e9) + 7;
const ll MOD = (ll)(1e9) + 7;
const ld eps = 1e-12;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ii = 1; ii <= tt; ++ii)
    {
        int a, b, c;
        cin >> a >> b >> c;
        printf("Case #%d: ", ii);
        int kol = 0;
        for (int i = 0; i < a; ++i)
            for (int j = 0; j < b; ++j)
                if ((i & j) < c)
                    ++kol;
        cout << kol << endl;
    }
    return 0;
}
