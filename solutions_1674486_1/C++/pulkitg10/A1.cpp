#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000

vector<vector<int> > a,rev;	
vector<int> src,dest;
int memo[100000],gans;
int getpath(int node,int dst){
	int i,ans=0;
	if(node==dst)return 1;
	if(memo[node]!=-1)return memo[node];
	for(int i=0;i<a[node].size();i++){
		ans+=getpath(a[node][i],dst);
	}
	gans=max(gans,ans);
	return memo[node]=ans;
}

int main(){
	int i,n,m,t,j,x,ts=1;;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a.clear();
		rev.clear();
		src.clear();
		dest.clear();
		a.resize(1002);
		rev.resize(1002);
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d",&x);
				a[i].PB(x);
				rev[x].PB(i);
			}
		}
		for(i=1;i<=n;i++){
			if(rev[i].size()==0)
				src.PB(i);
			else if(a[i].size()==0)
				dest.PB(i);
		}
		printf("Case #%d: ",ts++);
		for(j=0;j<dest.size();j++){
		for(i=0;i<src.size();i++){
			gans=0;
			memset(memo,-1,sizeof(memo));
				getpath(src[i],dest[j]);
				if(gans>=2){
					printf("Yes\n");
					goto end;
				}
		}
		}		
		printf("No\n");
end:;
	}
	return 0;
}

