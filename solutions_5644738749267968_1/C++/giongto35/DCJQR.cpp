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

const int maxn = 1000+10;
double a[maxn];
double b[maxn];
double a2[maxn];
double b2[maxn];
bool c[maxn];
int T,n;
int main()
{
    freopen("D-large.in","r",stdin);
    freopen("DCJQR.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) scanf("%lf",&a2[i]);
        for (int j = 1; j <= n; j++) scanf("%lf",&b2[j]);
        int res1 = 0;
        int res2 = 0;
        sort(a2+1,a2+1+n);
        sort(b2+1,b2+1+n);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for (int x = 1; x <= n; x++)
        {
            for (int i = 1; i <= n; i++)
                a[i] = a2[i],b[i] = b2[i];
            int rest = 0;
            int j = 1;
            for (int i = x; i <= n; i++)
                if (a[i] > b[j++]) rest++;
            res1 = max(res1,rest);
        }
        for (int i = 1; i <= n; i++)
            a[i] = a2[i],b[i] = b2[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        memset(c,true,sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            bool ok = false;
            for (int j = 1; j <= n; j++)
            {
                if (b[j] > a[i] && c[j])
                {
                    c[j] = false;
                    ok = true;
                    break;
                }
            }
            if (ok == false)
            {
                res2++;
                for (int j = 1; j <= n; j++)
                {
                    if (c[j])
                    {
                        c[j] = false;
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %d %d\n",st,res1,res2);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

