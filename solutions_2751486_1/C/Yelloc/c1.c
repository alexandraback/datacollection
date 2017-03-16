#include<stdio.h>
#include<string.h>
#define MAX_NAME 1000000
void main(){
	int t,tcase;
	char name[MAX_NAME+1];
	int n;
	int i,j;
	int con,pre,aft,len;
	__int64 sum;
	FILE *fin,*fout;
	fin=fopen("A-large.in","rw");
	fout=fopen("out.txt","ww");
	fscanf(fin,"%d",&tcase);
	for(t=1;t<=tcase;t++){
		fscanf(fin,"%s%d",name,&n);
		len=strlen(name);
		sum=0;
		for(i=0,pre=0,con=0;i<len;i++){
			pre++;
			if(name[i]!='a'&&name[i]!='e'&&name[i]!='i'&&name[i]!='o'&&name[i]!='u'){
				con++;
				if(con==n){
					sum+=(__int64)(pre-n+1)*(__int64)(len-i);
					pre=n-1;
					con--;
				}
			}else{
				con=0;
			}
		}
		fprintf(fout,"Case #%d: %I64d\n",t,sum);
	}
	fclose(fin);
	fclose(fout);
}