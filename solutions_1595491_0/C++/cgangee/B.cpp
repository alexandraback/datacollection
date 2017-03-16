#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;

const int N=100;

int i,j,k,m,n,l,p;
int a[N+10];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1; t<=T; t++)
	{
		scanf("%d%d%d",&n,&m,&p);
		int ans=0;
		for (i=1; i<=n; i++)
		{
			scanf("%d",&k);
			if (k%3==0)
			{
				if (k/3>=p) ans++;
				else if (k/3+1>=p && m && k/3>0)
				{
					ans++;
					m--;
				}
			}
			else if (k%3==1)
			{
				if (k/3+1>=p) ans++;
			}
			else if (k%3==2)
			{
				if (k/3+1>=p) ans++;
				else if (k/3+2>=p && m)
				{
					ans++;
					m--;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
}
