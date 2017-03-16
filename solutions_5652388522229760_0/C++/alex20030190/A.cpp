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

int t,n;
bool app[10];

LL res;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("As.out","w",stdout);
	
	scanf("%d",&t);
	FI(i,1,t){
		scanf("%d",&n);
		
		memset(app,0,sizeof(app));
		res=-1;
		
		FI(j,1,10000){
			LL cur=j*n;
			while(cur){
				app[cur%10]=true;
				cur/=10;
			}
			bool ok=true;
			FI(k,0,9) if(!app[k]){
				ok=false;
				break;
			}
			if(ok){
				res=1LL*j*n;
				break;
			}
		}
		printf("Case #%d: ",i);
		if(res==-1) printf("INSOMNIA\n");
		else printf("%lld\n",res);
	}
	return 0;
}

