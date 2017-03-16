#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <string>

using namespace std;

int T,ts,n,i,x,a[300],it,j;
double l,r,c,p,z;

int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		x=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			x+=a[i];
		}
		printf("Case #%d:",++ts);
		for(i=0;i<n;i++)
		{
			l=0;
			r=1;
			it=0;
			while(l<r && it<100)
			{
				it++;
				c=(l+r)/2;
				p=a[i]+x*c;
				z=0;
				for(j=0;j<n;j++)
					if(a[j]<p)
						z+=(p-a[j])/x;
				if(z>1)
					r=c;
				else
					l=c;
			}
			printf(" %.12lf",l*100);
		}
		printf("\n");
	}
	return 0;
}			