#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[16]={0};
int main() {
	int t,n,k;
	scanf("%d",&t);
	scanf("%d",&n);
	scanf("%d",&k);
	a[0]=1;
	a[15]=1;
	printf("Case #1:\n");
	for(int i=15;i>=0;i--) {
		printf("%d",a[i]);
	}
	printf(" 3 2 5 2 7 2 9 2 11\n");
	for(int i=14;i>=2;i--) {
		a[i]=1;
		for(int j=i-1;j>=1;j=j-2) {
			a[j]=1;
			for(int l=15;l>=0;l--) {
				printf("%d",a[l]);
			}
			printf(" 3 2 5 2 7 2 9 2 11\n");
			a[j]=0;
		}
		a[i]=0;
	}
	return 0;
}