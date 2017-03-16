#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

using namespace std;

int N,M,K,T;
int ar[11000];

int main(){

	cin >> T;

	for( int z=1 ; z<=T ; z++ ){
		cin >> N >> M >> K;
		long long mx=0;
		int res=0;
		for( int i=1 ; i<=M ; i++ ) scanf(" %d",&ar[i]);
		for( int i=1,a ; i<=M && mx < K ; i++ ){
			a=ar[i];
			while( a-1 > mx && mx < K ){
				mx=mx+1LL*(mx+1LL)*N;
				res++;
			}
			mx=mx+1LL*a*N;
		}
		while( mx < K ){
			mx=mx+1LL*(mx+1LL)*N;
			res++;
		}
		printf("Case #%d: %d\n",z,res);
	}

	return 0;
}