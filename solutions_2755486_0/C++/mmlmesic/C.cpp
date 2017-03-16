#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()

{
	FILE *fi,*fo;
	
	int t,tt;
	
	long long i,j,n,di[2000],ni[2000],wi[2000],ei[2000],si[2000],delta_di[2000],delta_pi[2000],delta_si[2000];
	
	long long w[2000];
	
	long long z=1000;
	
	long long total;
	
	fi=fopen("C.in","r");
	fo=fopen("C.out","w");
	
	fscanf(fi,"%d\n",&t);
	
	for (tt=0;tt<t;tt++)
	{	
		fscanf(fi,"%lld",&n);
		for (i=0;i<z*2;i++) w[i]=0;
		
		for (i=0;i<n;i++)
		{
			fscanf(fi,"%lld %lld %lld %lld %lld %lld %lld %lld",&di[i],&ni[i],&wi[i],&ei[i],&si[i],&delta_di[i],&delta_pi[i],&delta_si[i]);
		}
		
		printf("---------------------\n");
		long long dimin;
		total=0;
		while (1)
		{
			dimin=-1;
			bool barjedan=false;
			for (i=0;i<n;i++) if (ni[i] && (dimin==-1 || dimin>di[i]))
			{
				barjedan=true;
				dimin=di[i];
			}
			if (not barjedan) break;
			for (i=0;i<n;i++) if (ni[i] && (dimin==di[i]))
			{
				bool success=false;
				for (j=wi[i];j<ei[i];j++) if (w[j+z]<si[i])
				{
					total++;
					printf("Day %lld Tribe %lld attacks [%lld,%lld] at %lld and succeds\n",dimin,i+1,wi[i],ei[i],si[i]);
					success=true;
					break;
				}
				if (not success) printf("Day %lld Tribe %lld attacks [%lld,%lld] at %lld and FAILS\n",dimin,i+1,wi[i],ei[i],si[i]);
			}
			for (i=0;i<n;i++) if (ni[i] && (dimin==di[i]))
			{
				for (j=wi[i];j<ei[i];j++) if (w[j+z]<si[i]) 
				{
					w[j+z]=si[i];
				}
				ni[i]--;
				di[i]+=delta_di[i];
				wi[i]+=delta_pi[i];
				ei[i]+=delta_pi[i];
				si[i]+=delta_si[i];
			}
			
		}	
		fprintf(fo,"Case #%d: %lld\n",tt+1,total);		
	}
	
	fclose(fi);
	fclose(fo);

	return 0;
}
