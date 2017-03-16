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

#define maxn 2000 + 10

int n,i,j,k,t,tmp;
int c[maxn],hash[maxn];
PRII a[maxn],b[maxn];
priority_queue< int > que;

void add()
{
	while( j <= n && t >= a[j].x )
		que.push(c[a[j++].y]);
}

int main()
{
    int T,Test;
	
	freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    
	scanf("%d",&Test);
	for( T = 1 ; T <= Test ; ++T )
		{
			scanf("%d",&n);
			for( i = 1 ; i <= n ; ++i )
				{
					scanf("%d%d",&a[i].x,&b[i].x);
					a[i].y = b[i].y = i;
				}
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			for( i = 1 ; i <= n ; ++i )
				c[b[i].y] = i;

			while( Size(que) )
				que.pop();
			t = k = 0;
			memset(hash,0,sizeof hash);
			for( i = 1, j = 1 ; i <= n ; ++i )
				{
					add();
					while( t < b[i].x && Size(que) )
						{
							tmp = que.top();
							if( tmp >= i )
								{	
									que.pop();
									hash[tmp] = 1;
									++t, ++k;
									add();
								}
							else break;
						}
					if( t < b[i].x )
						break;
					t += 2-hash[i];
				}

			if( t == 2*n )
				printf("Case #%d: %d\n",T,k+n);
			else printf("Case #%d: Too Bad\n",T);
		}

    return 0;
}
