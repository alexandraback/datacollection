#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int i,j,k,n,p,s,t;
	int pos[3];
	int surprise_count,total;
	int triplet[101];
	FILE *in,*out;
	in = fopen("test.in","r");
	out = fopen("test.out","w");

	fscanf(in,"%d\n",&t);
	for (i = 0; i < t; i++)
	{
		fscanf(in,"%d%d%d",&n,&s,&p);
		for (j = 0, surprise_count = 0, total = 0;
				j < n; j++)
		{
			fscanf(in,"%d",triplet+j);
			
			if (triplet[j] >= 3*p)
			{
				total++;
			}
			else if (p-1 >= 0  && triplet[j] >= 3*p-2)
			{
				total++;
			}
			else if (p-2 >= 0)
			{
				if (triplet[j] == 3*p-4)
				{
					surprise_count++;
				}
				else if ( triplet[j] == 3*p-3)
				{
					surprise_count++;
				}
			}
		}
		total += surprise_count > s ? s : surprise_count;
		fprintf(out,"Case #%d: %d\n",i+1,total);
	}
	
	//fprintf(out,"Case #%d: %d %d\n",count,i+1,j+1);
    return 0;	
}