#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int sum[100000*20+5];
int num[21];
int main()
{

	FILE* in;
	FILE* out;
	
	int t,n;
	int i,j,k,l,u,s,f;
	
	in=fopen("C-small-attempt0.in","r");
	out=fopen("C-small-attempt0.out","w");
	
	fscanf(in,"%d",&t);
	
	for(i=1;i<=t;i++)
	{
		memset(sum,0,sizeof(sum));
		
		fprintf(out,"Case #%d: \n",i);
		fscanf(in,"%d",&n);
		
		for(j=0;j<n;j++)
		fscanf(in,"%d",&num[j]);
		
		f=0;
		for(j=1;j<(1<<20);j++){
			s=0;l=19;
			for(k=j;k>0;l--,k/=2){
				if(k%2==1){
					s+=num[l];
				}
			}
			
			if(sum[s]==0){
				sum[s]=j;
			}
			
			else{
				u=j&sum[s];
				j^=u;
				sum[s]^=u;
				l=19;u=0;
				for(k=j;k>0;l--,k/=2){
					if(k%2==1){
						if(u==0){
							u++;
							fprintf(out,"%d",num[l]);
						}
						else{
							fprintf(out," %d",num[l]);
						}
					}
				}
				fprintf(out,"\n");	
				l=19;u=0;
				for(k=sum[s];k>0;l--,k>>=1){
					if(k%2==1){
						if(u==0){
							u++;
							fprintf(out,"%d",num[l]);
						}
						else{
							fprintf(out," %d",num[l]);
						}
					}
				}
				
				fprintf(out,"\n");
				f=1;
				break;
			}
		}
		
		if(f==0){
			fprintf(out,"Impossible\n");
		}
	}
	
	fclose(in);
	fclose(out);
	return 0;
}

