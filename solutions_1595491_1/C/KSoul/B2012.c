#include <stdio.h>

int main()
{
	FILE *pFile1,*pFile2;
	pFile1=fopen("B-large.in","r");
	pFile2=fopen("B-large.out","w");
	int i,j,t,n,s,p;
	fscanf(pFile1,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(pFile1,"%d %d %d",&n,&s,&p);
		int sol=0,a,b=s;
		for(j=0;j<n;j++)
		{
			fscanf(pFile1,"%d",&a);
			if(p>=2)
			{
				if(a>=p*3-2)
				{
					if(a>=2)
					sol++;
				}
				else if(a>=p*3-4&&a<p*3-2)
				{
					if(b>0)
					{
						sol++;
						b--;
					}
				}
			}
			else if(p==1)
			{
				if(a>=1) sol++;	
			}
			else if(p==0) sol=n;
		}
		fprintf(pFile2,"Case #%d: %d\n",i+1,sol);
	}
    return 0;
}
