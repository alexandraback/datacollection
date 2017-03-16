#include <bits/stdc++.h>
using namespace std;

int T;
long long N, A, B;
int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%lld",&N); A = 0;
		if( N == 0 ){
			printf("Case #%d: INSOMNIA\n", t );	
			continue;
		}
		set<int> num;
		while( num.size() < 10 ){
			A += N; B = A;
			while( B ) {
				num.insert( B % 10 );
				B /= 10;
			}
		}
		printf("Case #%d: %lld\n", t, A );
	}
	return 0;
}
