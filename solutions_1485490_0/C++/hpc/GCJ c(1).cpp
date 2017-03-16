#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
unsigned long long int ans;

unsigned long long int boxs[110];
unsigned long long int boxt[110];
unsigned long long int toys[110];
unsigned long long int toyt[110];

void dfs(unsigned long long int now,int b,unsigned long long int bs,int t,unsigned long long int ts){
//	printf("%llu %d %llu %d %llu\n",now,b,bs,t,ts);

	if(b==n || t==m){

		ans = max(ans,now);
		return;
	}
	if(b!=n && bs==0) dfs(now,b+1,boxs[b+1],t,ts);
	else if(t!=m && ts==0) dfs(now,b,bs,t+1,toys[t+1]);
	else{
		if(boxt[b]==toyt[t]){
			unsigned long long int tmp = min(bs,ts);
			dfs(now+tmp,b,bs-tmp,t,ts-tmp);
		}
		else{
			if(t!=m)dfs(now,b,bs,t+1,toys[t+1]);
			if(b!=n)dfs(now,b+1,boxs[b+1],t,ts);
		}

	}



}
int main(){
	freopen("C-small-attempt1.in","r",stdin);
    freopen("C.out","w",stdout);

	int ca;
	scanf("%d",&ca);
	for(int cs=1;cs<=ca;cs++){
		printf("Case #%d: ",cs);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%llu%llu",&boxs[i],&boxt[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%llu%llu",&toys[i],&toyt[i]);
		}
		ans=0;
		dfs(0,0,boxs[0],0,toys[0]);
		printf("%llu\n",ans);
	}

	return 0;
}
