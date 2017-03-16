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

bool is_valid(const VS& strs)
{
    // string str = "";
    // REP(i,SZ(strs))
    //     str += strs[i];

    VI last_occ(100, -1);
    int idx = 0;
    REP(i, SZ(strs))
        REP(j, SZ(strs[i]))
        {
            if (last_occ[strs[i][j] - 'a'] == -1 || last_occ[strs[i][j] - 'a'] == idx-1)
            {
                last_occ[strs[i][j] - 'a'] = idx;
            }
            else
            {
                return false;
            }

            ++idx;
        }

    return true;
}

int fact(int n)
{
    if (n < 2)
        return 1;

    return n * fact(n-1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        cin >> N;

        VS strs(N);

        map<string, int> sstr;
        REP(i,N)
        {
            cin >> strs[i];
            ++sstr[strs[i]];
        }

        int factor = 1;

        FRE(it, sstr)
        {
            factor *= fact(it->second);
        }

        sort(ALL(strs));
        int cnt = 0;

        do
        {
            cnt += (is_valid(strs)) * factor;
        }
        while (next_permutation(ALL(strs)));

        cout << "Case #" << t+1 << ": ";
        cout << cnt << endl;
    }

    return 0;
}
