#include<stdio.h>

int T;
int r,c;
int w;

int ans;

int main(){

	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");

	fscanf(fin,"%d",&T);

	int t;

	for (t = 1; t <= T; t ++ )
	{
		fscanf(fin,"%d %d %d",&r,&c,&w);

		ans = r*(c/w) + w-1;
		if( c %w )
		{
			ans ++;
		
		}
		fprintf(fout,"Case #%d: %d\n",t,ans);
	}
	return 0;
}