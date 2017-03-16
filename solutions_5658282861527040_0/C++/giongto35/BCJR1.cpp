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

const int maxn = 100;
long long F[maxn][2][2][2];
long long A;
long long B;
int T;
long long K;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("BCJR1.out","w",stdout);
    scanf("%d",&T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%lld%lld%lld",&A,&B,&K);
        memset(F,0,sizeof(F));
        F[50][0][0][0] = 1;
        for (int i = 50; i > 0; i --)
        {
            int s1 = (A >> (i-1)) & 1;
            int s2 = (B >> (i-1)) & 1;
            int s3 = (K >> (i-1)) & 1;
            for (int j = 0; j <= 1; j++)
            for (int k = 0; k <= 1; k++)
            for (int l = 0; l <= 1; l++)
            for (int jj = 0; jj <= 1; jj++)
            for (int kk = 0; kk <= 1; kk++)
            for (int ll = 0; ll <= 1; ll++)
            {
                if ((j == 0) && (jj > s1)) continue;
                if ((k == 0) && (kk > s2)) continue;
                if ((l == 0) && (ll > s3)) continue;
                if ((jj & kk) == ll)
                {
                    F[i-1][j | (jj < s1)][k | (kk < s2)][l | (ll < s3)] =
                    F[i-1][j | (jj < s1)][k | (kk < s2)][l | (ll < s3)] + F[i][j][k][l];
                }
            }
        }
        long long res = 0;
/*        for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 1; k++)
        for (int l = 0; l <= 1; l++)
        {
            res += F[0][j][k][l];
        }*/
        printf("Case #%d: %d\n",x,F[0][1][1][1]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

