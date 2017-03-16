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

int main(){
	
	freopen("D-small-attempt1.in","r",stdin);
	freopen("Ds.out","w",stdout);
	
	scanf("%d",&t);
	FI(tc,1,t){
		scanf("%d %d %d",&n,&c,&s);
		printf("Case #%d:",tc);
		
		if(c==1){
			if(s<n) printf(" IMPOSSIBLE\n");
			else{
				FI(i,1,n) printf(" %d",i);
				printf("\n");
			}
		}else{
			if(s+s<n) printf(" IMPOSSIBLE\n");
			else{
				LL ttl=1;
				FI(i,1,c) ttl=ttl*n;
				for(int i=1;i<=n;i+=2){
					int nx=min(n,i+1);
					printf(" %lld",(ttl/n)*(i-1)+nx);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

