#include <iostream>
#include <cstdio>

int main(){
	
	long long a[10000];
    long long b[100];
	long long i,j,k,x,y,n=0;
	for(i=1;i<=9999999;i++){
		long long d=0;
		long long m=i;
		long long p=1;
		while(m!=0){d++;b[d]=m%10;m/=10;}
		for(j=1;j<=d/2;j++)if(b[j]!=b[d-j+1])p=0;
		if(p==1){
			m=i*i;
			d=0;
			p=1;
			while(m!=0){d++;b[d]=m%10;m/=10;}
	    	for(j=1;j<=d/2;j++)if(b[j]!=b[d-j+1])p=0;
	    	if(p==1){
				n++;
				a[n]=i*i;
			}
		}
	
	}
	int tc;
	scanf("%lld",&tc);
	for(i=1;i<=tc;i++){
		long long ans=0;
		scanf("%lld %lld",&x,&y);
		for(j=1;j<=n;j++)if(x<=a[j]&&a[j]<=y)ans++;
		printf("Case #%lld: %lld\n",i,ans);
	}
	
	return 0;
}
		
		
