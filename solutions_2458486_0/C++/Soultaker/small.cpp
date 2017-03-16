#include <assert.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i = int(a); i < int(b); ++i)
#define REP(i,n)   FOR(i,0,n)

struct Chest { int type; vector<int> keys; };
static vector<Chest> C;  /* list of all chests */
static vector<int>   S;  /* inital set of keys */

static signed char memo[1<<20];  /* caches results for possible() */

bool possible(map<int,int> &keys, unsigned unopened)
{
    if (unopened == 0) return true;
    signed char &m = memo[unopened];
    if (m >= 0) return m;
    for (int i = 0; (1u<<i) <= unopened; ++i)
    {
        if ((unopened & (1u<<i)) && keys[C[i].type] > 0)
        {
            --keys[C[i].type];
            REP(j, C[i].keys.size()) ++keys[C[i].keys[j]];
            unopened -= 1u<<i;
            if (possible(keys, unopened)) return (m = true);
            unopened += 1u<<i;
            REP(j, C[i].keys.size()) --keys[C[i].keys[j]];
            ++keys[C[i].type];
        }
    }
    return (m = false);
}

bool possible(const vector<int> &start)
{
    unsigned unopened = (1u << C.size()) - 1; 
    map<int,int> keys;
    REP(s, S.size()) ++keys[S[s]];
    REP(s, start.size()) {
        int i = start[s];
        if ((unopened & (1u<<i)) && keys[C[i].type] > 0) {
            --keys[C[i].type];
            REP(j, C[i].keys.size()) ++keys[C[i].keys[j]];
            unopened -= 1u<<i;
        } else return false;
    }
    return possible(keys, unopened);
}

int main()
{
    int cases = 0, caseno;
    cin >> cases;
    for (caseno = 1; caseno <= cases; ++caseno)
    {
        int N = 0, K = 0;
        cin >> K >> N;
        S = vector<int>(K);
        REP(k, K) cin >> S[k];
        C = vector<Chest>(N);
        REP(n, N) {
            int L = 0;
            cin >> C[n].type >> L;
            C[n].keys = vector<int>(L);
            REP(l, L) cin >> C[n].keys[l];
        }
        assert(cin);
        cout << "Case #" << caseno << ":";
        memset(memo, -1, sizeof(memo));
        vector<int> start;
        if (!possible(start))
        {
            cout << " IMPOSSIBLE";
        }
        else
        {
            while ((int)start.size() < N)
            {
                start.push_back(0);
                while (!possible(start))
                {
                    start.back()++;
                    assert(start.back() < N);
                }
                cout << ' ' << (start.back() + 1);
            }
        }
        cout << endl;
    }
    return 0;
}
