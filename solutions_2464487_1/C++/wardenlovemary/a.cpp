#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

long long r,t;

int main(){
	int T;scanf("%d",&T);
	for(int _=1;_<=T;_++){
		scanf("%I64d%I64d",&r,&t);
		double x=2.*r-1;
		double n=((sqrt(x*x+8.*t))-x)/4;
		long long ans=max((long long)n-10,0LL);
		while((2LL*r+2LL*ans-1)*ans<=t)
			ans++;
		printf("Case #%d: %I64d\n",_,ans-1);
	}

	return 0;
}