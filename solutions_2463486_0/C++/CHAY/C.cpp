#include<cstdio>
bool fun (long long a) {
	int i=0;
	int tmp[15]={0};
	while(a>0) {
		tmp[i]=a%10;
		a/=10;
		i++;
	}
	for(int j=0;j<i/2;j++)
		if(tmp[j]!=tmp[i-j-1]) return false;
	return true;
} 
int main () {
	long long i,j;
	int t,T;
	long long a,b;
	int N=0;
	long long num[20000]={0};
	for(i=1;i<=10000000;i++)
		if(fun(i)&&fun(i*i)) {
			num[N]=i*i;
			N++;
		}
	scanf("%d",&T);
	for(t=0;t<T;t++) {
		scanf("%lld%lld",&a,&b);
		for(i=0;num[i]<a&&i<N;i++) {}
		for(j=N-1;num[j]>b&&j>=0;j--) {}
		printf("Case #%d: %lld\n",t+1,j-i+1);
	}
	return 0;
}