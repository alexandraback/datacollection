
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define MIN(x,y) ( ((x) < (y))? (x) : (y) )
#define MAX(x,y) ( ((x) > (y))? (x) : (y) )
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define INF 1000000001

using namespace std;

typedef pair < int , int > PII;
typedef long long int LLI;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;

int solve()
{
    int r, c, w;
    cin >> r >> c >> w;

    VI dp(c+1,0);

    dp[w] = w;

    FOR(i,w+1,min(c,2*w-1))
        dp[i] = w + 1;

    FOR(i,2*w,c)
        dp[i] = 1 + max(dp[i-w], w);

    return dp[c] + (r - 1) * (dp[c] - w + 1);
}

/*************************************************************************/

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t)
        cout << "Case #" << i << ": " << solve() << '\n';

    return 0;
}

/*************************************************************************/
