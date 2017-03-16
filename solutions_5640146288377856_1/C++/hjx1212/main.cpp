#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t,r,c,w;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		scanf("%d%d%d",&r,&c,&w);
		printf("Case #%d: %d\n",t,c/w*(r-1)+(c-1)/w+w);
	}
}
