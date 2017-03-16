#include <cstdio>
#include <algorithm>

using namespace std;

long long num[15]; //num[i] means ans of 1x10^i
long long e[15];
long long n;

long long flip(long long n) {
	long long ans=0;
	while (n) {
		ans=ans*10+n%10;
		n/=10;
	}
	return ans;
}
long long getAns(long long n) {
	if (n<10) return n;
	int i=0;
	while (e[i]*10<=n) i++;
	if (n==e[i]) return num[i];
	long long ans1=n-e[i];
	long long ans2=0;
	if (n%e[(i+1)/2]!=0) ans2=(n%e[(i+1)/2])+(flip(n)%e[(i+1)-(i+1)/2]);
	else ans2=1+(n-1)%e[(i+1)/2]+flip(n-1)%e[(i+1)-(i+1)/2];
	return num[i]+min(ans1,ans2);
}

int main() {
	int t,tt,i;
	e[0]=1;
	for (i=1;i<=14;i++) e[i]=e[i-1]*10;
	num[0]=1;num[1]=10;
	for (i=2;i<=14;i++) {
		num[i]=num[i-1]+e[i/2]+e[i-i/2]-1;
	}
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",tt,getAns(n));
	}
	return 0;
}
