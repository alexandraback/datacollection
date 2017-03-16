#include<cstdio>
#include<cstring>
#include<cassert>
typedef long long LL;

int k,c,s;

LL pow(LL a,int n){
	LL s=1,t=a;
	for(;n;n>>=1){
		if(n&1)s*=t;
		t*=t;
	}
	return s;
}

void solve(){
	scanf("%d%d%d",&k,&c,&s); // s==k
	LL kc=pow(k,c);
	for(LL i=((1+kc)-(k-1))/2;i<=((1+kc)+(k-1))/2;++i)printf("%I64d%c",i,i==(kc+k)/2 ? '\n' : ' ');
}


int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase,i=0;scanf("%d",&kase);
	for(int i=1;i<=kase;++i){
		printf("Case #%d: ",i);
		solve();
	}
//	for(;;);
	return 0;
}
