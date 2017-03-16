#include <iostream>
#include <string>
#include <stdio.h>
#include <map>

using namespace std;

int ans[1100000],s[510];

int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	int i,j;
	int n;
	int T;
	int tmp,tt;
	scanf("%d",&T);
	map<int,int> M;
	for (int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
		}
		ans[0]=0;
		M.clear();
		for (i=1;i<(1<<n);i++)
		{
			for (j=0,tmp=i-(i&(i-1));tmp;j++)
				tmp=(tmp>>1);
			ans[i]=ans[i&(i-1)]+s[j-1];
			if (M[ans[i]]>0)
			{
				tmp=M[ans[i]];
				tt=i;
				break;
			}
			else
				M[ans[i]]=i;
		}
		printf("Case #%d:\n",t);
		if (i==(1<<n))
			printf("Impossible\n");
		else
		{
			bool f=true;
			for (i=0;i<n;i++)
			{
				if (tmp&(1<<i))
				{
					if (!f)
						printf(" ");
					printf("%d",s[i]);
					f=false;
				}
			}
			printf("\n");
			f=true;
			for (i=0;i<n;i++)
			{
				if (tt&(1<<i))
				{
					if (!f)
						printf(" ");
					printf("%d",s[i]);
					f=false;
				}
			}
			printf("\n");
		}
	}
	return 0;
}