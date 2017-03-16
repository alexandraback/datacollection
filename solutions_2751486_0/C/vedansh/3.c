#include<stdio.h>
#include<string.h>
void main()
{
int a,b,m,t,i,x,l,n,j,p,k;
char s[100];
    scanf("%d",&t);
    for ( i=0;i< t; ++i)
    {
	x=0;m=1;
	scanf("%s %d",s,&n);
	l=strlen(s);
	for(j=0;j<l;j++)
	{
		p=0;
		for(k=j;k<l;k++)
		{
			if(s[k]!='a' && s[k]!='e' && s[k]!='i' && s[k]!='o' && s[k]!='u' )
				p++;
			else break;
			if(p == n && m==1) {
				x=x+(j+1)*(l-k);
				a=j;b=k;m=0;
				break;
			}
			else if(p==n) {
				x+=(l-k)*(j-a);
				a=j;
				break;
			}
		}
	}
		printf("Case #%d: %d\n",i+1,x);
	}
}
		
