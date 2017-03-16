#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define maxm 150
#define ii unsigned long long int

struct node{
	ii num,type;
};

int n,m;
node node1[maxm],node2[maxm];
vector<int>v1[maxm],v2[maxm];
ii dp[maxm][maxm][maxm];
ii cal(int ind,int b1,int b2,ii rem);
ii maxi(ii a,ii b){
	if(a>b) return a;
	return b;
}
ii mini(ii a,ii b){
	if(a<b) return a;
	return b;
}


int main(){

	int i,j,k,l,test,t=1;

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	scanf("%d",&test);

	while(test--){

		scanf("%d",&n);
		scanf("%d",&m);

		for(i=0;i<=102;i++){
			v1[i].clear(); v2[i].clear();
		}

		for(i=1;i<=n;i++){
			scanf("%llu %llu",&node1[i].num,&node1[i].type);
			v1[node1[i].type].push_back(i);
		}
		for(i=1;i<=m;i++){
			scanf("%llu %llu",&node2[i].num,&node2[i].type);
			v2[node2[i].type].push_back(i);
		}
		memset(dp,-1,sizeof(dp));
		ii ans=cal(1,1,m,node2[1].num);

		printf("Case #%d: %llu\n",t++,ans);


	}

	return 0;
}

ii cal(int ind,int b1,int b2,ii rem){

	if(ind>n||b1>b2) return 0;

	if(dp[ind][b1][b2]!=-1) return dp[ind][b1][b2];

	ii ret=0;

	int k,l,i,j;
	k=node1[ind].type; l=-1;
	ii ret1=0,cut,cut1,rem2;
	ii tot=0,rem1=node1[ind].num;
	for(i=b1;i<=b2;i++){
		if(node2[i].type!=node1[ind].type){
			if(i==b1) rem2=rem;
			else rem2=node2[i].num;
			ret=maxi(ret,cal(ind+1,i,b2,rem2));
			continue;
		}
		if(i!=b1) cut=mini(rem1,node2[i].num);
		else cut=mini(rem1,rem);

		if(i!=b1) rem2=node2[i].num-cut;
		else rem2=rem-cut;
		tot+=cut;
		rem1=node1[ind].num-tot;
		ret=maxi(ret,cal(ind+1,i,b2,rem2)+tot);

	}

	return dp[ind][b1][b2]=ret;

}
