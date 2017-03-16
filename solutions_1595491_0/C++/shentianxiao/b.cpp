#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

typedef long long LL;
typedef vector< string > VS;
typedef vector< int > VI;
typedef pair< int, int > PRII;
typedef pair< double, double > PRDD;

#define p_b push_back
#define m_p make_pair
#define x first
#define y second

#define Size(a) ((int)a.size())
#define sqr(x) ((x)*(x))

#define oo 1000000000
#define eps 1e-9
const double pi = acos(-1.0);

#define maxn 100 + 10
#define maxm 30 + 5

int a[maxm],b[maxm];
int t[maxn];
int f[maxn][maxn];

int main()
{
    int T,Test;
    int n,s,p;
    int i,j,k;
    
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    
    memset(a,-1,sizeof a);
    memset(b,-1,sizeof b);
    for( i = 0 ; i <= 10 ; ++i )
        for( j = i ; j <= 10 && j <= i+2 ; ++j )
            for( k = j ; k <= 10 && k <= i+2 ; ++k )
                {
                    if( k-i == 2 )
                        a[i+j+k] = max(a[i+j+k],k);
                    else b[i+j+k] = max(b[i+j+k],k);
                }
    
    scanf("%d",&Test);
    for( T = 1 ; T <= Test ; ++T )
        {
            scanf("%d%d%d",&n,&s,&p);
            for( i = 1 ; i <= n ; ++i )
                scanf("%d",&t[i]);
            
            for( i = 0 ; i <= n ; ++i )
                for( j = 0 ; j <= s ; ++j )
                    f[i][j] = -oo;
            f[0][0] = 0;
            for( i = 1 ; i <= n ; ++i )
                for( j = 0 ; j <= s ; ++j )
                    {
                        if( j && a[t[i]] != -1 )
                            f[i][j] = max(f[i][j],f[i-1][j-1]+(a[t[i]] >= p));
                        if( b[t[i]] != -1 )
                            f[i][j] = max(f[i][j],f[i-1][j]+(b[t[i]] >= p));
                    }
            printf("Case #%d: %d\n",T,f[n][s]);
        }
    
    return 0;
}
