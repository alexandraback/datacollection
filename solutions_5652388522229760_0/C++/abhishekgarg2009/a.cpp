#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int main() {
	int t,count;
	long long n,temp,temp2,ans;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%lld",&n);
		if(n==0) {
			printf("Case #%d: INSOMNIA\n",i);
			continue;
		}
		count=0;
		for(int j=0;j<10;j++) {
			a[j]=0;
		}
		for(long long j=1;;j++) {
			temp=n*j;
			while(temp) {
				temp2=temp%10;
				if(a[temp2]==0) {
					a[temp2]=1;
					count++;
				}
				temp=temp/10;
			}
			if(count==10) {
				ans=n*j;
				break;
			}
		}
		printf("Case #%d: %lld\n",i,ans);
	}
	return 0;
}