#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
 
const int maxn=1e2+5;
int m[maxn],t[maxn];

int main ()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int cas,kk,n;
	scanf("%d",&cas);
	for(int ii=1;ii<=cas;++ii)
	{
		scanf("%d%d",&kk,&n);
		for(int i=0;i<n;++i)
			scanf("%d",&m[i]);
		printf("Case #%d: ",ii);

		if(kk==1)
		{
			printf("%d\n",n);
			continue;
		}

		sort(m,m+n);
		int tmp=0;
		for(int i=0;i<n;++i)
		{
			while(kk<=m[i])
			{
				++tmp;
				kk=kk*2-1;
			}
			kk+=m[i];
			t[i]=tmp;
		}

		int ans=n;
		for(int i=n-1;i>=0;--i)
		{
			tmp=t[i]+n-i-1;
			ans=min(tmp,ans);
		}
		printf("%d\n",ans);
	}
    return 0;
}
