#include <stdio.h>

void main(int argc, char **argv)
{
	int T;
	scanf("%d",&T);
	int i;
	for(i=1;i<=T;i++)
	{
		int a,b,v,cnt=0;
		scanf("%d%d",&a,&b);
		int mp=1,rots=-1,tmp=b;
		while (tmp)
		{
			mp*=10;tmp/=10;rots++;
		}
		mp/=10;
		for (v=a;v<=b;v++)
		{
			int x=v,r=0,ro=rots,v2=v;
			while (ro)
			{
				ro--;
				r=v2%10;x=v2/10;
				v2=r*mp+x;
				if (v==v2) break;
				if (v>=v2||v2<a||v2>b)
				{ 
					continue;
				}
				cnt++;
			}
		}
		printf("Case #%d: %d\n",i,cnt);
	}
}
