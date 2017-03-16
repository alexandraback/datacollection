
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

int prefsuflen(string w)
{
    int N = SIZE(w);

    vector < int > pre(N+1,-1);
    int b = -1;

    FOR(i,1,N)
    {
        while ( (b>-1) and (w[b] != w[i-1]) ) b = pre[b];
        ++b;
        pre[i]=b;
    }

    return pre.back();
}

#define AL ('Z' - 'A' + 1)

double solve()
{
    int k, l, s;
    cin >> k >> l >> s;

    VI cnt(AL,0);

    string keys;
    cin >> keys;

    FORE(i,keys)
        cnt[ keys[i] - 'A' ]++;

    string target;
    cin >> target;

    double chance = 1.0;
    bool possible = 1;

    int pos = max(0, s - l + 1);

    FORE(i,target)
    {
        int c = target[i] - 'A';
        chance *= ( cnt[c] / ((double) k) );

        if (!cnt[c])
            possible = 0;
    }

    chance *= pos;

    int ensure = 0;

    if (possible && s >= l)
    {
        ensure = 1;

        int everyNext = l - prefsuflen(target);
        ensure += (s - l)/everyNext;
    }

    return (ensure - chance);
}

/*************************************************************************/

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t)
    {
        cout.precision(10);
        cout << "Case #" << i << ": " << fixed << solve() << '\n';
    }

    return 0;
}

/*************************************************************************/
