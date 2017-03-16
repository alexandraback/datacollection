#include<cstdio>

typedef long long LL;

int n;
void solve(){
	scanf("%d",&n);
	if(n==0){puts("INSOMNIA");return;}
	int mask=0;
	LL t=n;
	for(int i=1;;++i,t+=n){
		LL tx=t;
		for(;tx;tx/=10)mask|=1<<(tx%10);
		if(mask==(1<<10)-1)break;
	}
	printf("%I64d\n",t);
}

int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int kase,i=0;scanf("%d",&kase);
	for(int i=1;i<=kase;++i){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
