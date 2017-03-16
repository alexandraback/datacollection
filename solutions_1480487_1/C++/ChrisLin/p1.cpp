// p1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

struct node
{
	int number;
	int score;
	double per;
};

int cmp(const void *a, const void *b)
{
	return ((node*)a)->score - ((node*)b)->score;
}

int cmp2(const void *a, const void *b)
{
	return ((node*)a)->number - ((node*)b)->number;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inFile("text.in");
	//ofstream outFile("ans.out");
	FILE *out = fopen("ans.out", "w");

	int n, m;
	node score[200];

	inFile >> n;
	for(int z = 0; z < n; z++)
	{
		inFile >> m;
		int sum = 0;
		for(int i = 0; i < m; i++)
		{
			inFile >> score[i].score;
			score[i].number = i;
			sum += score[i].score;
		}
		qsort(score, m, sizeof(node), cmp);
		double ave = (double)sum * 2 / m;
		int t = m - 1;
		int tmp = sum;
		while(true)
		{
			int tt = t;
			for(; t >= 0 && score[t].score > ave; tmp -= score[t].score, t--);
			ave = ((double)sum + tmp) / (t+1);
			if(tt == t)
				break;
		}
		for(int i = 0; i <= t; i++)
		{
			score[i].per = (ave - score[i].score) / sum;
		}
		for(int i = t + 1; i < m; i++)
			score[i].per = 0;
		fprintf(out, "Case #%d: ", z+1);
		qsort(score, m, sizeof(node), cmp2);
		for(int i = 0; i < m - 1; i++)
			fprintf(out, "%.6lf ", score[i].per * 100);
		fprintf(out, "%.6lf\n", score[m-1].per * 100);
	}
	return 0;
}

