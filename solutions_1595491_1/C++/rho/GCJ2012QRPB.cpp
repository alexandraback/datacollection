#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;

FILE* fin;
FILE* fout;

int main(void)
{
	fin = fopen("Bsmall.in", "r");
	fout = fopen("Bsmall.out", "w");
	int T;
	fscanf(fin, "%d", &T);
	printf("%d", T);
	for(int t=1; t<=T; t++)
	{
		int N, S, min;
		fscanf(fin, "%d %d %d", &N, &S, &min);
		int ans=0;
		for(int i=0; i<N; i++)
		{
			int n;
			fscanf(fin, "%d", &n);
			switch(n%3)
			{
				case 0: if(n/3>=min) ans++; else if(n/3+1>=min && S>0 && n>0) {S--; ans++;} break;
				case 1: if(n/3+1>=min) ans++; break;
				case 2: if(n/3+1>=min) ans++; else if(n/3+2>=min && S>0) {S--; ans++;} break;
			}
		}
		fprintf(fout, "Case #%d: %d\n", t, ans);
				
	}
	return 0;
}
