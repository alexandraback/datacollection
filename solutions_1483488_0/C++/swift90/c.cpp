#include<cstdio>
int A,B,sol;
int acc[10];
void solve(){
	int i,ax,x,op=0,put=1,ok;
	sol=0;
	x=A;
	while(x){
		++op;
		x/=10;
		put*=10;
	}
	put/=10;
	for(i=A;i<B;++i){
		x=i;
		acc[0]=0;
		for(int j=1;j<op;++j){
			ax=x%10;
			x=x/10+ax*put;
			if(i<x && x<=B){
				ok=1;
				for(int k=1;k<=acc[0];++k)
					if(x==acc[k])
						ok=0;
				if(ok){
					++sol;
					acc[++acc[0]]=x;
				}
			}
		}
		if(sol>280)
			ax=123;
	}
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		scanf("%d%d",&A,&B);
		solve();
		printf("Case #%d: %d\n",i,sol);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
