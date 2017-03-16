#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

int test;
FILE *fo = fopen("output.txt","w");
int r, n, m, k, ap[10];

bool product(int a, int b, int c)
{
	int p[10];
	p[0] = 1;
	p[1] = a;
	p[2] = b;
	p[3] = c;
	p[4] = a*b;
	p[5] = b*c;
	p[6] = a*c;
	p[7] = a*b*c;

	int ch;
	for(int i = 0; i < k; i++) {
		ch = 0;
		for(int j = 0; j < 8; j++) {
			if(ap[i] == p[j]) {
				ch = 1;
				break;
			}
		}
		if(ch == 0)
			return false;
	}
	return true;
}

void process()
{
	for(int i = 2; i <= m; i++) {
		for(int j = 2; j <= m; j++) {
			for(int a = 2; a <= m; a++) {
				if(product(i,j,a)) {
					fprintf(fo, "%d%d%d\n", i,j,a);
					return;
				}
			}
		}
	}
}

int main()
{
	//FILE *fp = fopen("input.txt", "r");
	FILE *fp = fopen("C-small-1-attempt0.in", "r");
	fscanf(fp, "%d", &test);
	for(int t = 1; t <= test; t++) {
		// init

		//input
		fscanf(fp, "%d %d %d %d", &r, &n, &m, &k);
		fprintf(fo, "Case #1:\n");
		for(int i = 1; i <= r; i++) {
			for(int j = 0; j < k; j++)
				fscanf(fp, "%d", &ap[j]);
			process();
		}
	}

	fclose(fp);
	fclose(fo);
	return 0;
}