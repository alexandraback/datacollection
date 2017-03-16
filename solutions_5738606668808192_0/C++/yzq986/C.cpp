#include<cstdio>
#include<cstring>
#include<cassert>
typedef long long LL;

int n,j;

LL ans[1010];int ansN;

LL getb(LL S,int b){
	LL bk=1;
	LL T=0;
	for(int i=0;i<n;++i){
		if(S&(1<<i))T+=bk;
		bk=bk*b;
	}
	return T;
}

LL mf(LL x){
	for(int i=2;i<=x/i;++i)if(x%i==0)return i;
	return x;
}

void solve(){
	scanf("%d%d",&n,&j);
	ansN=0;
	for(LL S=(1<<(n-1))+1;ansN<j;S+=2){
		bool fg=1;
		for(int b=2;b<=10;++b){
			LL T=getb(S,b);
			if(mf(T)==T){fg=0;break;}
		}
		if(fg)ans[ansN++]=S;
	}
	for(int i=0;i<ansN;++i){
		for(int j=n-1;j>=0;--j)printf("%d",(ans[i]>>j&1));putchar(' ');
		for(int b=2;b<=10;++b){
			LL T=getb(ans[i],b);
//			printf("%I64d\n %I64d\n",T,mf(T));
//			assert(T%mf(T)==0);
//			printf("%I64d %d %I64d\n",ans[i],b,T);
			printf("%I64d%c",mf(T),b==10 ? '\n' : ' ');
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
