#include <iostream>

using namespace std;
int n,m;
unsigned long long int ans;
#define MAXN 110
typedef unsigned long long int llu;
unsigned long long int boxs[MAXN];
unsigned long long int boxt[MAXN];
unsigned long long int toys[MAXN];
unsigned long long int toyt[MAXN];
unsigned long long int cut[MAXN][MAXN];
unsigned long long int unit =1;
llu Btypesum[MAXN][MAXN][MAXN];
llu Ttypesum[MAXN][MAXN][MAXN];
llu dp[MAXN][MAXN];
bool isfound[MAXN][MAXN];
void countsum(){
	memset(Btypesum,0,sizeof(Btypesum));
	memset(Ttypesum,0,sizeof(Ttypesum));
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
				for(int k=i;k<j;k++){
					Btypesum[i][j][boxt[k]]+=boxs[k];	
				}
		}	
	}
	for(int i=0;i<=m;i++){
		for(int j=i;j<=m;j++){
				for(int k=i;k<j;k++){
					Ttypesum[i][j][toyt[k]]+=toys[k];
				}
		}	
	}		
	
}

llu DP(int b,int t){
	if(b==n || t==m) return 0;
	if(isfound[b][t]) return dp[b][t];
	for(int i=b+1;i<=n;i++)
		for(int j=t+1;j<=m;j++){
			dp[b][t]= max(dp[b][t],DP(i,j) + max(min(Btypesum[b][i][boxt[b]],Ttypesum[t][j][boxt[b]]),
												 min(Btypesum[b][i][toyt[t]],Ttypesum[t][j][toyt[t]])));	
			
		}
	isfound[b][t]=true;
	return dp[b][t];
	
}
int main(){
	freopen("C-large.in","r",stdin);
	freopen("Cb.out","w",stdout);
	int ca;
	scanf("%d",&ca);
	for(int cs=1;cs<=ca;cs++){
		
		memset(isfound,false,sizeof(isfound));
		memset(dp,0,sizeof(dp));
		printf("Case #%d: ",cs);
		scanf("%d%d",&n,&m);	
		for(int i=0;i<n;i++){
			scanf("%llu%llu",&boxs[i],&boxt[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%llu%llu",&toys[i],&toyt[i]);	
		}
		countsum();
		printf("%llu\n",DP(0,0));
	}
	
	return 0;	
}
