#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("4.out","w",stdout);
	int T,n,m,q;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&n,&m,&q);
		printf("Case #%d:",i);
		for(int j=1;j<=q;j++)
			printf(" %d",j);
		printf("\n");
	}
	
	return 0;
}

