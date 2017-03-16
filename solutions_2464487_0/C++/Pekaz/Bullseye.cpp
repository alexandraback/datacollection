#include <stdio.h>

int main()
{
	int t,tcase;
	__int64 lit,r,pm;
	__int64 st,ed,mid,re;

	FILE *in,*out;
	in=fopen("A-small-attempt0.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%I64d",&r);
		fscanf(in,"%I64d",&lit);

		pm=((r+1)*(r+1))-(r*r);

		mid=1;
		while(1)
		{
			if(((pm+(pm+4*(mid-1)))*mid)/2 <= lit)
			{
				re=mid;
				mid*=2;
			}
			else
			{
				st=mid/2;
				ed = mid;
				break;
			}
		}

		while(1)
		{
			if(st>ed) break;
			mid = (st+ed)/2;
			
			if(((pm+(pm+4*(mid-1)))*mid)/2 <= lit)
			{
				st=mid+1;
				re=mid;
			}
			else
				ed=mid-1;
		}
		fprintf(out,"Case #%d: %I64d\n",t+1,re);
	}

	return 0;
}