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

vi currentKeys;
vi chest;
vvi chestKeys;
vi sequence;
int n;

const string kImpossibe = "IMPOSSIBLE";
vector<vector<char> > dp;

char CanOpenChests(int opened, int mask, int prev)
{
    if (opened == n)
        return true;

    char& res = dp[prev][mask];

    if (res != -1)
        return res;

    res = 0;

    FOR(i, n)
    {
        if ((1 << i) & mask) continue;
        if (!currentKeys[chest[i]]) continue;

        --currentKeys[chest[i]];
        sequence[opened] = i + 1;
        int sz = chestKeys[i].size();
        FOR(j, sz) ++currentKeys[chestKeys[i][j]];

        if (CanOpenChests(opened + 1, mask | (1 << i), i))
            return res = 1;

        FOR(j, sz) --currentKeys[chestKeys[i][j]];
        ++currentKeys[chest[i]];
    }

    return res;
}

int main()
{
    ofstream cout ("D-small-attempt0.out");
    ifstream cin ("D-small-attempt0.in");

    int t;

    cin >> t;
    
    FOR(c, t)
    {
        currentKeys.clear();
        currentKeys.resize(201, 0);
        int k;
        cin >> k >> n;
        sequence.clear();
        sequence.resize(n, -1);
        chest.clear();
        chest.resize(n);
        chestKeys.clear();
        chestKeys.resize(n);
        dp.clear();
        dp.resize(n, vector<char>(1 << n, -1));

        FOR(i, k)
        {
            int a;
            cin >> a;
            ++currentKeys[a];
        }

        FOR(i, n)
        {
            cin >> chest[i];
            int contains;
            cin >> contains;

            FOR(j, contains)
            {
                int a;
                cin >> a;
                chestKeys[i].push_back(a);
            }
        }

        cout << PrintCase(c);

        if (CanOpenChests(0, 0, 0))
        {            
            FOR(i, n)
            {
                if (i) cout << " ";
                cout << sequence[i];
            }
            cout << endl;
        }
        else
        {
            cout << kImpossibe << endl;
        }
    }

    return 0;
}
#endif