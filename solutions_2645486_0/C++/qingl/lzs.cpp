#include<cstdio>
#include<cstring>
typedef __int64 ll;
const int N = 10005;
int v[N],nxt[N];
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	int ca=1,E,R,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&E,&R,&n);
		for(i=1;i<=n;i++)scanf("%d",&v[i]);
		int j;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(v[j]>v[i])break;
			}
			nxt[i]=j;
			//printf("i:%d nxt:%d \n",i,nxt[i]);
			if(nxt[i]==n+1)nxt[i]=1000000007;
		}
		int e=E;
		ll ret=0;
		for(i=1;i<=n;i++)
		{
			ll vv=(ll)R*(nxt[i]-i);
			ll tp=E-vv;
			if(tp<0)tp=0;
			if(tp>e){e+=R;if(e>E)e=E;continue;}
			ret+=(ll)v[i]*(e-tp);
			e=tp+R;
		}
		printf("Case #%d: %I64d\n",ca++,ret);
	}
	return 0;
}