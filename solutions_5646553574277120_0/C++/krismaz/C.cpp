
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

bool next(int *T, int v)
{
    T[0]++;

    int it = 0;

    while (it < 5 && T[it] > v)
    {
        T[it++] = 0;
        T[it]++;
    }

    return (it < 5);
}

bool check(VI &T, int v)
{
    sort(T.begin(), T.end());

    FOR(i,1,SIZE(T)-1)
        if (T[i] == T[i-1]) return 0;

    VB vis(v+1,0);
    vis[0] = 1;

    FORE(i,T)
    {
        VB temp = vis;

        FOR(j,T[i],v) if (vis[j-T[i]])
            temp[j] = 1;

        vis = temp;
    }

    FORE(i,vis)
        if (!vis[i]) return 0;

    return 1;
}

int solve()
{
    int c, d, v;
    cin >> c >> d >> v;

    VI D(d);
    FORE(i,D) cin >> D[i];

    int T[4] = {0, 0, 0, 0};

    do
    {
        VI temp = D;

        FOR(i,0,3) if (T[i] > 0)
            temp.PB(T[i]);

        if (check(temp, v))
            return (SIZE(temp) - d);
    } while(next(T, v));

    return 5;
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
