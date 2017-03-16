#include<stdio.h>

void main()
{
	FILE *fi=fopen("B-small-attempt0.in","r");
	FILE *fo=fopen("B-small-attempt0.out","w");
	int t,i,j,x,y;

	fscanf(fi,"%d",&t);
	for(i=0;i<t;i++){
		fscanf(fi,"%d %d",&x,&y);
		fprintf(fo,"Case #%d: ",i+1);
		if(x>0) for(j=0;j<x;j++) fprintf(fo,"WE");
		else for(j=0;j<-1*x;j++) fprintf(fo,"EW");
		
		if(y>0) for(j=0;j<y;j++) fprintf(fo,"SN");
		else for(j=0;j<-1*y;j++) fprintf(fo,"NS");
		fprintf(fo,"\n");
	}
}