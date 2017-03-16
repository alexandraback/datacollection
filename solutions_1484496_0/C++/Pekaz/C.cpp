#include <stdio.h>

int t,tcase,n,num[22];
int check[22];

int getnum(int x)
{
	int i,s1,s2;
	if(x==n)
	{
		s1=s2=0;
		for(i=0;i<n;i++)
		{
			if(check[i]==1)
				s1+=num[i];
			if(check[i]==2)
				s2+=num[i];
		}
		if(s1>0 && s1==s2)
			return 1;
	}
	else
	{
		check[x]=0;
		if(getnum(x+1)==1)
			return 1;
		check[x]=1;
		if(getnum(x+1)==1)
			return 1;
		check[x]=2;
		if(getnum(x+1)==1)
			return 1;
	}
	return 0;
}

int main()
{
	int i,j;

	FILE *in,*out;
	in=fopen("C-small-attempt0.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%d",&n);
		for(i=0;i<n;i++)
			fscanf(in,"%d",&num[i]);
		getnum(0);
		fprintf(out,"Case #%d:\n",t+1);
		for(i=0;i<n;i++)
		{
			if(check[i]==1)
				fprintf(out,"%d ",num[i]);
		}
		fprintf(out,"\n");

		for(i=0;i<n;i++)
		{
			if(check[i]==2)
				fprintf(out,"%d ",num[i]);
		}
		fprintf(out,"\n");
	}

	return 0;
}