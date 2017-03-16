#include <stdio.h>

const int maxn=10003;

int ne[maxn],pr[maxn],s[maxn],prev[maxn],next[maxn];
long long v[maxn],save[maxn],need[maxn];
int i,j,k,m,n,t,tt;
long long e,r,now,x,y,tmp,ans;

void qs(int l,int r)
{
	int i,j,y;
	long long x;

	i=l;j=r;
	x=v[s[(i+j)/2]];

	while (i<=j)
	{
		while (v[s[i]]<x) i++;
		while (v[s[j]]>x) j--;
		if (i<=j)
		{
			y=s[i];s[i]=s[j];s[j]=y;
			i++;j--;
		}
	}
	if (i<r) qs(i,r);
	if (l<j) qs(l,j);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%lld%lld%d",&e,&r,&n);
		for (i=1;i<=n;i++)
		{
			scanf("%lld",&v[i]);
			save[i]=need[i]=prev[i]=next[i]=0;
			pr[i]=i-1;
			ne[i]=i+1;
			s[i]=i;
		}
		ne[0]=1;
		pr[n+1]=n;
		qs(1,n);
		for (i=1;i<=n;i++)
		{
			now=s[i];
			prev[now]=pr[now];
			next[now]=ne[now];
			ne[pr[now]]=ne[now];
			pr[ne[now]]=pr[now];
		}
		save[0]=e-r;
		for (i=n;i>=1;i--)
		{
			now=s[i];
			x=prev[now];y=next[now];
			if (y<=n)
			{
				tmp=(y-now)*r;
				save[now]=need[y]-tmp;
				if (save[now]<0)
					save[now]=0;
			}
			tmp=save[x]+(now-x)*r;
			if (tmp>e)
				tmp=e;
			need[now]=tmp;
		}
		ans=0;
		for (i=1;i<=n;i++)
		{
			ans+=(need[i]-save[i])*v[i];
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
}






