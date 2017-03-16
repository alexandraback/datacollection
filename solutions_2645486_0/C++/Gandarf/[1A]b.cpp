#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;
#define M 10010
int test;
FILE *fo = fopen("output.txt","w");
int res, v[M], E, R, N;

void process(int val, int p, int r)
{
	if (p == N) {
		res = max(res, val);
		return;
	}
	
	for(int i = max(0, r+R-E); i <= r; i++) {
		process(val+v[p]*i, p+1, min(E, r-i+R));
	}
}

int main()
{
	//FILE *fp = fopen("input.txt", "r");
	FILE *fp = fopen("B-small-attempt3.in", "r");
	fscanf(fp, "%d", &test);
	for(int t = 1; t <= test; t++) {
		// init

		//input
		fscanf(fp, "%d %d %d", &E, &R, &N);
		for(int i = 0; i < N; i++)
			fscanf(fp, "%d", &v[i]);

		//process
		if (R > E)
			R = E;
		res = 0;
		process(0, 0, E);

		//output
		fprintf(fo, "Case #%d: %d\n", t, res);
	}

	fclose(fp);
	fclose(fo);
	return 0;
}