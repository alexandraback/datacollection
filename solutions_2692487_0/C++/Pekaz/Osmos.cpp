#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int t,n,tcase;
	__int64 a,num[102],sum;
	int i,j,re,cnt,sumre[102];

	FILE *in,*out;
	in=fopen("A-small-attempt0.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%I64d",&a);
		fscanf(in,"%d",&n);
		for(i=0;i<n;i++)
			fscanf(in,"%I64d",&num[i]);

		if(a==1)
		{
			fprintf(out,"Case #%d: %d\n",t+1,n);
			continue;
		}
		sort(&num[0],&num[n]);
		sum=a;
		re=0;
		for(i=0;i<102;i++)
			sumre[i]=0;
		for(i=0;i<n;i++)
		{
			if(num[i]>=sum)
			{
				cnt=0;
				while(1)
				{
					sum+=sum-1;
					cnt++;
					if(num[i]<sum)
						break;
				}
				sumre[i]=cnt;
				i--;
				continue;
			}
			else
				sum+=num[i];
		}

		re=n;
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(cnt+sumre[i]+(n-i-1) < re)
				re=cnt+sumre[i]+(n-i-1);
			cnt+=sumre[i];
		}
		fprintf(out,"Case #%d: %d\n",t+1,re);
	}

	return 0;
}