#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

typedef long long LL;
typedef pair< int, int > PRII;
typedef pair< double ,double > PRDD;
typedef vector< string > VS;
typedef vector< int > VI;

#define Size(a) ((int)a.size())
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

#define x first
#define y second
#define p_b push_back
#define m_p make_pair
#define oo 1000000000
#define eps 1e-12
const double pi = acos(-1.0);

#define maxn 100000 + 10

int n,m;
double f[maxn],p,q,ans;

int main()
{
    int T,Test,i;

	freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    
	scanf("%d",&Test);
	for( T = 1 ; T <= Test ; ++T )
		{
			q = 1;
			scanf("%d%d",&n,&m);
			for( i = 1 ; i <= n ; ++i )
				{
					scanf("%lf",&p);
					f[i] = f[i-1] + q*(1-p);
					q *= p;
				}
			ans = m+2;
			for( i = 0 ; i <= n ; ++i )
				ans = min(ans,f[i]*(m+1)+n-i+m-i+1);
			printf("Case #%d: %.10lf\n",T,ans);
		}

    return 0;
}
