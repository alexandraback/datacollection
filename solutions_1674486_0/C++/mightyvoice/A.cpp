#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef map<int, int> mint;
typedef set<int> sint;

#define TWO(k)  (1<<k)
#define TWOL(k) (((LL)(1)<<(k)))
#define MP make_pair
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int oo = 210000000;
const int MAX = 1005;

int g[MAX][20];
int g1[MAX][MAX];
int dp[MAX][MAX];

int n;

bool ways()
{
    for( int k = 1; k <= n; k++)
    {
        for( int j = 1; j <= n; j++)
        {
            for( int i = 1; i <= n; i++)
            {
                dp[j][i] += dp[j][k] * dp[k][i];
                if( dp[j][i] >= 2) return 1;
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);freopen("out.txt","w",stdout);
    int t, test = 0;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case #%d: ", ++test);
        scanf("%d", &n);
        for( int i = 1; i <=n; i++)
        {
            for( int j = 1; j <= n; j++)
            {
                g1[i][j] = 0;
                dp[i][j] = 0;
            }
        }
        for( int i = 1; i <= n; i++) 
        {
            g[i][0] = 0;
            int j;
            scanf("%d", &j);
            g[i][0] = j;
            for( int k = 1; k <= j; k++) 
            {
                int tmp;
                scanf("%d", &tmp); g[i][k] = tmp;
                g1[i][tmp] = 1;
                dp[i][tmp] = 1;
            }
        }
        if( ways()) printf("Yes\n");
        else printf("No\n");


    }
    return(0);
}

