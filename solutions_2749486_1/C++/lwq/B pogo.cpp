#include<stdio.h>
FILE *in,*out;
int abs(int x)
{
	if( x<0 ) return -x;
	return x;
}
char o[1048576];
int main()
{
	in=fopen("b.in","r");
	out=fopen("b.out","w");
	int tc,test;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		int m,n,c,k,x,y,a;
		fscanf(in,"%d%d",&m,&n);
		fprintf(out,"Case #%d: ",test);
		c=0;
		for(k=0;;k++)
		{
			c+=k;
			if( c>=abs(m)+abs(n) && (c+m+n)%2==0 ) break;
		}
		x=0;
		y=0;
		for(a=k;a>=1;a--)
		{
			if( abs(m-x)>abs(n-y) )
			{
				if( x<m )
				{
					o[a]='E';
					x+=a;
				}
				else
				{
					o[a]='W';
					x-=a;
				}
			}
			else
			{
				if( y<n )
				{
					o[a]='N';
					y+=a;
				}
				else
				{
					o[a]='S';
					y-=a;
				}
			}
		}
		for(a=1;a<=k;a++) fprintf(out,"%c",o[a]);
		fprintf(out,"\n");
	}
	return 0;
}