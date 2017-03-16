
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

/*************************************************************************/

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(test,1,t)
    {
        int x, r, c;
        cin >> x >> r >> c;

        int area = r * c;

        bool ans = 1;

        if (area%x == 0)
        {
            if (x <= 2)
                ans = 0;
            else if (x == 3)
            {
                if (area > 3)
                    ans = 0;
            }
            else if (x == 4)
            {
                if (area >= 12)
                    ans = 0;
            }
        }

        cout << "Case #" << test << ": ";

        if (ans) cout << "RICHARD\n";
        else cout << "GABRIEL\n";
    }

    return 0;
}

/*************************************************************************/
