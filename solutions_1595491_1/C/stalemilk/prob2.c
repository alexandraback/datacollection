#include<stdlib.h>
#include<math.h>
#include<stdio.h>


main()
{
	FILE *ifile;
	FILE *ofile;
	ifile = fopen("input.txt", "r");
	ofile = fopen("output.txt", "w");
	int t,n,s,p;
	int i,j,k=1,x,y=1,z;
	fscanf(ifile,"%d",&t);
	while(t--)
	{	
		x=0;
		
		fscanf(ifile,"%d%d%d",&n,&s,&p);
		y=3*p-3;
		j=0;
		for(i=0;i<n;i++)
		{
			fscanf(ifile,"%d",&z);
			if(z>y)
			{
				x++;
			//	printf("%d ",z);
			}
			else if(z>=y-1 && j<s && z!=0)
			{
				x++;
			//	printf("%d ",z);
				j++;
			}
		}
		fprintf(ofile,"Case #%d: %d\n",k,x);
		k++;
	}
} 			
