#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
#define maxn 3000010
int a[100],vis[maxn];
int aa[100],at;
int bb[100],bt;
int vv[25];
int main()
{
	int i,j,ncase,tt=0,f;
	double sum;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(vis,0,sizeof(vis));
		int f,ff,res;
		for(i=1;i<(2<<n);i++)
		{
			int tmp=i,t=0,ans=0;
			while(tmp)
			{
				if(tmp&1==1) ans+=a[t];
				t++;
				tmp/=2;
			}
			if(vis[ans])
			{
				memset(vv,0,sizeof(vv));
				tmp=vis[ans];
				t=0;
				while(tmp)
				{
					if(tmp&1==1) vv[t]=1;
					t++;
					tmp/=2;
				}
				tmp=i; int pan=0;
				t=0;
				while(tmp)
				{
					if(tmp&1==1) 
						if(vv[t]) 
							pan=1;
					t++;
					tmp/=2;
				}
				if(pan==0)
				{
					res=ans;
					f=i;
					break;
				}
			}else vis[ans]=i;
		}
		printf("Case #%d:\n",++tt);
		if(i==(2<<n)) 
		{
			printf("Impossible\n");
			continue;
		}
		int t=0,tmp=vis[res]; 
		at=0; bt=0;
		while(tmp)
		{
			if(tmp&1) aa[at++]=t;
			t++; tmp/=2;
		}
		tmp=f; t=0;
		while(tmp)
		{
			if(tmp&1) bb[bt++]=t;
			t++; tmp/=2;
		}
		for(i=0;i<at;i++)
		{
			if(i==at-1) printf("%d\n",a[aa[i]]);
			else printf("%d ",a[aa[i]]);
		}
		for(i=0;i<bt;i++)
		{
			if(i==bt-1) printf("%d\n",a[bb[i]]);
			else printf("%d ",a[bb[i]]);
		}
	}
	return 0;
}
