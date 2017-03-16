#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
#include "string.h"
#include "math.h"

FILE *fin, *fout;

#define INPUT_FILE_NAME "B-large"
#define INPUT_FILE INPUT_FILE_NAME##".in"
#define OUTPUT_FILE INPUT_FILE_NAME##".out"

#define print(format,...) {fprintf(fout, format, __VA_ARGS__); printf(format, __VA_ARGS__);}

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define pow2(a) ((a)*(a))

template<class T>
inline void swap(T &a, T &b)
{
	T c;
	c=a;
	a=b;
	b=c;
}

void problem(int nCase);
void init();

void main(int argc, char **argv)
{
	int N,k;
	printf("%s\n", INPUT_FILE);
	fopen_s(&fin, INPUT_FILE, "rt");
	fopen_s(&fout, OUTPUT_FILE, "wt");
	fscanf_s(fin, "%d\n", &N);
	k=0;
	init();
	while(N--)
	{
		++k;
		print("Case #%d: ", k);
		problem(k);
		print("\n");
	}
	fclose(fin);
	fclose(fout);
}

void init()
{
}

typedef struct  
{
	int c,f;
	long double time;
	bool bBeen;
}SCell;

int H,N,M;
SCell cells[100][100];

bool canGo(int fromx, int fromy, int tox, int toy)
{
	if (tox<0 || toy<0 || tox>=N || toy>=M)
		return false;
	if (cells[tox][toy].c-cells[tox][toy].f<50)
		return false;
	if (cells[fromx][fromy].c<cells[tox][toy].f+50)
		return false;
	if (cells[fromx][fromy].f+50>cells[tox][toy].c)
		return false;
	return true;
}

void go(int fromx, int fromy, int tox, int toy, bool *bFull)
{
	long double neededTime=0,startTime;
	long double moveTime,endTime;
	int neededH = cells[tox][toy].c-50;
	neededH = min(neededH, cells[fromx][fromy].c-50);
	if (neededH<H)
		neededTime = (H-neededH)/10.0;
	startTime = max(neededTime,cells[fromx][fromy].time);
	if (H-10*startTime<cells[fromx][fromy].f+20)
		moveTime = 10;
	else
		moveTime = 1;
	if (neededH>=H && cells[fromx][fromy].time==0)
		moveTime = 0;
	endTime = startTime+moveTime;
	if (cells[tox][toy].bBeen == false || endTime<cells[tox][toy].time)
	{
		cells[tox][toy].bBeen = true;
		cells[tox][toy].time = endTime;
		*bFull = false;
	}
}

void problem(int nCase)
{
	int i,j;
	bool bFull = false;
	memset(cells, 0, sizeof(cells));
	fscanf_s(fin, "%d %d %d", &H, &N, &M);
	for (i=0;i<N;++i)
	{
		for (j=0;j<M;++j)
		{
			fscanf_s(fin, "%d", &cells[i][j].c);
		}
	}
	for (i=0;i<N;++i)
	{
		for (j=0;j<M;++j)
			fscanf_s(fin, "%d", &cells[i][j].f);
	}

	cells[0][0].bBeen = true;
	cells[0][0].time = 0;

	while (!bFull)
	{
		bFull = true;
		for (i=0;i<N;++i)
		{
			for (j=0;j<M;++j)
			{
				if (cells[i][j].bBeen)
				{
					if (canGo(i,j,i+1,j))
						go(i,j, i+1,j, &bFull);
					if (canGo(i,j,i-1,j))
						go(i,j, i-1,j, &bFull);
					if (canGo(i,j,i,j+1))
						go(i,j, i,j+1, &bFull);
					if (canGo(i,j,i,j-1))
						go(i,j, i,j-1, &bFull);
				}
			}
		}
	}
	print("%.6f", cells[N-1][M-1].time);
}