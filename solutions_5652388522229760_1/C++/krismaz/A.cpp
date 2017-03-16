
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

int solve(int n) {
    VB dig(10,0);

    for (int i = n; ; i += n) {
        int j = i;
        while (j) {
            dig[j%10] = 1;
            j /= 10;
        }

        bool all = true;
        FOR(j,0,9) all = all && dig[j];

        if (all) {
            return i;
        }
    }
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t) {
        int n;
        cin >> n;

        cout << "Case #" << i << ": ";

        if (!n) cout << "INSOMNIA";
        else cout << solve(n);

        cout << '\n';
    }

    return 0;
}

/*************************************************************************/

