#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<string>
#include<cstring>


#define PR(x) printf(#x"=%d\n",x)
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define READ(x) scanf("%d",&x)
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
using namespace std;
vector<int> matr[1001];

int main() { 
int t;
int j=0;
scanf("%d",&t);
while(t--)
	{
	bool flg=false;
	printf("Case #%d: ",j+1); j++;
	for(int i=0;i<1001;i++) matr[i].clear();
	//for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) tr[i][j]=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
		int m;
		scanf("%d",&m);
		int tmp;
		for(int j=0;j<m;j++){ scanf("%d",&tmp);
		matr[i].push_back(tmp);
		}
		}
		
	
	for(int i=1;i<=n;i++){
	int root=i;
	
	bool visited[1001]={false};
	visited[root]=true;
	stack<int> dfs;
	dfs.push(root);
	
	 flg=false;
	while(dfs.empty()!=true)
		{
		
		int dest=dfs.top();dfs.pop();
		
		int sz=matr[dest].size();
		for(int j=0;j<sz;j++)
			{
			if(visited[matr[dest][j]]) { flg=true;break;}
			dfs.push(matr[dest][j]);
			visited[matr[dest][j]]=true;
			}		
		if(flg) break;
		}
	if(flg==true) {
			printf("Yes\n");
			break;
			}
	}
	if(!flg) printf("No\n");
	}
}
