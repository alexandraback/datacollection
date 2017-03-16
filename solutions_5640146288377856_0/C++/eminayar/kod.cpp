#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

using namespace std;

int N,M,K,T;

int main(){
	
	cin >> T;

	for( int z=1 ; z<=T ; z++ ){
		cin >> N >> M >> K;
		int L=M;
		int res=0;
		for( int i=K ; i<=M && M-i>=K ; i+=K ) res++,L-=K;
		if( L == K ) res+=K;
		else res+=K+1;
		printf("Case #%d: %d\n",z,res);
	}

	return 0;
}