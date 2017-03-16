#include<stdio.h>
#include<math.h>
FILE *fp,*fw;
scan()
{
int t=0;
char c;
	c=getc(fp);
	while(c>='0')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getc(fp);
	}
	return(t);
}
int main()
{
int t,a,b,i,num,l,divten,j,ten,rem,left,count,newnum,k,list[50],m,s,divident,temp;
char h[2000002]={0};
int tt[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
fp=fopen("/home/sidhant/Desktop/codejam/C-small-attempt0.in","r");
fw=fopen("/home/sidhant/Desktop/codejam/output.txt","w");
t=scan();
k=1;
	while(k<=t)
	{
		a=scan();
		b=scan();
		count=0;
		l=log10(a)+1;
		divident=tt[l-1];

		for(i=a;i<=b-1;i++)
		{	
			divten=divident;
			num=i;ten=tt[0];
			m=0;
			for(j=1;j<l;j++)
			{
				ten=tt[j];
				rem=num%ten;
				left=num/ten;
			
				newnum=rem*divten+left;
		
				if(newnum<=b && newnum>num && !h[newnum])
				{count++;h[newnum]=1;list[m++]=newnum;}
				divten=tt[l-j-1];
			}
			for(s=0;s<m;s++)
			h[list[s]]=0;
		}
		fprintf(fw,"Case #%d: %d\n",k,count);
		k++;
	}
	return(0);
}
