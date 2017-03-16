#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map> 
using namespace std;
map<long long, bool> av;
int T , C=1;
long long P , Q;
long long GCD( long long a , long long b ){
	long long r;
	do{
		r = a % b;
		a = b;	
		b = r;
	}while ( r != 0 );
	return a;
}
int Solve(){
	int cnt = 1;
	long long p = P , q = Q;
	long long gcd = GCD( p , Q );
	p /= gcd , q /= gcd;
	if ( !av[q] ) return 50;
	while ( p < q/2 ){
		cnt++;	
		q /= 2;
	}
	return cnt;
	
}


int main(){
	 freopen("A-small-attempt3.in","r",stdin);
	 freopen("output.out","w",stdout);
	for ( long long i = 0 , j = 1; i < 40 ; i++ , j*=2 )
		 av[j] = 1;
	scanf("%d",&T);
	while ( T-- ){
		scanf("%I64d/%I64d",&P,&Q);
		int ans = Solve();
		if ( ans <= 40 )
			printf("Case #%d: %d\n",C++,ans);
		else
			printf("Case #%d: impossible\n",C++);
	}
	return 0;
}
