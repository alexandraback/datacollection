#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, x, y;

double C(int n, int m){
	if ( n<m ) return 0;
	double ret = 1;
	for (int i=n-m+1; i<=n; i++)
		ret = ret*i;
	for (int i=1; i<=m; i++)
		ret = ret/i;
	return ret;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int tt = 0, cs=0;
	scanf("%d", &tt);
	while ( tt-- ){
		scanf("%d%d%d", &n, &x, &y);
		if ( x<0 ) x = -x;
		if ( (x+y)%2!=0 ){
			printf("Case #%d: %.6lf\n", ++cs, 0.0);
			continue;
		}
		int level = (x+y)/2;
		long long m = 0, pre = 0;
		for (int i=0; i<=level; i++){
			pre = m;
			m = m+(i*2)*2+1;
			if ( pre >= n ) break;
		}
		if ( pre>=n ){
			printf("Case #%d: %.6lf\n", ++cs, 0.0);
			continue;
		}
		if ( n>=m ){
			printf("Case #%d: %.6lf\n", ++cs, 1.0);
			continue;
		}
		n -= pre;

		y++;
		if ( n >= level*2+y ){
			printf("Case #%d: %.6lf\n", ++cs, 1.0);
			continue;
		}
		//cout<<n<<' '<<m<<' '<<pre<<endl;
		if ( x==0 ){
			printf("Case #%d: %.6lf\n", ++cs, 0);
			continue;
		}

//		int retn = y - std::max( 0, n-level*2 );
		double ret = 0;
		for (int i=0; i<=y-1; i++){
			ret += C( n, i );
		}
		for (int i=0; i<n; i++)
			ret *=0.5;

		printf("Case #%d: %.6lf\n", ++cs, 1-ret);
	}
	return 0;
}
