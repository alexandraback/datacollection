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
		printf("Case #%d: ",cs);
		scanf("%d%d%d",&k,&c,&s);
		if (s<k){
			puts("IMPOSSIBLE");
			continue;
		}
		long long d=mypow(k,c-1);
		putchar('1');
		for (long long i=2;i<=k;i++){
			printf(" %lld",(i-1)*d+1);
		}
		printf("\n");
	}


	return 0;
}