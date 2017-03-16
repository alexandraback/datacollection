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

#define maxn 2000000 + 10

int hash[maxn];
int c[30];

int main()
{
    int T,Test;
    int a,b,i,j,k,t,s,p,ans;
    
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    
    scanf("%d",&Test);
    for( T = 1 ; T <= Test ; ++T )
        {
            scanf("%d%d",&a,&b);
            ans = 0;
            for( i = a ; i <= b ; ++i )
                {
                    s = 0;
                    for( k = 0, j = i ; j ; j /= 10 )
                        ++k;
                    for( p = 1, j = 1 ; j < k ; ++j )
                        p *= 10;
                    for( t = i, j = 1 ; j <= k ; ++j )
                        {
                            if( t >= a && t <= b && hash[t] != T )
                                hash[t] = T, ++s;
                            t = t/10 + t%10*p;
                        }
                    ans += s*(s-1)/2;
                }
            printf("Case #%d: %d\n",T,ans);
        }
    
    return 0;
}
