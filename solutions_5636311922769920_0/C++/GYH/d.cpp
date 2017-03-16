#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("ansD.txt","w",stdout);
	int T,k,c,s;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%d %d %d",&k,&c,&s);
		printf("Case #%d:",z);
		for(int i=1;i<=k;++i) printf(" %d",i);
		puts("");
	}
	return 0;
}
