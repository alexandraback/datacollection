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
#include <climits>
#include <cfloat>
#include <cstring>
#include <ctime>
#include <cassert>

#define REP(k,a) for(int k = 0; k < (a); ++k)
#define FOR(k,a,b) for(int k=(a); k < (b); ++k)
#define FRE(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define CLR(c) memset((c), 0, sizeof(c))
#define VCLR(v) fill((v).begin(), (v).end(), 0)
#define PB push_back
#define MP make_pair
#define DBG(x) std::cerr << #x" = " << x << std::endl
#define I1 first
#define I2 second

const int INF = 1000000000;

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<pair<int,int> > VII;
typedef long long LL;
typedef long double LD;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        LL P, Q;
        scanf("%lld/%lld", &P, &Q);
        LL gcd = __gcd(P, Q);
        P /= gcd;
        Q /= gcd;

        cout << "Case #" << t+1 << ": ";

        if (Q != 0 && (Q & (Q-1)))
        {
            cout << "impossible" << endl;
            continue;
        }

        int cnt = 1;

        while (2LL * P < Q)
        {
            P *= 2LL;
            ++cnt;
        }

        cout << cnt << endl;
    }

    return 0;
}
