#include<stdio.h>
#include<string.h>
long long A,B,K,k;
long long Ans;
int bit[50],c;
int bitA[50],cA;
int bitB[50],cB;
long long MIN(long long a,long long b)
{
	if(a>b) return b;
	return a;
}
long long MAX(long long a,long long b)
{
	if(a<b) return b;
	return a;
}
long long HasXbit(int x,long long S,long long E)
{
	if(S>E) return 0;
	long long a,b;
	a=S/(1<<(x+1));
	b=E/(1<<(x+1));
	if(a==b)
	{
		if(S<(a*(1<<(x+1))+(1<<x))) S=(a*(1<<(x+1))+(1<<x));
		if(S>E) return 0;
		return E-S+1;
	}
	long long ans=0;
	ans+=HasXbit(x,S,(a+1)*(long long)(1<<(x+1))-1);
	ans+=HasXbit(x,b*(long long)(1<<(x+1))+(long long)(1<<x),E);
	ans+=(b-1-(a+1)+1)*(long long)(1<<x);
	return ans;
}
long long HasntXbit(int x,long long S,long long E)
{
	if(S>E) return 0;
	long long has = HasXbit(x,S,E);
	return E-S+1-has;
}
void dfs(int x,long long lA,long long rA,long long lB,long long rB,long long BaseA,long long BaseB)
{
	if(lA>rA || lB>rB) return;
	if(x==-1) return;
	if(bit[x])
	{
		long long hasntxbita = HasntXbit(x,lA,rA);
		long long hasxbita = rA-lA+1-hasntxbita;
		long long hasntxbitb = HasntXbit(x,lB,rB);
		long long hasxbitb = rB-lB+1-hasntxbitb;
		Ans+=hasntxbita*hasntxbitb;
		Ans+=hasxbita*hasntxbitb;
		Ans+=hasntxbita*hasxbitb;
		dfs(x-1,MAX(BaseA+(1<<x),lA),rA,MAX(BaseB+(1<<x),lB),rB,BaseA+(1<<x),BaseB+(1<<x));
		return;
	}
	else
	{
		dfs(x-1,lA,MIN(BaseA+(1<<x)-1,rA),lB,MIN(BaseB+(1<<x)-1,rB),BaseA,BaseB);
		dfs(x-1,lA,MIN(BaseA+(1<<x)-1,rA),MAX(BaseB+(1<<x),lB),rB,BaseA,BaseB+(1<<x));
		dfs(x-1,MAX(BaseA+(1<<x),lA),rA,lB,MIN(BaseB+(1<<x)-1,rB),BaseA+(1<<x),BaseB);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld %lld %lld",&A,&B,&K);
		printf("Case #%d: ",t);
		Ans=0;
		memset(bit,0,sizeof(bit));
		memset(bitA,0,sizeof(bitA));
		memset(bitB,0,sizeof(bitB));
		c=0; k=K;
		while(k!=0) bit[c++]=k%2,k>>=1;
		cA=0; k=A;
		while(k!=0) bitA[cA++]=k%2,k>>=1;
		cB=0; k=B;
		while(k!=0) bitB[cB++]=k%2,k>>=1;
		if(c<cA) c=cA;
		if(c<cB) c=cB;
		dfs(c-1,0,A-1,0,B-1,0,0);
		printf("%lld\n",Ans);
	}
}