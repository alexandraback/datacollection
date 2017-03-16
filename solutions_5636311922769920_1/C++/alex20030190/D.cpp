#include <bits/stdc++.h>

#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)

#define LL long long
#define PI 3.141592653589793238

#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second

using namespace std;

int t,n,c,s;

LL conv(int st){
	LL x=1;
	FI(i,1,c) x*=n;
	LL res=0;
	FI(i,1,c){
		int g=min(st+i-1,n);
		x/=n;
		res+=(g-1)*x;
	}
	return res+1;
}

int main(){
	
	freopen("D-large.in","r",stdin);
	freopen("Dl.out","w",stdout);
	
	scanf("%d",&t);
	FI(tc,1,t){
		scanf("%d %d %d",&n,&c,&s);
		printf("Case #%d:",tc);
		
		if(c*s<n) printf(" IMPOSSIBLE\n");
		else{
			for(int i=1;i<=n;i+=c){
				LL val=conv(i);
				printf(" %lld",val);
			}
			printf("\n");
		}
	}
	return 0;
}

