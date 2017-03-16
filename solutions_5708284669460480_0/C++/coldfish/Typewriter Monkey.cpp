#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;
float max_repe;

int check[28] = { 0, };
char word[100] = { 0, },l;
char bb[100] = { 0, };
char aa[100] = { 0, };
int ccount, avg,k;
int testing(int s){
	int cnt = 0;
	for (int i = 0; i <= s-l; i++)
	{
		int flag = 0;
		if (bb[0] == word[i])
		{
			for (int j = 1; j < l; j++)
			{
				if (j + i == s) break;

				if (bb[j] != word[i + j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
		}
	}
	return cnt;
}
void makeword(int idx, int s){
	if (idx == s)
	{
		int m = testing(s);
		ccount++;
		avg += m;
		if (m > 0)
		{
			if (m > (int)max_repe)
				max_repe = m;
		}
		return;
	}

	for (int i = 0; i < k; i++)
	{
		word[idx] = aa[i];
		makeword(idx + 1, s);
	}
}
void main()
{
	FILE *fs = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");

	int testcase;
	fscanf(fs, "%d", &testcase);

	for (int t = 0; t < testcase; t++)
	{
		fprintf(fp, "Case #%d:", t + 1);

		int s,flag=1;
		max_repe = 0;
		ccount = 0;
		avg = 0;
		fscanf(fs, "%d %d %d\n", &k, &l, &s);
		fscanf(fs, "%s", aa);
		fscanf(fs, "%s", bb);
		for (int i = 0; i < 28; i++) check[i] = 0;
		for (int i = 0; i < k; i++)
		{
			check[aa[i] - 'A'] = 1;
		}
		for (int i = 0; i < l; i++){
			if (check[bb[i] - 'A'] == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0){
			fprintf(fp," 0.0\n");
			continue;
		}
		makeword(0, s);
		if (ccount == 0){
			fprintf(fp, " 0.0\n");
			continue;
		}
		fprintf(fp, " %.7f\n", max_repe - (float)avg / ccount);
	}
	fclose(fs);
	fclose(fp);
}