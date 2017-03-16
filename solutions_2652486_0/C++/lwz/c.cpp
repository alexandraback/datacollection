#include<cstdio>
using namespace std;
int max(int x,int y){ if( x>=y ) return x; return y; }
int min(int x,int y){ if( x<=y ) return x; return y; }
int main()
{
int N,T; scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,s,n,m,l,k,mx,mn,t;
	printf("Case #%d:\n",T);
	scanf("%d%d%d%d",&l,&n,&m,&k);
	for(a=0;a<l;a++)
	{
		mx=0;
		mn=m;
		for(s=0;s<k;s++)
		{
			scanf("%d",&t);
			if( t>mx ) mx=t;
			if( t>1 && t<mn ) mn=t;
		}
		printf("%d",mn);
		mx=mx/mn;
		if( mx==0 ) mx=mn*mn;
		for(s=2;s<=m;s++) if( mx%s==0 ) goto found;
		printf("%d%d",mn,mn);
		if( false ) found: printf("%d%d",s,min(max(mx/s%10,2),m));
		printf("\n");
	}
}
	return 0;
}
