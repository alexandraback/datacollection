#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int K,C,S;
void solve(){
	scanf("%d%d%d",&K,&C,&S);
	int lim=K/C; if (K%C) lim++;
	long long tot=1;
	for (int i=1;i<=C;i++) tot*=K;
	if (lim>S){
		printf(" IMPOSSIBLE\n"); return;
	}
	for (int i=1;i<=lim;i++){
		long long num=1;
		for (int j=(i-1)*C+1;j<=i*C;j++){
			int kk=j; if (j>K) kk=K;
			num=(num-1)*K+kk; 
		}
		if (num>tot) cerr<<"fa "<<num-tot<<endl;
		printf(" %lld",num);
	}
	printf("\n");
	return;
}
int main(){
	freopen("large.in","r",stdin);
	freopen("large.out","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d:",i); solve();
	}
}
