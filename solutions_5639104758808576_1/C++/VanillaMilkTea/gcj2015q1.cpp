#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char **argv){
	int caseno,i,j,k,res;
	int T;
	int n,s,sum,xtra;
	int a[1101];
	FILE *fin,*fout;

	fin=fopen("A-large.in","rt");
	fout=fopen("A-large.out","wt");
	//fin=fopen("test.txt","rt");
	//fout=fopen("result.out","wt");
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d",&n);
		//printf("%d\n",n);
		s=fgetc(fin);
		//printf("%c\n",s);
		for(i=0;i<=n;i++){
			s=fgetc(fin);
			a[i]=s-48;
			//printf("%d %c  ",s,s);
			//printf("%d",a[i]);
		}
		//printf("\n");
		//
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
		//
		/*
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
		*/
		//for(i=0;i<=n;i++) printf("%d",a[i]);
		//printf("\n");
		
		
		fprintf(fout,"Case #%d: %d\n",caseno,xtra);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}