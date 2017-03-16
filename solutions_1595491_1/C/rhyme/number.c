#include<stdio.h>
int main()
{
int a[]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int b[]={0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11};
int t,n,s,p,k,count,i,total;
FILE *fp,*fw;
fp=fopen("/home/sidhant/Desktop/codejam/B-large.in","r");
fw=fopen("/home/sidhant/Desktop/codejam/output.txt","w");
fscanf(fp,"%d",&t);
k=1;
	while(k<=t)
	{	
		int count=0;
		fscanf(fp,"%d%d%d",&n,&s,&p);
		for(i=0;i<n;i++)
		{
			fscanf(fp,"%d",&total);
			if(a[total]>=p)
			count++;
			else if(s && b[total]>=p)
			{	
				count++;s--;
			}
		}
		fprintf(fw,"Case #%d: %d\n",k,count);
		k++;
	}
	return(0);
}
			
