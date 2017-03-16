#include <bits/stdc++.h>
#define value(x) (x - '0')
using namespace std;

int main(){
	int T,Smax,sum,ans;
	char audiance[2000];
	scanf("%d",&T);
	for(int t = 1;t <= T;t++){
		scanf("%d %s",&Smax,audiance);
		sum = value(audiance[0]);
		ans = 0;
		for(int i = 1;i <= Smax;i++){
			if((i > sum) && value(audiance[i])) {
				ans += i - sum;
				sum += i - sum;
			}
			sum += value(audiance[i]);
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}