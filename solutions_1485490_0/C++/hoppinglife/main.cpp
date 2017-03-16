#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;
long T;
long long n,m,a1[500],a20[500],n1[500],n2[500],t1[500];
long ll[5];

long long dfs(long x,long y)
{
	long long now=0;
	long long t=0;
	if (x<n-1)
	{
		for (long b=y;b<=m;++b)
		{
			ll[x+1]=b;
			t=dfs(x+1,b);
			if (t>now)
			{
				now=t;
			}
		}
	}else
	{
		long long re=0;
		for (long a=1;a<=m;++a) t1[a]=n2[a];
		for (long a=1;a<=n;++a)
		{
			long long all=n1[a];
			//	printf("%d,",lis[a]);
			for (long b=ll[a-1];b<=ll[a];++b)
			{

				if (a1[a]==a20[b])
				{
					if (t1[b]<all)
					{
						all-=t1[b];
						re+=t1[b];
						t1[b]=0;
					}else
					{
						t1[b]-=all;
						re+=all;
						all=0;
						break;
					}

				}
				//	printf("<%d,%d:%d,%d = %d>",a,b,ty1[a],ty2[b],re);
			}
		}
		//	printf(":= %d\n",re);
		return re;
	}
	return now;
}
int main()
{
	freopen("result.in","r",stdin);
	freopen("result.out","w",stdout);
	cin>>T;
	for (int k=1;k<=T;++k)
	{
		cin>>n>>m;
		for (int a=1;a<=n;++a)
		{
			cin>>n1[a]>>a1[a];
		}
		for (int a=1;a<=m;++a)
		{
			cin>>n2[a]>>a20[a];
		}
		printf("Case #%d: ",k);
		for(int i=0;i<5;i++) ll[i] = 0;
		ll[0]=1;
		ll[n]=m;
		cout<<dfs(0,0)<<endl;

	}
}