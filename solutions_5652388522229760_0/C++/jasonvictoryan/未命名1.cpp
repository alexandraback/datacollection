#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

int T,totnum;

bool ok[15];

long long x;

void calc(long long now){
	while (now>0) {
		if (!ok[now % 10]) totnum+=1;
		ok[now % 10]=true;
		now=now / 10;
		if(now==0) return;
	}
}

int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		memset(ok,0,sizeof(ok));
		totnum=0;
		scanf("%I64d",&x);
		if (x==0) {
			printf("Case #%d: INSOMNIA\n",i);
			continue;
		}
		long long ans=x;
		while (totnum<10) {
			calc(ans);
			if (totnum==10) {
				printf("Case #%d: %I64d\n",i,ans);
				break;
			}
			ans+=x;
		}
	}
	return 0;
}
