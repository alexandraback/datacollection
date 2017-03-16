#include <stdio.h>
#include <istream>
#include <string.h>

#define abs(a,b) a>b? a-b : b-a
FILE *fs,*fp;
int main()
{
	fs=fopen("input.in","rt");
	fp=fopen("output.out","wt");

	int n,cnt;
	long long int a,b;

	fscanf(fs,"%d\n",&n);

	for(int i=0;i<n;i++)
	{
		fscanf(fs,"%lld/%lld",&a,&b);

		cnt=40;
		for(int j=1;j<=40;j++)
		{
			a*=2;
			if(a>=b)
			{
				a-=b;
				if(cnt>j) cnt=j;
			}
		}
		if(a!=0) fprintf(fp,"Case #%d: impossible\n",i+1);
		else	fprintf(fp,"Case #%d: %d\n",i+1,cnt);
	}

	fclose(fs);
	fclose(fp);
	return 0;
}