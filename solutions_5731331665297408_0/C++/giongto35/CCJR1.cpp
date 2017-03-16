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
string F[20][10][10][1<<10];
string st[maxn];
vector<int> a[maxn];
int u,v,T,n,m;

string min(string a, string b)
{
    if (a == "") return b;
    if (a < b) return a; else return b;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("CCJR1.out","w",stdout);
    scanf("%d",&T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d%d",&n,&m);
        getline(cin,st[0]);
        for (int i = 0; i < n; i++)
        {
            a[i].clear();
            getline(cin,st[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int l = 0; l < 2*(n-1); l++)
        for (int j = 0; j < (1<<n); j++)
        for (int i = 0; i < n; i++)
        for (int bd = 0; bd < n; bd++)
            F[l][bd][i][j]= "";

        for (int i = 0; i < n; i++)
            F[0][i][i][1<<i] = st[i];
        string res = "";
        for (int l = 0; l < 2*(n-1); l++)
        for (int j = 1; j < (1<<n); j++)
        for (int i = 0; i < n; i++)
        for (int bd = 0; bd < n; bd++)
        {
            if (F[l][bd][i][j] == "") continue;
            /*if (j == (1 << n) - 1)
            {
                if (minl == oo) minl = l;
                res = min(res,F[l][i][j]);
                continue;
            }*/
                for (int k = 0; k < (int)a[i].size(); k++)
                {
                    int v = a[i][k];
                    if ((j | (1 << v)) != j)
                        F[l+1][bd][v][j | (1 << v)] = min(F[l+1][bd][v][j | (1 <<v )],F[l][bd][i][j] + st[v]);
                    else
                        F[l+1][bd][v][j | (1 << v)] = min(F[l+1][bd][v][j | (1 <<v )],F[l][bd][i][j]);
                }
        }
        for (int i = 0; i < n; i++)
        {
            res = min(res,F[(n-1)*2][i][i][(1<<n)-1]);
        }
        cout<<"Case #"<<x<<": ";
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
