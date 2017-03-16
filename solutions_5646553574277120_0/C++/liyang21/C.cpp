#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int T,C,D,V,ans;
int a[100001];
int f[100001];

int main()
{
	
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++)
	{
		scanf("%d%d%d",&C,&D,&V);
		for (int i=1;i<=D;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+D);
		for (int i=0;i<=V;i++) f[i]=0;
		f[0]=1; int tt=1; ans=0;
		for (int i=1;i<=V;i++)
		{
			while (tt<=D&&a[tt]<=i)
			{
				for (int j=1;j<=C;j++)
					for (int k=V;k>=a[tt];k--)
						if (f[k-a[tt]]) f[k]=1;
				tt++;
			}
			if (f[i]) continue;
			ans++;
			for (int j=1;j<=C;j++)
				for (int k=V;k>=i;k--)
					if (f[k-i]) f[k]=1;
		}
		printf("Case #%d: %d\n",Case,ans);
	}
}

