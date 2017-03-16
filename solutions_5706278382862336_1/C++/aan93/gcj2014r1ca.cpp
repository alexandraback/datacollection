#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
FILE *in,*out;
long long int lcd(long long int a,long long int b)
{
	if (a==0) return b;
	else return lcd(b%a,a);
}
int main()
{
	in=fopen("in.txt","r");
	out=fopen("out.txt","w");
	int t,z;
	long long int p,q,r;
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		fscanf(in,"%ld/%ld",&p,&q);
		r=lcd(p,q);
		p/=r;
		q/=r;
		z=0;
		for (;q>1;)
		{
			if (p<q) z++;
			if (q%2==0)
			{
				q/=2;
			}
			else
			{
				q=-1;
				fprintf(out,"Case #%d: impossible\n",i);
			}
		}
		if (q!=-1) fprintf(out,"Case #%d: %d\n",i,z);
	}
	fclose(in);
	fclose(out);
	return 0;
}
