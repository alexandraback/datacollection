
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
    int n;
    cin >> n;

    vector < pair < LLI , LLI > > hiker;

    while (n--)
    {
        LLI d, h, m;
        cin >> d >> h >> m;

        FOR(i,1,h)
            hiker.PB( MP(d, m++) );
    }

    if (SIZE(hiker) <= 1)
        return 0;

    sort(hiker.begin(), hiker.end());

    LLI pos[] = {hiker[0].ST, hiker[1].ST},
        time[] = {hiker[0].ND, hiker[1].ND};

    LLI diff = 360 + pos[0] - pos[1];

    if (time[0] == time[1])
        return 0;
    else if (time[0] > time[1]) // v1 < v2
        return (diff * time[1] <= (360LL - pos[0]) * (time[0] - time[1]));
    else
        return (time[1] * (360LL - pos[1]) >= time[0] * (720LL - pos[0]));
}

/*************************************************************************/

int main()
{
    int t;
    cin >> t;

    FOR(i,1,t)
        cout << "Case #" << i << ": " << solve() << '\n';
}

/*************************************************************************/
