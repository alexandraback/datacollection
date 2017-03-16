#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<iostream>

using namespace std;
typedef long long ll;

int a[30],v1[30],v2[30];
int sum,n;
int dfs(int t,int pos,int s)
{
	if(s>t)
		return 0;
	if(pos>=n){
		if(s==t)
			return 1;
		else
			return 0;
	}
	while(v1[pos])
		pos++;
	if(pos>=n)
		return 0;
	v2[pos]=1;
	if(dfs(t,pos+1,s+a[pos]))
		return 1;
	v2[pos]=0;
	if(dfs(t,pos+1,s))
		return 1;

	return 0;
}
int dfs(int pos,int s)
{
	if(s*2>sum)
		return 0;
	if(pos>=n){
		if(s==0)
			return 0;
		memset(v2,0,sizeof(v2));
		int ans=dfs(s,0,0);
		return ans;
	}
	if(dfs(pos+1,s))
		return 1;
	v1[pos]=1;
	if(dfs(pos+1,s+a[pos]))
		return 1;
	v1[pos]=0;

	return 0;
}
int main() {
	int T,ri=1;
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		memset(v1,0,sizeof(v1));
		int ans=dfs(0,0);
		printf("Case #%d:\n",ri++);
		vector<int> e;
		if(ans){
			e.clear();
			for(int i=0;i<n;i++)
				if(v1[i])
					e.push_back(i);
			for(int i=0;i<e.size();i++){
				if(i==e.size()-1)
					printf("%d\n",a[e[i]]);
				else
					printf("%d ",a[e[i]]);
			}
			e.clear();
			for (int i = 0; i < n; i++)
				if (v2[i])
					e.push_back(i);
			for (int i = 0; i < e.size(); i++) {
				if (i == e.size() - 1)
					printf("%d\n", a[e[i]]);
				else
					printf("%d ", a[e[i]]);
			}
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
