#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1010;
int a[maxn],b[maxn],n;
bool visit1[maxn],visit2[maxn];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tests;
	scanf("%d",&tests);
	for (int test=1; test<=tests; test++)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
			scanf("%d%d",&a[i],&b[i]);
			
		memset(visit1,0,sizeof(visit1));
		memset(visit2,0,sizeof(visit2));
		int cnt=0,ans=0,k,max;
		bool flag=0;
		for (;cnt<=2*n;)
		{
			flag=0;
			for (int i=1; i<=n; i++)
				if (!visit2[i]&&b[i]<=cnt)
				{
					flag=1; k=i; break;
				}
			if (flag)
			{
				if (!visit1[k]) cnt+=2,ans++,visit1[k]=visit2[k]=1;
				else cnt++,ans++,visit1[k]=visit2[k]=1;
				continue;
			}
			
			flag=0;  k=max=0;
			for (int i=1; i<=n; i++)
				if (!visit1[i]&&a[i]<=cnt&&b[i]>max)
				{
					flag=1; k=i; max=b[i];
				}
			if (!flag) break;
			visit1[k]=1;
			ans++,cnt++;
		}
		if (cnt<2*n) printf("Case #%d: Too Bad\n",test);
		else printf("Case #%d: %d\n",test,ans);
	}
}
