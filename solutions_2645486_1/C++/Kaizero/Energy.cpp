#include<stdio.h>
long long TC,TC_C,i,E,R,N,w[10001],O[10001],st[10001],st2[10001],top;
long long Res,tt,S;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&TC);
	while(TC--){
		printf("Case #%lld: ",++TC_C);
		scanf("%lld%lld%lld",&E,&R,&N);
		if(R>=E)R=E;
		top=0;
		for(i=1;i<=N;i++){
			scanf("%lld",&w[i]);
			while(top&&st[top]<w[i]){
				O[st2[top]]=i;
				top--;
			}
			st[++top]=w[i];
			st2[top]=i;
		}
		S=E-R;
		Res=0;
		for(i=1;i<=N;i++){
			S+=R;
			tt=O[i]-i;
			if(O[i]==0 || tt*R > E){
				tt=S*w[i];
				Res+=tt;
				S=0;
				continue;
			}
			if(tt*R + S <= E) continue;
			Res+=(S-(E-tt*R))*w[i];
			S=E-tt*R;
		}
		for(i=1;i<=N;i++)O[i]=0;
		printf("%lld\n",Res);
	}
}
