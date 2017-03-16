#include<stdio.h>
#include<algorithm>
long long rev(long long x){
	long long ret=0;
	while(x){
		ret=ret*10+x%10;
		x/=10;
	}
	return ret;
}
int d(long long rev){
	int r=0;
	while(rev){
		rev/=10;
		r++;
	}
	return r>0?r:1;
}
long long p10(int x){
	long long ret=1;
	while(x)ret*=10,x--;
	return ret;
}
int main(){
	int i,j,k;
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		long long n;
		scanf("%lld",&n);
		long long ans=1;
		while(n>1){
			long long from=n-1;
			if(n%p10(d(n)/2)==1){
				long long r=rev(n);
				if(r<n){
					n=r;
					ans++;
					continue;
				} else {
					n--;
					ans++;
					continue;
				}
			} else if(n>10){
				long long t=n%p10(d(n)/2);
				long long u=!t?(p10(d(n)/2)-1):t-1;
				n-=u;
				ans+=u;
				continue;
			} else {
				n--;
				ans++;
			}
		}
		printf("Case #%d: %lld\n",T,ans);
	}
}
