#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define LL long long
int n,m;
int E,R;	
int v[15];
int dfs(int a,int e)
{
	if(a>=n) return 0;
	int tmp,res=0;
	int i;
	for(i=0;i<=e;i++)
	{
		tmp=i*v[a]+dfs(a+1,min(e-i+R,E));;
		res=max(tmp,res);
	}
	return res;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.txt","w",stdout);
	
	int i,j,k;
	int cas=0,T;
	cin>>T;

	while(T--)
	{
		int ans=0;
		cas++;
		
		scanf("%d%d%d",&E,&R,&n);
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		ans=dfs(0,E);

		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;	
}
