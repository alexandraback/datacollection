#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	int rate,x;
}a[1010];

int s[3][1010],gone[1010];

bool cmp(node a,node b)
{
	if (a.rate>b.rate||(a.rate==b.rate&&s[2][a.x]>s[2][b.x])) return true;
	else return false;
}

int main()
{
	int T,i,sum,now,ans,n,j,pos;
	bool flag;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d%d",&s[1][i],&s[2][i]);
		memset(gone,0,sizeof(gone));
		sum=n*2; now=0; ans=0; flag=true;
		while (sum)
		{
			pos=0;
			for (i=1;i<=n;i++)
				for (j=gone[i]+1;j<=2;j++)
				{
					if (now<s[j][i]) continue;
					a[pos].rate=j; a[pos].x=i;
					pos++;
				}
			if (pos==0)
			{
				flag=false; break;
			}
			sort(a,a+pos,cmp);
			pos=0;
			sum-=(a[pos].rate-gone[a[pos].x]);
			now+=(a[pos].rate-gone[a[pos].x]);
			gone[a[pos].x]=a[pos].rate; ans++;
		}
		if (flag) printf("Case #%d: %d\n",tt,ans);
		else printf("Case #%d: Too Bad\n",tt);
	}
	return 0;
}
