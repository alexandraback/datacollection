#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char **argv){
	int caseno,i,j,k,res;
	int T;
	int n,s,sum,xtra;
	int a[1001];
	FILE *fin,*fout;

	fin=fopen("A-small-attempt0.in","rt");
	fout=fopen("A-small-attempt0.out","wt");
	//fin=fopen("test.txt","rt");
	//fout=fopen("result.out","wt");
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d",&n,&s);
		printf("%d %d\n",n,s);


		for(i=n;i>=0;i--){
			a[i]=s%10;
			s=s/10;
		}
		
		sum=a[0];xtra=0;
		for(i=1;i<=n;i++){
			if(sum>=i){
				sum+=a[i];
			}
			else{
				xtra+=(i-sum);
				sum=i+a[i];
			}
		}
		//for(i=0;i<=n;i++) printf("%d",a[i]);
		//printf("\n");
		
		
		fprintf(fout,"Case #%d: %d\n",caseno,xtra);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}