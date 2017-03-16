//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define N 100010
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const	double pi = acos(-1);

int		main(){
	int	cas,tt=0;
	LL	t,r;
	scanf("%d",&cas );
	while ( cas -- ) {
		scanf("%lld%lld",  &r, &t );
		LL g = 1 , h = 1000000000ll, ans = 1;
		while ( g <= h ){
			LL	mid = (g+h)/2;
			double k = 2.0*r*mid+2.0*(mid-1)*mid+1.0*mid;
			if ( k > t+100 ) h = mid-1;
			else{
				LL	area = 2ll*r*mid+2ll*(mid-1)*mid+mid;
				if ( area > t ) h = mid-1;
				else {
					g = mid+1;
					ans = mid;
				}
			}
		}
		printf("Case #%d: %lld\n", ++tt , ans );
	}
	return 0;
}
