#define ENABLE_MAIN 1
#if ENABLE_MAIN


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <list>
#include <queue>
#include <numeric>
#include <iomanip>
#include <fstream>


using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<ll, ll> PLL;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

const ll oo = 1LL << 60;
const int kNumMoves = 4;
const int kMoves[kNumMoves][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

#define FOR(i, n) for (int i = 0; i < int(n); ++i)
#define FORI(i, s, n) for (int i = s; i < int(n); ++i)
#define FORD(i, n) for (int i = n - 1; i >= 0; --i)
#define VALID(i, mx) (i >= 0 && i < mx)

string PrintCase(int i)
{     
    ostringstream os;
    os << "Case #" << (i + 1) << ": ";
    return os.str();
}
int E, R, N;
vl val;
vvl dp;

ll GetMaxGain(int idx, int energy)
{
    if (idx == N)
        return 0;
    ll &res = dp[energy][idx];
    if (res != -1)
        return res;
     
    res = 0;    

    FOR(i, energy + 1)
    {
        int newEnergy = min(E, energy - i + R);
        ll gain = val[idx] * i + GetMaxGain(idx + 1, newEnergy);
        res = max(res, gain);
    }
    
    return res;
}

int main()
{
    ofstream cout ("B-small-attempt1.out");
    ifstream cin ("B-small-attempt1.in");

    int numCases;
    cin >> numCases;    
    FOR(cs, numCases)
    {
        
        cin >> E >> R >> N;
        val.clear();
        val.resize(N);
        FOR(i, N) cin >> val[i];

        if (R >= E)
        {
            ll sum = accumulate(val.begin(), val.end(), 0LL);
            ll rs = sum * E;
            cout << PrintCase(cs) << rs << endl;
            continue;
        }

        dp.clear();
        dp.resize(E + 1, vl(N + 1, -1));


        ll res = GetMaxGain(0, E);

        cout << PrintCase(cs) << res << endl;
    }

    int i;
    cin >> i;

    return 0;
}
#endif