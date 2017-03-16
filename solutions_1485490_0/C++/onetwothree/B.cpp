#include<fstream>
#include<iostream>
#include<cstring>
//#include<cmath>
using namespace std;

//ofstream out("output.txt");
FILE *out=fopen("output.txt", "w");
long long a[100];
int tipoa[100];
long long b[100];
int tipob[100];
int N, M;
long long F[101][101];

int main(void)
{
	FILE *fp=fopen("input.txt", "r");

	int T;
	fscanf(fp, "%d\n", &T);
	for(int l=1;l<=T;l++)
	{
		memset(F, 0, sizeof(F));
		fscanf(fp, "%d %d", &N, &M);
		for(int i=0;i<N;i++)
			fscanf(fp, "%I64d %d", &a[i], &tipoa[i]);
		for(int i=0;i<M;i++)
			fscanf(fp, "%I64d %d", &b[i], &tipob[i]);
		long long result=0;
		for(int z=0;z<100;z++)
		for(int i=0;i<N;i++)
			for(int inizio=0;inizio<M;inizio++)
			{
				if(tipoa[i]!=tipob[inizio])
					continue;
				
				long long rem=a[i];
				long long matched=F[i][inizio];
				if(F[i][inizio]<=F[i][inizio+1])
				{
					matched=F[i][inizio+1];
					b[inizio]-=F[i][inizio+1]-F[i][inizio];
					matched+=min(rem, b[inizio]);
					result=max(result, matched);
					rem-=min(rem, b[inizio]);
					b[inizio]+=F[i][inizio+1]-F[i][inizio];
					F[i+1][inizio+1]=max(F[i+1][inizio+1], matched);
				}
				
				for(int j=inizio+1;j<M;j++)
				{
					if(tipoa[i]==tipob[j])
					{
						matched+=min(rem, b[j]);
						rem-=min(rem, b[j]);
					}
					F[i+1][j+1]=max(F[i+1][j+1], matched);
					result=max(result, matched);
				}
			}
		fprintf(out, "Case #%d: %I64d", l, result);
		fprintf(out, "\n");	
	}
	//out.close();
	fclose(out);
	fclose(fp);
}
