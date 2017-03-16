/*
 * main.cpp
 *
 *  Created on: May 3, 2014
 *      Author: blding
 */

#include <cstdio>

int caseNum;
FILE * fin;
FILE * fout;

int a, b, k;

int main()
{
	fin = fopen("../input", "r");
	fout = fopen("../output", "w");
	fscanf(fin, "%d ", &caseNum);
	for (int caseId = 1; caseId <= caseNum; ++caseId) {
		fscanf(fin, "%d %d %d ", &a, &b, &k);
		int cnt = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if ((i & j) < k)
					++cnt;
			}
		}
		fprintf(fout, "Case #%d: %d\n", caseId, cnt);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}


