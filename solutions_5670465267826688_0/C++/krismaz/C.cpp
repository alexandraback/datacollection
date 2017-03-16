
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <map>

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

/*
 * 1 is 1
 * 2 is i
 * 3 is j
 * 4 is k
 */

int ans[4][4] = { {1, 2, 3, 4},
                  {2, -1, 4, -3},
                  {3, -4, -1, 2},
                  {4, 3, -2, -1} };

int multQuat(int x, int y)
{
    int temp = 1;

    if (x < 0)
    {
        x *= -1;
        temp *= -1;
    }

    if (y < 0)
    {
        y *= -1;
        temp *= -1;
    }

    return temp * ans[x-1][y-1];
}

/*************************************************************************/

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(test,1,t)
    {
        LLI len, x;
        string s;

        cin >> len >> x >> s;

        if (x > 16)
            x = 16 + (x%4);

        string str;

        FOR(i,1,x)
            str += s;

        int val = 1, lookFor = 2;

        FORE(i,str)
        {
            val = multQuat(val, str[i] - 'i' + 2);

            if (lookFor < 4 && val == lookFor)
            {
                lookFor++;
                val = 1;
            }
        }

        bool ans = (lookFor == 4 && val == 4);

        cout << "Case #" << test << ": ";

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/*************************************************************************/
