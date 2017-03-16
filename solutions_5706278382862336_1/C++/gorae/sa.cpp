#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long eu(long long x,long long y){
	long long n;
	while(1){
		n=x%y;
		if(!n) return y;
		x=y;
		y=n;
	}
}

int go(long long n,long long m){
	if(n==1){
		int ans=0;
		while(m!=1){
			m/=2;
			ans++;
		}return ans;
	}if(n>m/2){
		return 1;
	}
	
	int a=go(1,m/2);
	long long gc=eu(n-1,m/2);
	int b=go((n-1)/gc,m/(2*gc));
	return a<b?a+1:b+1;
}


int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);

	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){

		printf("Case #%d: ",TT);
		
		long long n,m;
		scanf("%lld/%lld",&n,&m);
		
		long long gc=eu(n,m);
		n/=gc;
		m/=gc;

		long long t=1;
		int f=0;
		while(t<=1000000000000){
			t*=2;
			if(t==m) {
				f=1;break;}
		}if(!f) {
			printf("impossible\n");
		}else printf("%d\n",go(n,m));
	
	}

}
