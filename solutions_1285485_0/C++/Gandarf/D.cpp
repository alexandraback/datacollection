#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 250
#define M 35

int ttest, test, i, j, k, h, w, d, res, t1, t2;
int x, y, W, H, start, a, q;
double temp;
int map[N][N] = {0,}, dxdy[N][N] = {0,};
char s[M][M] = {0,};

void srs();

int main()
{
	//FILE *fp1 = fopen("input.txt", "r");
	FILE *fp1 = fopen("D-small-attempt0.in", "r");
	FILE *fp2 = fopen("output.txt", "w");

	fscanf(fp1, "%d", &test);
	for(ttest = 1; ttest <= test; ttest++)
	{
		// init
		res = 0;
		a = 100;
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				dxdy[i][j] = map[i][j] = 0;

		// input
		fscanf(fp1, "%d %d %d\n", &h, &w, &d);
		for(i = 0; i < h; i++)
			fscanf(fp1, "%s", s[i]);

		for(i = 1; i < h-1; i++)
		{
			for(j = 1; j < w-1; j++)
			{
				if(s[i][j] == 'X')
				{
					map[a+i][a+j] = 1;
					x = a+j;
					y = a+i;
				}
				else
					map[a+i][a+j] = 0;
			}
		}

		map[y][a-(x-a-1)] = 1;
		map[a+h-1 + a+h-2-y][x] = 1;
		map[a+h-1 + a+h-2-y][a-(x-a-1)] = 1;

		W = (w-2)*2;
		H = (h-2)*2;
		start = a+1-(w-2);


		/*for(i = a+1; i < a+1+H; i++)
		{
			for(j = a+1-W/2; j < a+1+W/2; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}////////*/

		for(q = 1; ; q++)
		{
			if(start-W*q <= 0)
				break;
			for(i = a+1; i < a+1+H; i++)
				for(j = start; j < start+W; j++)
					map[i][j-W*q] = map[i][j];
		}
		for(q = 1; ; q++)
		{
			if(start+W*q >= 200)
				break;
			for(i = a+1; i < a+1+H; i++)
				for(j = start; j < start+W; j++)
					map[i][j+W*q] = map[i][j];
		}
		for(q = 1; ; q++)
		{
			if(a+1-H*q <= 0)
				break;
			for(i = a+1; i < a+1+H; i++)
				for(j = 0; j < N; j++)
					map[i-H*q][j] = map[i][j];
		}
		for(q = 1; ; q++)
		{
			if(a+1+H*q >= 200)
				break;
			for(i = a+1; i < a+1+H; i++)
				for(j = 0; j < N; j++)
					map[i+H*q][j] = map[i][j];
		}

		// process
		for(i = y-d; i <= y+d; i++)
		{
			for(j = x-d; j <= x+d; j++)
			{
				//printf("%d ", map[i][j]);
				if(i == y && j == x)
					continue;
				if(map[i][j] == 1)
				{
					t1 = abs(i-y);
					t2 = abs(j-x);
					srs();
				}
			}
			//printf("\n");
		}

		// output
		fprintf(fp2, "Case #%d: %d\n", ttest, res);
	}

	fcloseall();
	return 0;
}

void srs()
{
	int aa = x-j;
	int bb = y-i;
	int tt = max(t1, t2);
	int z;

	if(aa == 0)
	{
		if(bb < 0) bb = -1;
		else bb = 1;
	}
	else if(bb == 0)
	{
		if(aa < 0) aa = -1;
		else aa = 1;
	}
	else
	{
	for(z = 2; z <= tt; z++)
	{
		if(aa % z == 0 && bb % z == 0)
		{
			aa /= z;
			bb /= z;
			z = 1;
		}
	}
	}

	if(dxdy[aa+100][bb+100] == 0)
	{
		temp = sqrt((double(t1*t1+t2*t2)));
		if(temp <= (double)d)
		{
			res++;
			dxdy[aa+100][bb+100] = 1;
			//printf("- ");
		}
	}
}