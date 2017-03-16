#include<stdio.h>
#include<string.h>
#include<vector.h>
FILE *in,*out;
int i[1024];
int b[1024];
int main()
{
	in =fopen("a.in" ,"r");
	out=fopen("a.out","w");
	int tests,test;
	int n,t,k,m,a;
	fscanf(in,"%d",&tests);
	for(test=0;test<tests;test++)
	{
		fscanf(in,"%d",&n);
		t=0;
		for(a=0;a<n;a++)
		{
			fscanf(in,"%d",&i[a]);
			t+=i[a];
		}
		for(a=0;a<n;a++) b[a]=0;
		k=n;
		m=t*2;
		for(a=0;a<n;a++)
		{
			if( b[a]==0 && m<i[a]*k )
			{
				b[a]=1;
				m-=i[a];
				k--;
				a=-1;
			}
		}
		fprintf(out,"Case #%d:",test+1);
		for(a=0;a<n;a++)
		{
			if( b[a]==1 ) fprintf(out," 0");
			else fprintf(out," %f",(float)((m-i[a]*k)*100)/k/t);
		}
		fprintf(out,"\n");
	}
	return 0;
}