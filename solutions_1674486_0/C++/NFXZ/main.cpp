#include <stdio.h>
#include <iostream>
#include <set>
#include <math.h>
using namespace std;

int n;
int f[1030][1030];
int s[1030];
int doit[1030];
int yes=0;
void SS(int n);


int main()
{
	int t,n,i,j,k;

	FILE* in;
	FILE* out;
	
	in=fopen("A-small-attempt0.in","r");
	out=fopen("A-small-attempt0.out","w");
	
	fscanf(in,"%d",&t);
	
	for(k=1;k<=t;k++)
	{
		fprintf(out,"Case #%d: ",k);
		yes=0;
		fscanf(in,"%d",&n);
		
		for (i=1;i<=n;i++)
		{
			doit[i]=0;
			fscanf(in,"%d",&s[i]);
			
			for (j=1;j<=s[i];j++)
			fscanf(in,"%d",&f[i][j]);
		}
		
		
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)doit[j]=0;
			SS(i);
			if (yes) break;
		}
		if (yes) fprintf(out,"Yes\n"); 
		else fprintf(out,"No\n");
	}
	
	fclose(in);
	fclose(out);
	return 0;
}

void SS(int n)
{
	int i;
	if (yes) return ;
	for (i=1;i<=s[n];i++)
	{
		if (doit[f[n][i]]==1) yes=1;

		else doit[f[n][i]]=1;
		SS(f[n][i]);
	}
}

