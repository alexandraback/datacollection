#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

char red[10000000];

int i,j,t,tt,a,b,c,k,best;

int ab[10][10],bc[10][10],ac[10][10],abc[10][10][10];

int res[1000][3],bres[1000][3];

void rec(int ai, int bi, int ci, int d)
{
	int maxi;
	
	if (d>best)
	{
		best=d;
		int i,j;
		for (i=0;i<best;i++) for (j=0;j<3;j++) bres[i][j]=res[i][j];
	}
	if (ai==a) return;
	
	
	if (abc[ai][bi][ci]==0)
	maxi=ab[ai][bi];
	if (ac[ai][ci]>maxi) maxi=ac[ai][ci];
	if (bc[bi][ci]>maxi) maxi=bc[bi][ci];
	
	int cin,bin,ain;
	
	
	cin=ci;bin=bi;ain=ai;
	
	cin++;
	if (cin==c) {cin=0; bin++;}
	if (bin==b) {bin=0; ain++;}
	rec(ain,bin,cin,d);
	
	if (maxi<k)
	{
		
		res[d][0]=ai;
		res[d][1]=bi;
		res[d][2]=ci;
		d++;
		abc[ai][bi][ci]++;
		ab[ai][bi]++;
		ac[ai][ci]++;
		bc[bi][ci]++;
			//printf("%d: %d %d %d\n",d,ai,bi,ci);
		rec(ain,bin,cin,d);
		abc[ai][bi][ci]--;
		ab[ai][bi]--;
		ac[ai][ci]--;
		bc[bi][ci]--;
	}
}

int main()

{
	FILE *fi,*fo;
	


	
	
	
	
	
	
	
	long long n,tot,ttot,zaredom,maks,total,count;
	
	bool seen[10],all;
	
	fi=fopen("C.in","r");
	fo=fopen("C.out","w");
	
	fscanf(fi,"%d\n",&t);
	
	
	for (tt=0;tt<t;tt++)
	{	
		
		fscanf(fi,"%d%d%d%d",&a,&b,&c,&k);
		
		int ai,bi,ci;
		
		for (ai=0;ai<10;ai++) for (bi=0;bi<10;bi++) for (ci=0;ci<10;ci++)
		{
			ab[ai][bi]=ac[ai][ci]=bc[bi][ci]=0;
			abc[ai][bi][ci]=0;
		}
		
		best=0;
		rec(0,0,0,0);
		printf("%d\n",tt);
		fprintf(fo,"Case #%d: %d\n",tt+1,best);
		for (i=0;i<best;i++) fprintf(fo,"%d %d %d\n",bres[i][0]+1,bres[i][1]+1,bres[i][2]+1);
	}
	
	fclose(fi);
	fclose(fo);

	return 0;
}



