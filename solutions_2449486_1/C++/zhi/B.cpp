#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int main()
{
	int T,N,M,h,a[100][100],l[100][100];
	bool flag;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d %d",&N,&M);
		for(int j=0;j<N;j++)
			for(int k=0;k<M;k++)
			{
				scanf("%d",&a[j][k]);
				l[j][k]=100;
			}

		for(int j=0;j<N;j++)
		{
			flag=true;
			h=0;
			for(int k=0;k<M;k++)
				h=max(h,a[j][k]);
			for(int k=0;k<M;k++)
				if(h<a[j][k])
					flag=false;
			if(flag)
				for(int k=0;k<M;k++)
					l[j][k]=min(l[j][k],h);
		}

		for(int j=0;j<M;j++)
		{
			flag=true;
			h=0;
			for(int k=0;k<N;k++)
				h=max(h,a[k][j]);
			for(int k=0;k<N;k++)
				if(h<a[k][j])
					flag=false;
			if(flag)
				for(int k=0;k<N;k++)
					l[k][j]=min(l[k][j],h);
		}

		flag=true;
		for(int j=0;j<N;j++)
			for(int k=0;k<M;k++)
				if(a[j][k]!=l[j][k])
					flag=false;
			
		if(flag)
			printf("Case #%d: YES\n",i+1);
		else
			printf("Case #%d: NO\n",i+1);
	}
	return 0;
}
