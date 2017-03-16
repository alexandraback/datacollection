#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,w;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&n,&m,&w);
		int ans=n*((int)(m+w-1)/w)+w-1;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
