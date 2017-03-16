#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ll> pt;

int T;
ll r, t;

int main()
{
    ios::sync_with_stdio(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
        cin >> r >> t;
        ll lo = 0, hi = min(t/(2*r), 1000000000ll) + 1;
        while (lo < hi)
        {
            ll mid = (lo + hi + 1) / 2;
            if (mid*(2*r+2*mid-1) <= t)
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << "Case #" << z << ": " << lo << endl;
    }
}
