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

int calc(int i,int j){
	return (i-1)*k+j;
}

void solve(){
	scanf("%d%d%d",&k,&c,&s); // s==k
	if(s>=k){
		LL kc=pow(k,c);
		for(LL i=((1+kc)-(k-1))/2;i<=((1+kc)+(k-1))/2;++i)printf("%I64d%c",i,i==(kc+k)/2 ? '\n' : ' ');
	}else{
		if(c==1||s<(k+1)/2){puts("IMPOSSIBLE");return;}
		for(int i=1;i+1<=k;i+=2)printf("%d ",calc(i,i+1));
		if(k&1)printf("%d\n",k);else putchar('\n');
	}
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
