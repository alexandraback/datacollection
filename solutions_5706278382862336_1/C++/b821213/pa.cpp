#include <iostream>
#include <algorithm>
#include <stdio.h>
using std::cin;
using std::cout;

long long gcd(long long x,long long y){
	return x == 0 ? y : gcd(y%x,x);
}

int main(){
	long long MAX = 1LL<<40;
	
	int T;
	scanf("%d",&T);
	
	for(int t=1;t<=T;++t){
		long long x,y;
		scanf("%lld/%lld",&x,&y);
		printf("%lld,%lld\n",x,y);
		long long g = gcd(x,y);		 	
		x /= g, y /= g;
		if( x <= 0 || x > y || MAX % y != 0 )
			cout << "Case #" << t << ": impossible\n";
		else {
			x *= MAX/y;
			long long tmp = 1;
			int cnt;
			for(cnt=0;tmp<=x;++cnt,tmp+=tmp);
			cout << "Case #" << t << ": " << 41-cnt << "\n";
		}
	}
	return 0;
}
