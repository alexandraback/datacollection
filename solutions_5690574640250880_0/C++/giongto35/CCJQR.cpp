#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn = 60;
int R,C,M,T;
char A[maxn][maxn];
int need;

void fill (int y1, int x1, int y2, int x2, char c)
{
    for (int i = y1 ; i <= y2; i++)
    for (int j = x1 ; j <= x2; j++)
    A[i][j] = c;
}

bool process()
{
    if (M == 0)
    {
        fill (1,1,R,C,'.');
        A[1][1] = 'c';
        return true;
    }
    if (need == 1)
    {
        fill (1,1,R,C,'*');
        A[1][1] = 'c';
        return true;
    }
    fill (1,1,R,C,'*');
        for (int h = min(R,2); h <= R; h++)
        for (int w = min(C,2); w <= C; w++)
        {
            int rem = need - h * w;
            if (rem == 0)
            {
                fill(1,1,h,w,'.');
                A[1][1] = 'c';
                return true;
            }
            else
            if (rem < w && rem >= 2 && h < R)
            {
                fill(1,1,h,w,'.');
                fill(h+1,1,h+1,rem,'.');
                A[1][1] = 'c';
                return true;
            }
            else
            if (rem < h && rem >= 2 && w < C)
            {
                fill(1,1,h,w,'.');
                fill(1,w+1,rem,w+1,'.');
                A[1][1] = 'c';
                return true;
            }
            else
            if (rem <= w + h && h < R && w < C)
            {
                for (int r1 = 2; r1 <= min(h,rem); r1++)
                {
                    int r2 = rem - r1;
                    if (r2 >= 2 && r2 <= w)
                    {
                        fill(1,1,h,w,'.');
                        fill(h+1,1,h+1,r2,'.');
                        fill(1,w+1,r1,w+1,'.');
                        A[1][1] = 'c';
                        return true;
                    }
                }
            }
        }
        return false;
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("CCJQR.out","w",stdout);
    //scanf("%d",&T);
    cin>>T;
    for (int st = 1; st <= T; st++)
    {
        scanf("%d%d%d",&R,&C,&M);
        need = R * C - M;
        fill(1,1,R,C,'*');
        printf("Case #%d:\n",st);
        if (process() == false)
        {
            printf("Impossible\n");
        }
        else
        {
            for (int i = 1; i <= R; i++)
            {
                for (int j = 1; j <= C; j++)
                printf("%c",A[i][j]);
                printf("\n");
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

