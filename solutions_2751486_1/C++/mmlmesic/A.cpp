#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

char red[10000000];

int main()

{
	FILE *fi,*fo;
	

	
	char c[300];
	char ci;
	
	int i,j,t,tt;
	
	long long n,zaredom,maks,total;
	
	/*fi=fopen("A.in","w");
	fprintf(fi,"20\n");
	fprintf(fi,"bb");
	for (i=0;i<1099998;i++) fprintf(fi,"a");
	fprintf(fi," 2\n");
	for (i=0;i<1100000;i++) fprintf(fi,"b");
	fprintf(fi," 3\n");
	
	for (i=0;i<1100000;i++) fprintf(fi,"b");
	fprintf(fi," 2\n");
	for (i=0;i<1100000;i++) fprintf(fi,"b");
	fprintf(fi," 1\n");
	
	for (i=0;i<1000000;i++) fprintf(fi,"b");
	fprintf(fi," 3\n");
	
	for (i=0;i<1000000;i++) fprintf(fi,"b");
	fprintf(fi," 2\n");
	for (i=0;i<1000000;i++) fprintf(fi,"b");
	fprintf(fi," 1\n");
	
	
	for (i=0;i<10;i++) fprintf(fi,"b");
	fprintf(fi," 3\n");
	
	for (i=0;i<10;i++) fprintf(fi,"b");
	fprintf(fi," 2\n");
	for (i=0;i<10;i++) fprintf(fi,"b");
	fprintf(fi," 1\n");
	
	for (i=0;i<3;i++) fprintf(fi,"b");
	fprintf(fi," 3\n");
	
	for (i=0;i<3;i++) fprintf(fi,"b");
	fprintf(fi," 2\n");
	for (i=0;i<3;i++) fprintf(fi,"b");
	fprintf(fi," 1\n");


	for (i=0;i<2;i++) fprintf(fi,"b");
	fprintf(fi," 3\n");
	
	for (i=0;i<2;i++) fprintf(fi,"b");
	fprintf(fi," 2\n");
	for (i=0;i<2;i++) fprintf(fi,"b");
	fprintf(fi," 1\n");
	
	
	for (i=0;i<1;i++) fprintf(fi,"b");
	fprintf(fi," 3\n");
	
	for (i=0;i<1;i++) fprintf(fi,"b");
	fprintf(fi," 2\n");
	for (i=0;i<1;i++) fprintf(fi,"b");
	fprintf(fi," 1\n");
	
	
	
	
	for (i=0;i<1099998;i++) fprintf(fi,"a");
	fprintf(fi,"bb");
	fprintf(fi," 2\n");
	fclose(fi);
	*/
	fi=fopen("A.in","r");
	fo=fopen("A.out","w");
	
	fscanf(fi,"%d\n",&t);
	
//	printf("%d\n",t);
	
	for (ci='a';ci<='z';ci++) { //printf("%d\n",ci); 
	c[ci]=1; }
	c['a']=0;
	c['e']=0;
	c['i']=0;
	c['o']=0;
	c['u']=0;
	
	for (tt=0;tt<t;tt++)
	{	
		fscanf(fi,"%s %lld",red,&n);
//		printf("%s\n",red);
		maks=-1;
		zaredom=0;
		total=0;
		for (i=0;red[i];i++)
		{
			if (c[red[i]]) 
			{
				zaredom++;
				if (zaredom>=n) maks=i-n+1;
			}
			else 
			{
				zaredom=0;
			}
			if (maks!=-1) total+=maks+1;			
		}
		
		fprintf(fo,"Case #%d: %lld\n",tt+1,total);		
	}
	
	fclose(fi);
	fclose(fo);

	return 0;
}
