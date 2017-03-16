#include <cstdio>
#include <iostream>
using namespace std;

bool f[10];

void solve(long long x){
	while (x>0){
		f[x%10]=1;
		x=x/10;
	}
}

bool see(){
	for (int i=0;i<=9;i++)
		if (!f[i]) return 0;
	return 1;
}

int main(){
	int tt;
	long long n,sum;
	cin>>tt;
	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d: ",cs);
		scanf("%lld",&n);
		if (n==0){
			puts("INSOMNIA");
			continue;
		}
		for (int i=0;i<=9;i++) f[i]=0;
		sum=0;
		while (1){
			sum+=n;
			//cerr<<sum<<endl;
			solve(sum);
			if (see()) break;
		}
		printf("%lld\n",sum);
	}

	return 0;
}