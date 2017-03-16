#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define PAUSE system("pause")
#define MAX 10
int E,R,N,v[MAX];
int dfs(int now,int e,int s)
{
	if(now==N) return s;
	if(e>E) e=E;
	int i,j,k;
	for(i=k=0;i<=e;i++)
	{
		j = dfs(now+1,e-i+R,s+v[now]*i);
		if(k<j) k=j;
	}
	return k;
}
main()
{
//	freopen("B_small.in","r",stdin);
//	freopen("B_small_out.txt","w",stdout);
	int Test,Case,i,j,k;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scanf("%d%d%d",&E,&R,&N);
		for(i=0;i<N;i++) scanf("%d",v+i);
		if(R>E) R=E;
		printf("Case #%d: %d\n",Case,dfs(0,E,0));
	}
}
