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

int tc,res[55],n,cnt[2505];

int main(){
	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bs.out","w",stdout);
	
	scanf("%d",&tc);
	FI(t,1,tc){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		FI(i,1,n*(2*n-1)){
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		
		int p=0;
		FI(i,1,2500) if(cnt[i]&1) res[++p]=i;
		printf("Case #%d:",t);
		FI(i,1,p) printf(" %d",res[i]);
		printf("\n");
	}
	return 0;
}

