#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

//Macro........
#define maxm 3000
#define eps 1e-9
#define sq(a) ((a)*(a))
#define iseq(a,b) (fabs(a-b)<eps)
#define ii __int64

vector<int>v[maxm],topo;
int n,col[maxm];
ii dp[maxm][maxm];
ii cal(int s,int d);

int main(){
	
	int i,j,k,l,test,t=1;
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	scanf("%d",&test);
	
	while(test--){

		scanf("%d",&n);

		for(i=0;i<=n;i++){
			v[i].clear();
		}
		topo.clear();
		memset(col,0,sizeof(col));
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=1;j<=k;j++){
				scanf("%d",&l);
				v[l].push_back(i);
			}			
		}
		
		int fl=0;
		memset(dp,-1,sizeof(dp));
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j) continue;
				if(cal(i,j)>1) fl=1;
				if(fl) break;
			}
			if(fl) break;
		}
		if(fl){
			printf("Case #%d: Yes\n",t++);
		}
		else{
			printf("Case #%d: No\n",t++);
		}
		
	
	}
	
	return 0;
}

ii cal(int s,int d){

	if(s==d) return 1;
	if(v[s].size()==0) return 0;

	if(dp[s][d]!=-1) return dp[s][d];

	int i,j,k,l;
	ii ret=0;
	for(i=0;i<v[s].size();i++){
		k=v[s][i];
		ret+=cal(k,d);
	}
	return dp[s][d]=ret;

}