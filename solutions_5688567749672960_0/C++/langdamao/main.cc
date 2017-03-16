#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int f[1000005];
int a[100005];
int n;
int reserve(int x){
	int ret=0;
	int now=0;
	while(x){
		a[now++]=x%10;
		x/=10;
	}
	for (int i=0;i<now;i++) ret=ret*10+a[i];
	return ret;
}
int main(){
	int T,ca=1;
	f[1]=1;
	for (int i=2;i<=1000000;i++){
		int tmp=reserve(i);
		if(tmp!=i&&i%10&&tmp<i)
			f[i]=min(f[i-1],f[tmp])+1;
		else f[i]=f[i-1]+1;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("Case #%d: %d\n",ca++,f[n]);
	}
	return 0;
}
