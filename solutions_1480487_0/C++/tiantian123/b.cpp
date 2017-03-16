#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;

int n,nn,s[201];
double j[101],x,xx,p;

int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("output.out","w",stdout);
	int cas = 1;
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:",cas++);
		scanf("%d",&n);
		x = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d",&s[i]);
			x += s[i];
		}
		x *= 2;
		p = x/n;
		nn = n;
		xx = x;
		for(i=0; i<n; i++)
			if(s[i]>=p)
			{
				nn--;
				xx -= s[i];
			}
		for(i=0; i<n; i++)
		{
			if(s[i]>=p)
				j[i] = 0;
			else
				j[i] = (xx/nn-s[i])/x;
			//printf("%lf ",j[i]*200);
		}
		//j[i] = (xx/nn-s[i])/x;
		for(i=0; i<n; i++)
			printf(" %lf",j[i]*200);
		puts("");
	}
	return 0;
}
