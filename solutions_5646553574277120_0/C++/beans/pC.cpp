#include<bits/stdc++.h>
using namespace std;
const int maxD=100+5;
int a[35];
struct Seg
{
	int l,r;
	bool operator < (const Seg& rhs) const
	{
		return l<rhs.l || (l==rhs.l && r<rhs.r);
	}
};
vector<Seg> vec;
int main()
{
//	freopen("smallC.in","r",stdin);
//	freopen("smallC.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof a);
		a[0]=1;
		int C,D,V;
		scanf("%d%d%d",&C,&D,&V);
		for(int i=0,x;i<D;i++)
		{
			scanf("%d",&x);
			for(int j=V-x;j>=0;j--) if(a[j]) a[j+x]=1;
		}
		int ans=0;
		for(int i=0;i<=V;i++)
		{
			if(!a[i])
			{
				ans++;
				for(int j=V-i;j>=0;j--) if(a[j]) a[j+i]=1;
			}
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
}
