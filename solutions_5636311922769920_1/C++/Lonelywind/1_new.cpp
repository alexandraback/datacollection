#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long mypow(int a,int b){
	long long ret=1;
	for (int i=1;i<=b;i++)
		ret*=a;
	return ret;
}

int main(){
	int tt,k,c,s;
	cin>>tt;
	getchar();
	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d:",cs);
		scanf("%d%d%d",&k,&c,&s);
		if (s*c<k){
			puts(" IMPOSSIBLE");
			continue;
		}
		if (c>k){
			long long ans=1;
			for (int i=1;i<=k;i++){
				ans+=(i-1)*mypow(k,c-i);
			}
			for (int i=k+1;i<=c;i++){
				ans+=(k-1)*mypow(k,c-i);
			}
			printf(" %lld\n",ans);
			continue;
		}
		long long d=c*mypow(k,c-1);
		long long sum=1;
		for (int i=c;i>=1;i--){
			sum+=(i-1)*mypow(k,c-i);
		}
		for (int i=0;i<((k-1)/c)+1;i++){
			printf(" %lld",i*d+sum);
		}
		printf("\n");
	}


	return 0;
}