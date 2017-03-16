#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T, n;
bool visited[2502];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	
	scanf("%d",&T);
	for (int k=1;k<=T;k++)
	{
		for (int i=1;i<=2500;i++)
			visited[i]=false;
		
		scanf("%d",&n);
		for (int i=1;i<=2*n-1;i++)
			for (int j=1;j<=n;j++)
			{
				int x;
				scanf("%d",&x);
				visited[x]=!visited[x];
			}
		
		printf("Case #%d:",k);
		for (int i=1;i<=2500;i++)
		if (visited[i])
			printf(" %d",i);
		printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);
			
	return 0;
}











