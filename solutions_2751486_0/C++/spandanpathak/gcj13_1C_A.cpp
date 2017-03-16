#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

FILE *f1,*f2;

char ch[1000010];

int main()
{
	long long x,y,p,q;
	int i,j,l,n,t;		
	
	f1=fopen("A-small-attempt0.in","r+");
	f2=fopen("out.txt","w");
		
	fscanf(f1,"%d",&t);
	
	
	for(int tt=1;tt<=t;tt++)
	{
		fscanf(f1,"%s",ch);
		fscanf(f1,"%d",&n);
		
		l=strlen(ch);
		
		x=0;
		
		for(i=0;i<l;i++)
		{
			p=0;
			
			for(j=i;j<l;j++)
				if( ch[j]!='a' && ch[j]!='e' && ch[j]!='i' && ch[j]!='o' && ch[j]!='u')
				{					
					p++;
					if(p==n) break;
				}
				else
					p=0;
			
			x+=(l-j);
		}
		
		
		fprintf(f2,"Case #%d: %d\n",tt,x);
	}
	
	return 0;
}