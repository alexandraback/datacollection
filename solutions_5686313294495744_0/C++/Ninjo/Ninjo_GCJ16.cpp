#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;


#define iFILE(N) freopen(#N, "r", stdin)
#define oFILE(N) freopen(#N, "w", stdout)

int main()
{

	iFILE(input.txt);
	oFILE(output.txt);
	int i,j,k,p,m,n,q;
	char b[100][21],c[100][21];
	scanf("%d",&m);
	for(p=1;p<=m;p++)
	{
		q=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s %s",&b[i],&c[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i!=j)
				{
					if(!strcmp(b[i],b[j]))
					{
						for(k=0;k<n;k++)
						{
							if(j!=k)
							{
								if(!strcmp(c[j],c[k]))
								q++;
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n",p,q);
	}
	return 0;
}
