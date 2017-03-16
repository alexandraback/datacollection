
#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp_in,*fp_out;
	fp_in = fopen("E:\\A-small-attempt2.in","r");
	fp_out = fopen("E:\\data.txt","w");
	
	int t,n,m;
	double s[205];
	double sum,temp,sum2,temp2;
	
	fscanf(fp_in,"%d",&t);
	for(int j=1;j<=t;j++){
		fscanf(fp_in,"%d",&n);
		
		sum = 0;
		for(int i=0;i<n;i++){
			fscanf(fp_in,"%lf",s+i);
			sum+=s[i];
		}
		temp = 2*sum/n;
		
		m = 0;
		sum2 = 0;
		for(int i=0;i<n;i++){
			if(s[i]<temp){
				sum2+=s[i];
				m++;
			}
		}
		temp2 = (sum2+sum)/m;
		
		fprintf(fp_out,"Case #%d:",j);
		for(int i=0;i<n;i++){
			if(s[i]>=temp)fprintf(fp_out," %lf",0.0);
			else fprintf(fp_out," %lf",(temp2 - s[i])/sum*100);
		}
		fprintf(fp_out,"\n");
	}
	
	fclose(fp_in);
	fclose(fp_out);
	
	return 0;
}

