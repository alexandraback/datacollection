#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int ans;
int p[2000];
int T,n,step;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (int test=1;test<=T;++test)
	{
        //cout<<1<<endl;
		scanf("%d",&n);
		ans=step=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&p[i]);
			step=max(step,p[i]);
		}
		ans=step;
		for (int m=1;m<=step;++m)
		{
			int tmp=0;
			for (int i=1;i<=n;++i) 
				if (p[i]>m) tmp+=(p[i]-1)/m;
			ans=min(ans,m+tmp);
		}            
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
