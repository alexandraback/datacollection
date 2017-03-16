#include<cstdio>
#include<algorithm>
using namespace std;

#define bignum 1000000000

int T,E,R,N,ans;
int v[555];
int f[555][555];

int main(){
	scanf("%d",&T);
	for(int _=1;_<=T;_++){
		scanf("%d%d%d",&E,&R,&N);
		for(int i=0;i<N;i++)
			scanf("%d",&v[i]);
		for(int i=0;i<=N;i++)
			for(int j=0;j<=E;j++)
				f[i][j]=-bignum;
		f[0][E]=ans=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<=E;j++){
				if(f[i][j]<0)continue;
				for(int cost=0;cost<=j;cost++){
					int new_E=min(j-cost+R,E);
					int &nxt=f[i+1][new_E];
					nxt=max(nxt,f[i][j]+cost*v[i]);
					ans=max(ans,nxt);
				}
			}
	
		printf("Case #%d: %d\n",_,ans);
	}

	return 0;
}