#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[32]={0};
int main() {
	int t,n,k;
	scanf("%d",&t);
	scanf("%d",&n);
	scanf("%d",&k);
	a[0]=1;
	a[31]=1;
	printf("Case #1:\n");
	for(int i=31;i>=0;i--) {
		printf("%d",a[i]);
	}
	printf(" 3 2 5 2 7 2 9 2 11\n");
	k--;
	for(int i=30;i>=2;i--) {
		a[i]=1;
		for(int j=i-1;j>=1;j=j-2) {
			a[j]=1;
			for(int l=31;l>=0;l--) {
				printf("%d",a[l]);
			}
			printf(" 3 2 5 2 7 2 9 2 11\n");
			k--;
			a[j]=0;
		}
		a[i]=0;
	}
	a[30]=1;
	a[29]=1;
	for(int i=28;i>=2;i--) {
		a[i]=1;
		for(int j=i-1;j>=1;j=j-2) {
			a[j]=1;
			for(int l=31;l>=0;l--) {
				printf("%d",a[l]);
			}
			printf(" 3 2 5 2 7 2 9 2 11\n");
			k--;
			a[j]=0;
		}
		a[i]=0;
	}
	a[28]=1;
	a[27]=1;
	for(int i=26;i>=2;i--) {
		a[i]=1;
		for(int j=i-1;j>=1;j=j-2) {
			a[j]=1;
			for(int l=31;l>=0;l--) {
				printf("%d",a[l]);
			}
			printf(" 3 2 5 2 7 2 9 2 11\n");
			k--;
			if(k==0) {
				return 0;
			}
			a[j]=0;
		}
		a[i]=0;
	}
	return 0;
}