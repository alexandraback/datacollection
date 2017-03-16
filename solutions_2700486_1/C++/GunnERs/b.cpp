#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n, x, y;

double C(int n, int m){
	if ( n<m ) return 0;
	double ret = 1;
	int remain = n;
	int rr = m;
	for (int i=n-m+1; i<=n; i++){
		ret = ret*i;
		while ( ret>1 && remain>0 ){
			remain--;
			ret *= 0.5;
		}
		while ( ret>1 && rr>0 ){
			ret = ret/rr;
			rr--;
		}
	}
	
	while ( remain>0 ){
		remain--;
		ret*=0.5;
	}

	while ( rr>0 ){
		ret = ret/rr;
		rr--;
	}
	return ret;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("d.out","w",stdout);
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
		ret = 1-ret;
		if ( std::fabs(ret)<1e-7 ) ret = 0;
		printf("Case #%d: %.6lf\n", ++cs, ret);
	}
	return 0;
}
