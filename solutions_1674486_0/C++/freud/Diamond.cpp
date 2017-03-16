// Diamond.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
FILE *fin,*fout;

int T,N,i,j,k,t;
int data[1001][1001];
int visit[1002];
int answer;

int dfs(int k) {
	if (visit[k]==1) {
		return 1;
	}
	int i;
	visit[k] = 1;

	int ans = 0;
	for (i=1;i<=data[k][0];i++) {
		if  ( dfs(data[k][i]) == 1 )
			return 1;
	}

	return 0;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	fin = fopen("Diamond.txt","r");
	fout=fopen("Diamond.out","w");


	fscanf(fin,"%d",&T);
	for (t=1;t<=T;t++) {
		fscanf(fin,"%d",&N);

		memset(data,0,sizeof(data));
		for (i=1;i<=N;i++){
			
			fscanf(fin,"%d",&data[i][0]);
			for (int c=1;c<=data[i][0];c++) {
				fscanf(fin,"%d",&data[i][c]);
			}
		}

		// process

		
		
 		for (i=1;i<=N;i++) {
			memset(visit,0,sizeof(visit));
			answer = dfs(i);
			if (answer==1)
				break;
		}

		if (answer==1)
			fprintf(fout,"Case #%d: Yes\n",t);
		else
			fprintf(fout,"Case #%d: No\n",t);

		int xxx=234;
	}



	fclose(fin);
	fclose(fout);



	getch();
	return 0;
}

