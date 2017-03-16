#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int usd[1005];
int n;
struct st{
	int u, d;
	st(){}
	st( int u, int d): u(u), d(d){}
	bool operator < ( st const &a ) const{
		if ( a.d != d ){
			return d < a.d;
		}
		return u > a.u;
	}
};

int main(){
	int runs;
	cin >> runs;
	for( int r = 1; r <= runs; r++){
		cin >> n;
		st p[n];
		bool c = true;
		for( int i = 0; i < n; i++) {
			cin >> p[i].u >> p[i].d;
		}
		printf("Case #%d: ",r);
		
		sort( p , p + n);	
		int stars = 0, games = 0;
		for( int i = 0; i < n; i++) usd[i] = 2;
		bool cagao = false;
		for( int i = 0; i < n; i++){
			for( ; i < n && stars >= p[i].d; i++ ){
				games++;
				stars += usd[i];
			}
			if ( i == n ) break;
			int j ;
			for( j = n - 1; j >= i; j--){
				if ( usd[j] == 1 ) continue;
				if ( stars >= p[j].u ) {
					break;
				}
			}
			if ( j == i - 1 ) {
				cagao = true;
				break;
			}
			stars++; games++;
			usd[ j ] = 1;
			i--;

		}
		if ( cagao ) {
			printf("Too Bad\n");
			continue;
		}
		printf("%d\n", games);
	

	}
}
