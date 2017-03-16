#include<stdio.h>
#include<string.h>
int a[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,121,104,101,115,111,99,118,120,100,117,105,103,108,98,107,114,122,116,110,119,106,112,102,109,97,113};
int main()
{
int t,i,l,k;
char str[500],c;
FILE *fp,*fw;
fp=fopen("/home/sidhant/Desktop/codejam/A-small-attempt0.in","r");
fw=fopen("/home/sidhant/Desktop/codejam/output.txt","w");
fscanf(fp,"%d\n",&t);
k=1;
	while(k<=t)
	{
		for(i=0;;i++)
		{
			c=getc(fp);
			if((c<'a' || c>'z') && c!=' ')
			break;
			str[i]=c;
		}
		l=i;
		fprintf(fw,"Case #%d: ",k);
		for(i=0;i<l;i++)
		fprintf(fw,"%c",a[str[i]]);
		fprintf(fw,"\n");
		k++;
	}
	return(0);
}
