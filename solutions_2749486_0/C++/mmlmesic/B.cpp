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
	
	long long x,y,i;
	
	fi=fopen("B.in","r");
	fo=fopen("B.out","w");
	
	fscanf(fi,"%d\n",&t);
	
	for (tt=0;tt<t;tt++)
	{	
		fscanf(fi,"%lld %lld",&x,&y);
		
		fprintf(fo,"Case #%d: ",tt+1);		
		if (x>0) for (i=0;i<x;i++) fprintf(fo,"WE");
		if (x<0) for (i=0;i>x;i--) fprintf(fo,"EW");
		if (y>0) for (i=0;i<y;i++) fprintf(fo,"SN");
		if (y<0) for (i=0;i>y;i--) fprintf(fo,"NS");		
		fprintf(fo,"\n");
	}
	
	fclose(fi);
	fclose(fo);

	return 0;
}
