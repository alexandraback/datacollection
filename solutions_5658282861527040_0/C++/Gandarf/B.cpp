#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int test, caseNum;
int a, b, k, res;

int main()
{
	FILE *in = fopen("B-small-attempt0.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		fscanf(in, "%d %d %d", &a, &b, &k);

		res = 0;
		int r;
		for (int i = 0 ; i < a; i++) {
			for (int j = 0 ; j < b; j++) {
				r = i&j;
				if (r < k)
				{
					//if (caseNum == 1) printf("%d & %d = %d\n", i, j, r);
					res++;
				}
			}
		}
		//printf("k = %d\n", k);
		
		fprintf(out, "Case #%d: %d\n", caseNum++, res);
	}

	fcloseall();
	return 0;
}
