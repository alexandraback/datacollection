#include<cstdio>

using namespace std;

int T;
int n,m,w,ans;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d%d",&n,&m,&w);
		ans=n*((int)(m+w-1)/w);
		ans+=w-1;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
