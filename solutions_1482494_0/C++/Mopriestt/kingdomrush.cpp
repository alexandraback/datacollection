#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN=1005;

struct level
{
	int s,b;
}a[MAXN];

int n,i,j,k,ans,cas,now,tot,DAT,MAX;
bool used[MAXN],flag,som[MAXN];

int cmp(const void *p,const void *q)
{
	return ((level *)p)->b-((level *)q)->b;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&DAT);
	for (cas=1;cas<=DAT;cas++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d",&a[i].s,&a[i].b);
		qsort(a+1,n,sizeof(a[1]),cmp);
		ans=0;
		now=0;
		tot=0;
		for (i=1;i<=n;i++) som[i]=used[i]=false;
		j=1;
		while (tot<n)
		{
			flag=true;
			while (flag)
			{
				flag=false;
				for (i=1;i<=n;i++)
					if (!used[i] && now>=a[i].b)
					{
						used[i]=true;
						if (!som[i]) now+=2;
						else now+=1;
						++tot;
						++ans;
						flag=true;
					}
			}
			if (tot==n) break;
			MAX=0;
			j=0;
			for (i=1;i<=n;i++)
				if (!used[i] && !som[i] && a[i].b>MAX && a[i].s<=now) 
				{
					MAX=a[i].b;
					j=i;
				}
			if (j==0) break;
			som[j]=true;
			++now;
			++ans;
		}
		if (tot==n) printf("Case #%d: %d\n",cas,ans);
		else printf("Case #%d: Too Bad\n",cas);
	}
	return 0;
}
