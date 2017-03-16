/*
 * main.c
 *
 *  Created on: 13-Apr-2013
 *      Author: chaitu
 */
#include<stdio.h>
#include<stdlib.h>

void solve(char* in, char* out)
{
	FILE *inf, *ouf;

	inf = fopen(in, "r");
	ouf = fopen(out, "w");

	int cases, c;
	fscanf(inf, "%d", &cases);

	for(c=0;c<cases;c++){
		fprintf(ouf, "Case #%d: ", c+1);
		fflush(ouf);

		int A, N;
		int motes[100];

		fscanf(inf, "%d%d", &A, &N);

		int j;
		for(j=0;j<N;j++){
			fscanf(inf, "%d", &motes[j]);
		}

		int k;
		int tmp;
		for(j=0;j<N-1;j++){
			for(k=j+1;k<N;k++){
				if(motes[j] > motes[k]){
					tmp = motes[k];
					motes[k] = motes[j];
					motes[j] = tmp;
				}
			}
		}
		for(j=0;j<N;j++){
			printf("%d ", motes[j]);
		}
		printf("\n");
		int worstcase = N;
		int opscnt = 0;
		int curA = A;
		int minpos = N;
		int l;

		for(j=0;j<N;j++){
			int tmp = motes[j];

			if(curA > tmp){

				curA += tmp;

				l = opscnt + N - j -1;
				if(l < minpos){
					minpos = l;
				}
				continue;
			}
			while(curA <= tmp){
				curA += curA-1;
				opscnt++;
				if(opscnt >= worstcase){
					goto out;
				}
			}
			curA += tmp;
		}
		out:
		fprintf(ouf, "%d\n", minpos);
		fflush(ouf);
	}
}

int main(void)
{
	solve("/home/chaitu/codejam/jam1b/inp.sm", "/home/chaitu/codejam/jam1b/oup");
	return 0;
}
