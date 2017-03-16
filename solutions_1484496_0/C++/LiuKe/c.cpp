#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,s;
int a[100];
int f[3000000];

void out(int w)
{
	bool first=true;
	for (int i=0;i<n;i++)
		if ((w>>i)&1) 
		{
			if (!first) printf(" ");
			first=false;
			printf("%d",a[i]);
		}
	printf("\n");
}


int main()
{
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d:\n",t);
		scanf("%d",&n);	s=0;
		for (int i=0;i<n;i++)	scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		
		bool ok=false;
		for (int i=1;i<(1<<n);i++)
		{
			int now=0;
			for (int j=0;j<n;j++)
				if ((i>>j)&1) now+=a[j];
			if (f[now])
			{
				ok=true;
				out(i);	out(f[now]);
				break;
			}
			else f[now]=i;
		}
		if (!ok) printf("Impossible\n");
	}
	return 0;
}
				
				
		
	
	