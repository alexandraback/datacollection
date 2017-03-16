#include<stdio.h>
#include<set>
#include<stdlib.h>
#define PAUSE system("pause")
#define MAX 8000
#define DIG 12
using namespace std;
set<long long> FIND;
int R,N,M,K;
long long P[MAX][DIG];
char ans[MAX][DIG+1];
int array[MAX];
void Combination(int i,long long j)
{
	FIND.insert(j);
	if(i==N) return;
	Combination(i+1,j*array[i]);
	Combination(i+1,j);
}
void dfs(int now,int last)
{
	int i,j;
	if(now==N)
	{
		FIND.clear();
		Combination(0,1);
		for(i=0;i<R;i++)
		{
			for(j=0; j<K && FIND.count(P[i][j]) ;j++);
			if(j==K)
				for(j=0;j<N;j++) ans[i][j] = array[j]+'0';
		}
		return;
	}
	for(i=last;i<=M;i++)
	{
		array[now]=i;
		dfs(now+1,i);
	}
}
main()
{
//	freopen("C_small.in","r",stdin);
//	freopen("C_small_out.txt","w",stdout);
	int i,j;
	scanf("%d",&R);
	printf("Case #%d:\n",R);
	scanf("%d%d%d%d",&R,&N,&M,&K);
	for(i=0;i<R;i++)
		for(j=0;j<K;j++) scanf("%I64d",&P[i][j]);
	dfs(0,2);
	for(i=0;i<R;i++) puts(ans[i]);
}
