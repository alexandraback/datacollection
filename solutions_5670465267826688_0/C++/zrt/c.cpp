#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
#define int LL
int tt;
int n,x;
//0 1 2 3 4 5 6 7
//1-1 i-i j-j k-k
int op[8][8]={
	{0,1,2,3,4,5,6,7},
	{1,0,3,2,5,4,7,6},
	{2,3,1,0,6,7,5,4},
	{3,2,0,1,7,6,4,5},
	{4,5,7,6,1,0,2,3},
	{5,4,6,7,0,1,3,2},
	{6,7,4,5,3,2,1,0},
	{7,6,5,4,2,3,0,1},
};
char s[10005];
int to[128];
bool vis[10];
int lft[10];
int rgt[10];
int po[62];
int kase;
#undef int
int main(){
	#define int LL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%lld",&tt);
	to['i']=2;
	to['j']=4;
	to['k']=6;
	while(tt--){
		scanf("%lld%lld",&n,&x);
		scanf("%s",s);
		for(int i=0;i<n;i++) s[i]=to[s[i]];
		int sum=0;
		memset(lft,-1,sizeof lft);
		lft[0]=0;
		for(int i=0;i<n;i++) {
			sum=op[sum][s[i]];
			if(lft[sum]==-1){
				lft[sum]=i+1;
			}
		}
		po[0]=sum;
		for(int i=1;i<=60;i++) po[i]=op[po[i-1]][po[i-1]];
		int k=0;
		for(int i=0;i<=60;i++){
			if(x&(1LL<<i)){
				k=op[k][po[i]];
			}
		}
		if(k!=1){
			
			printf("Case #%lld: NO\n",++kase);
			continue;
		}
		//find i
		memset(vis,0,sizeof vis);
		int now=0;
		int t=0;
		int mnl=-1;
		while(!vis[now]){
			vis[now]=1;
			for(int i=0;i<8;i++){
				if(lft[i]!=-1){
					if(op[now][i]==to['i']){
						mnl=t*n+lft[i];goto ed;
					}
				}
			}
			now=op[now][sum];
			t++;
		}
		ed:;
		//find k
		memset(vis,0,sizeof vis);
		memset(rgt,-1,sizeof rgt);
		sum=0;
		rgt[0]=0;
		for(int i=n-1;i>=0;i--){
			sum=op[s[i]][sum];
			if(rgt[sum]==-1){
				rgt[sum]=n-i;
			}
		}
		now=0;
		t=0;
		int mxr=-1;
		while(!vis[now]){
			vis[now]=1;
			for(int i=0;i<8;i++){
				if(rgt[i]!=-1){
					if(op[i][now]==6){
						mxr=t*n+rgt[i];goto ed2;
					}
				}
			}
			now=op[now][sum];
			t++;
		}
		ed2:;
		if(mnl!=-1&&mxr!=-1&&mnl+mxr<=n*x){
			printf("Case #%lld: YES\n",++kase);
		}else printf("Case #%lld: NO\n",++kase);
	}
	
	
	return 0;
}
