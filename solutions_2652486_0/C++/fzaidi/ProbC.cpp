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
int R, N, M, K;
vvi subsets;

 map<int, vvi> values;

 void GenerateValues()
 {
     vi cards;
     
     FORI(i, 2, M + 1)
         values[i].push_back(vi(i, 1));


     FORI(i, 2, M + 1)
         cards.push_back(i);

     FOR(i, cards.size()) FOR(j, cards.size())     
     {
         int v = cards[i] * cards[j];
         vi tmp;
         tmp.push_back(cards[i]), tmp.push_back(cards[j]);
         values[v].push_back(tmp);
     }

     FOR(i, cards.size()) FOR(j, cards.size()) FOR(k, cards.size())
     {
         int v = cards[i] * cards[j] * cards[k];
         vi tmp;
         tmp.push_back(cards[i]), tmp.push_back(cards[j]), tmp.push_back(cards[k]);
         values[v].push_back(tmp);
     }
 }


vi DetermineValues(int idx)
{
    vi& vals = subsets[idx];

    vvi subs(3);

    sort(vals.begin(), vals.end());

    vvi cands;

    FORD(i, K)
    {
        int v = vals[i];
        if (!values.count(v)) continue;

        vvi& vals = values[v];
        FOR(i, vals.size())
        {
            if (vals[i].size() == N) 
                return vals[i];
        }
    }

    vi res;

    FOR(i, cands.size())
    {
        if (cands[i].size() > res.size())
        {
            res = cands[i];
        }
    }

    while (res.size() < N)
        res.push_back(2);

    return res;
}

int main()
{
    ofstream cout ("C-small-1-attempt0.out");
    ifstream cin ("C-small-1-attempt0.in");


    int numCases;
    cin >> numCases;    
    FOR(cs, numCases)
    {
        cin >> R >> N >> M >> K;
        subsets.resize(R);

        FOR(i, R) FOR(j, K)
        {
            int a;
            cin >> a;
            subsets[i].push_back(a);
        }

        cout << PrintCase(cs) << endl;

        GenerateValues();

        FOR(i, R)
        {
            vi val = DetermineValues(i);
            FOR(j, N)
                cout << val[j];

            cout << endl;
        }
    }

    int i;
    cin >> i;

    return 0;
}
#endif