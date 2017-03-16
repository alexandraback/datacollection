#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define MAX_N 2000
#define MAX_M 100
using namespace std;
int N,M[MAX_N],flag[MAX_N];
int v[MAX_N][MAX_M];
bool answer;
void DFS(int num)
{
	if(flag[num]==2) answer=true;
	if(flag[num]>=1||answer) return;
	flag[num]=1;
	for(int i=0;i<M[num];i++)
	{
		DFS(v[num][i]);
	}
	flag[num]=2;
}


void solve(int T)
{
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&M[i]);
		for(j=0;j<M[i];j++) scanf("%d",&v[i][j]);
	}
	for(j=1;j<=N;j++)
	{
		answer=false;
		for(i=1;i<=N;i++) flag[i]=0;
		DFS(j);
		if(answer) break;
	}
	printf("Case #%d: ",T);
	if(answer) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	int T,i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++) solve(i);
	return 0;
}