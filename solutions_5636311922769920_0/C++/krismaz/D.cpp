
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const LLI LLINF = 1000000000000000001LL;

/*************************************************************************/

bool solve(int k, int c, int s, VL &ans) {
    if (s * c < k) return false;

    VVL sequences(1);

    FOR(d,0,k-1) {
        if (SIZE(sequences.back()) == c) {
            sequences.emplace_back();
        }

        sequences.back().PB(d);
    }

    FORE(i,sequences) {
        LLI num = 0;
        FORE(j,sequences[i]) {
            num *= k;
            num += sequences[i][j];
        }

        ans.PB(num);
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t) {
        int k, c, s;
        cin >> k >> c >> s;

        cout << "Case #" << i << ": ";

        VL ans;
        if (solve(k, c, s, ans)) {
            for (LLI p : ans) {
                cout << 1 + p << ' ';
            }
        } else {
            cout << "IMPOSSIBLE";
        }

        cout << '\n';
    }

    return 0;
}

/*************************************************************************/

