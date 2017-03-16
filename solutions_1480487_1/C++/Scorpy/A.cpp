#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdio>
using namespace std;


pair<int,int> a [300];

double res [300];

int sum [300];

void solve(){
	int n;
	scanf("%d", &n);



	int s = 0;
	for( int i = 0; i < n; i++ ){
		res[i] = 0;
		scanf("%d", &a[i].first);
		a[i].second = i;
		s+=a[i].first;
	}

	sort(a, a+n);
	sum[0] = a[0].first;
	for( int i = 1; i < n; i++ )
		sum[i] = sum[i-1] + a[i].first;

	int sz = n;
	for( ; sz>0; ){
		if( a[sz-1].first <= double(sum[sz-1]+s) / sz ) break;
		sz--;
	}

	double need = double(s+sum[sz-1])/sz;

	for( int i = 0; i < sz; i++ ){
		double left =  need - a[i].first;
		if( left<0 ) 
			res[ a[i].second ] = 0;
		else
			res[ a[i].second ] = left/s*100;
	}

	for( int i = 0; i < n; i++ )
		printf(" %.7lf", res[i]);

}

int main(){
	
	freopen("A-small-attempt0 (2).in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for( int i = 0; i < T; i++ ){
		printf("Case #%d:", i+1);
		solve();
		printf("\n");
	}
}