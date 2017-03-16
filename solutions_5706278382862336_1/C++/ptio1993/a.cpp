#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll gcd(ll P,ll Q){
	if(P<Q)gcd(Q,P);
	while(Q!=0){
		ll temp=Q;
		Q=P%Q;
		P=temp;
	}
	return P;
}

ll pow2(int n){
	ll ret=1;
	for(int i=0;i<n;++i){
		ret*=2;
	}
	return ret;
}

int retpow(ll Q){
	int ctr=0;
	while(Q>1){
		if(Q%2==1)return -1;
		Q=Q/2;++ctr;
	}
	return ctr;
}

int main(){
	int TC;
	cin>>TC;
	for(int T=1;T<=TC;++T){
		printf("Case #%d:",T);
		ll P,Q;
		scanf("%lld/%lld",&P,&Q);
		ll div=gcd(P,Q);
		//printf("%lld\n",div);
		P=P/div;Q=Q/div;
		int n=retpow(Q);
		//printf("%lld %lld\n",P,Q);
		//printf("%d\n",n);
		if(n==0){printf(" 1\n");continue;}
		if(n>40){printf(" impossible\n");continue;}
		if(n==-1){printf(" impossible\n");continue;}
		int ct=0;
		while(P>1){
			P=P/2;++ct;
		}
		printf(" %d\n",n-ct);
	}
	return 0;
}