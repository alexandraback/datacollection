#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long a[50];
int lim=14;


long long interp(long long b){
	long long ret=0,c=1;
	for (int i=0;i<16;i++){
		ret+=(a[i]*c);
		c*=b;
	}
	return ret;
}

int main(){

	printf("Case #1:\n");

	int i,k,cnt=0,num=500;
	long long y,z,d[50];
	bool flag;
	//a[31]=1;
	//a[16]=1;
	a[15]=1;
	a[0]=1;
	for (long long x=0;x<(1<<lim);x++){
		for (k=0;k<lim;k++){
			a[k+1]=(x>>k)&1;
			//a[k+17]=(x>>k)&1;
		}
		flag=1;
		for (i=2;i<=10;i++){
			y=interp(i);
			d[i]=y;
		}
		if (flag){
			cnt++;
			for (int j=15;j>=0;j--){
				printf("%lld",a[j]);
			}
			for (int j=15;j>=0;j--){
				printf("%lld",a[j]);
			}
			for (int j=2;j<=10;j++)
				printf(" %lld",d[j]);
			printf("\n");
		}
		if (cnt>=num) break;
	}


	return 0;
}