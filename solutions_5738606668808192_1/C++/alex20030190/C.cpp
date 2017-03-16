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

int n,cnt,t;
bool rn[17];

int main(){
	
	freopen("C-large.in","r",stdin);
	freopen("Cl.out","w",stdout);
	
	scanf("%d",&t);
	scanf("%d %d",&n,&cnt);
	printf("Case #1:\n");
	int num;
	FI(i,0,cnt-1){
		rn[0]=rn[n/2-1]=1;
		FI(j,0,n/2-3){
			if(i&(1<<j)) rn[j+1]=1;
			else rn[j+1]=0;
		}
		FI(j,0,n/2-1) printf("%d",rn[j]);
		FI(j,0,n/2-1) printf("%d",rn[j]);
		FI(j,2,10){
			LL cur=0;
			FI(k,0,n/2-1) cur=cur*j+rn[k];
			printf(" %lld",cur);
		}
		printf("\n");
	}
	return 0;
}

