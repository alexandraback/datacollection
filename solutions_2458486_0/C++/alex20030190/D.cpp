#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<list>
using namespace std;

bool submit=true;

int dp[1<<20+3],Tc,init[201],req[21],T[21],wl[21][41],st,n;
int q[1<<20+3],prev[1<<20+3];
bool b[1<<20+3];
void bfs(){
	int l=0,r=1;
	q[0]=0;
	prev[0]=-1;
	memset(b,false,sizeof(b));
	while(l<r){
		if(q[l]==((1<<n)-1)){
			int ans[21],tmp=q[l];
			for(int i=0;i<n;i++){
				int diff=tmp-prev[tmp];
				for(int j=0;j<n;j++){
					if(diff&(1<<j)){
						ans[i]=j+1;
						break;
					}
				}
				tmp=prev[tmp];
			}
			for(int i=n-1;i>=0;i--) printf(" %d",ans[i]);
			goto gg;
		}
		for(int i=0;i<n;i++){
			if(q[l]&(1<<i)){
				init[req[i]]--;
				for(int j=0;j<T[i];j++) init[wl[i][j]]++;
			}
		}
		for(int i=0;i<n;i++){
			int kN=(q[l]&(1<<i)),kO=(q[l]|(1<<i));
			if(kN==0 && !b[kO] && init[req[i]]>0){
				b[kO]=true;
				prev[kO]=q[l];
				q[r++]=(kO);
			}
		}
		for(int i=0;i<n;i++){
			if(q[l]&(1<<i)){
				init[req[i]]++;
				for(int j=0;j<T[i];j++) init[wl[i][j]]--;
			}
		}
		l++;
	}
	printf(" IMPOSSIBLE");
	gg:;
	return;
}
int main(){
	if(submit){
		freopen("D-small-attempt0.in.txt","r",stdin);
		freopen("D-small-attempt0.txt","w",stdout);
	}
	scanf("%d",&Tc);
	for(int i=1;i<=Tc;i++){
		memset(init,0,sizeof(init));
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&st,&n);
		for(int i=1;i<=st;i++){
			int tt;
			scanf("%d",&tt);
			init[tt]++;
		}
		for(int i=0;i<n;i++){
			scanf("%d %d",&req[i],&T[i]);
			for(int j=0;j<T[i];j++){
				scanf("%d",&wl[i][j]);
			}
		}
		printf("Case #%d:",i);
		bfs();
		printf("\n");
	}
	return 0;
}
