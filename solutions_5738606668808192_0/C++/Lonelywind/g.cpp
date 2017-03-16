#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[50];
int lim=14;

long long prime(long long n) {
    long long i;
    if (n==1) return -1;
    for (i = 2; i*i <= n; i++) {
        if (!(n % i)) {
            return i;
        }
    }
    return -1;
}


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

	int i,k,cnt=0;
	long long y,z,d[50];
	bool flag;
	a[15]=1;
	a[0]=1;
	for (int x=0;x<(1<<lim);x++){
		for (k=0;k<lim;k++) a[k+1]=(x>>k)&1;
		flag=1;
		for (i=2;i<=10;i++){
			y=interp(i);
			z=prime(y);
			if (z==-1){
				flag=0;
				break;
			}
			else d[i]=z;
		}
		if (flag){
			cnt++;
			for (int j=15;j>=0;j--){
				printf("%d",a[j]);
			}
			for (int j=2;j<=10;j++)
				printf(" %lld",d[j]);
			printf("\n");
		}
		if (cnt>=50) break;
	}


	return 0;
}