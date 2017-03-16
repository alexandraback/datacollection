#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;

const int maxn=100+10;
int a[maxn];
int n,s;
int ans,tot;

void work()
{
	scanf("%d%d",&s,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (s==1) {printf("%d\n",n);return;}
	sort(a+1,a+n+1);
	ans=n;tot=0;
	for (int i=1;i<=n;i++)
	{
		while (a[i]>=s)
		{
			s=s*2-1;
			tot++;
		}
		s+=a[i];
		ans=min(ans,tot+n-i);
	}
	printf("%d\n",ans);
}

int main()
{
	freopen(".in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++) 
	{
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
