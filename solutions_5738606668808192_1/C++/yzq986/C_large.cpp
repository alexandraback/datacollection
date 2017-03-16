#include<cstdio>
#include<cstring>
#include<cassert>
typedef long long LL;

const int pri[5]={2,3,5,7,11};

int n,j;

LL ans[1010];int ansN;

LL getb(LL S,int b,int MOD){
	LL bk=1;
	LL T=0;
	for(int i=0;i<n;++i){
		if(S&(1<<i))T=(T+bk)%MOD;
		bk=bk*b%MOD;
	}
	return T;
}

void solve(){
	scanf("%d%d",&n,&j);
	ansN=0;
	for(LL S=(1LL<<(n-1))^1;ansN<j;S+=2){
		bool fg=1;
		for(int b=2;b<=10;++b){
			int pi;for(pi=0;pi<5 && getb(S,b,pri[pi])!=0;++pi);
			if(pi>=5){fg=0;break;}
		}
		if(fg)ans[ansN++]=S;
	}
	LL lst=ans[0];
	for(int i=0;i<ansN;++i){
		for(int j=n-1;j>=0;--j)printf("%d",(ans[i]>>j&1));putchar(' ');
		for(int b=2;b<=10;++b){
			int pi;for(pi=0;pi<5 && getb(ans[i],b,pri[pi])!=0;++pi);
			printf("%d%c",pri[pi],b==10 ? '\n' : ' ');
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase,i=0;scanf("%d",&kase);
	for(int i=1;i<=kase;++i){
		printf("Case #%d:\n",i);
		solve();
	}
//	for(;;);
	return 0;
}
