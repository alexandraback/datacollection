#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int is[2000100];
int factor[8] = {1,10,100,1000,10000,100000,1000000,10000000};
int A,B;
int calc(int a){
	int weishu = 0,tmp = a;
	while (tmp != 0){
		weishu ++;
		tmp/= 10;
	}
	int k;
	int ans = 0;
	for (k = 1;k < weishu;k++){
		tmp = a%factor[k]*factor[weishu-k]+a/factor[k];
		if (tmp > a && tmp <= B){
			if (is[tmp]!= a){
				is[tmp] = a;
				ans ++;
			}
		}
	}
	return ans;
}
long long deal(int a,int b){
	int i;
	long long ans = 0;
	for (i = a;i <= b;i++){
		ans += calc(i);
	}
	return ans;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i;
	scanf("%d",&t);
	for (i = 1;i <= t;i++){
		memset(is,0,sizeof(is));
		scanf("%d%d",&A,&B);
		int weishua = 0,weishub = 0;

		long long ans = 0;
		
		ans = deal(A,B);

		
		printf("Case #%d: %lld\n",i,ans);
	}
	return 0;
}