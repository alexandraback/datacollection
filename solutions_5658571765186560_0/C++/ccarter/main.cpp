#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int tt,tc;
    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		int s,r,c;
		scanf("%d %d %d",&s,&r,&c);
		if (r<c)
		{
			int t=r;
			r=c;
			c=t;
		}
		int ok=2;
		if (r*c%s!=0)
			ok=0;
		else
		{
			if (s>=7)
				ok=0;
			else if (s==1)
				ok=1;
			else if (s==2)
			{
				if (r>=2)
					ok=1;
				else
					ok=0;
			}
			else if (s==3)
			{
				if (c<=1)
					ok=0;
				else
					ok=1;
			}
			else if (s==4)
			{
				if (c<=2)
					ok=0;
				else
					ok=1;
			}
			else if (s==5 || s==6)
			{
				if (c<=3)
					ok=0;
				else
					ok=1;
			}
		}
		if (ok==1)
			printf("Case #%d: %s\n",tc,"GABRIEL");
		else
			printf("Case #%d: %s\n",tc,"RICHARD");
	}
    return 0;
}
