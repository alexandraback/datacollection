
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

int rev(int x)
{
    VI dig;

    while (x > 0)
    {
        dig.PB(x%10);
        x /= 10;
    }

    int ans = 0;

    FORE(i,dig)
    {
        ans *= 10;
        ans += dig[i];
    }

    return ans;
}

/*************************************************************************/

int main()
{
    ios_base::sync_with_stdio(0);

    int N = 10000000;
    VVI G(N);

    FOR(i,1,N-1)
    {
        G[i].PB(i+1);
        G[i].PB(rev(i));
    }

    VI dist(N,INF);

    queue < int > Q;

    Q.push(1);
    dist[1] = 1;

    while (!Q.empty())
    {
        int q = Q.front();
        Q.pop();

        FORE(i,G[q]) if (dist[ G[q][i] ] == INF)
        {
            int v = G[q][i];

            dist[v] = dist[q] + 1;
            Q.push(v);
        }
    }

    int t;
    cin >> t;

    FOR(i,1,t)
    {
        int n; cin >> n;
        cout << "Case #" << i << ": " << dist[n] << '\n';
    }

    return 0;
}

/*************************************************************************/
