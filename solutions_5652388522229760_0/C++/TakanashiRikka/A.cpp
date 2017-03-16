#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int pd[20],rem=10;
void insert(int k){
	for (int i=1;i<=k;i*=10){
		int k1=k/i%10; if (pd[k1]==0){pd[k1]=1; rem--;}
	}
}
void solve(){
	int k; scanf("%d",&k); memset(pd,0x00,sizeof pd); rem=10;
	if (k==0){
		printf("INSOMNIA\n"); return;
	}
	for (int i=1;;i++){
		insert(k*i); if (rem==0){printf("%d\n",i*k); return;}
	}
}
int main(){
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
	return 0;
}
