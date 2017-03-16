#include "stdafx.h"
#include <vector>
#include <utility>

using namespace std;

int step[4001][4001];
int dir[4001][4001];
int go[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void search()
{
	vector<pair<int, int>> buf;

	buf.push_back(make_pair(0, 0));
	int start = 0;
	for (int i = 0; i < 4001; i++)
		for (int j = 0; j < 4001; j++)
		{
			step[i][j] = 0;
			dir[i][j] = 0;
		}
	step[2000][2000] = 1;
	dir[2000][2000] = -1;
	int done = 1;
	while (start != buf.size())
	{
		pair<int, int> cor = buf[start];
		int curStep = step[cor.first + 2000][cor.second + 2000];
		int x, y;
		x = cor.first;
		y = cor.second;
		for (int i = 0; i < 4; i++)
		{
			int newx = x + go[i][0] * curStep;
			int newy = y + go[i][1] * curStep;
			if (abs(newx) <= 2000 && abs(newy) <= 2000 && step[newx + 2000][newy + 2000] == 0)
			{
				step[newx + 2000][newy + 2000] = curStep + 1;
				dir[newx + 2000][newy + 2000] = i;
				buf.push_back(make_pair(newx, newy));
				if (abs(newx) <= 100 && abs(newy) <= 100)
				{
					done++;
				}
			}
		}
		if (done == 10000) break;
		start++;
	}
}

void print(int x, int y, FILE* out)
{
	if (x == 0 && y == 0) return;

	int d = dir[x + 2000][y + 2000];
	int s = step[x + 2000][y + 2000] - 1;
	int dx = go[d][0] * s;
	int dy = go[d][1] * s;
	print(x - dx, y - dy, out);
	
	switch (d)
	{
	case 0:
		fprintf(out, "E");
		break;
	case 1:
		fprintf(out, "W");
		break;
	case 2:
		fprintf(out, "S");
		break;
	case 3:
		fprintf(out, "N");
		break;
	}
}

int main()
{
	FILE* in = fopen("B-small-attempt1.in", "r");
	FILE* out = fopen("b.out.txt", "w");

	int t;
	fscanf(in, "%d", &t);

	
	for (int it = 1; it <= t; it++)
	{
		int x, y;
		fscanf(in, "%d %d", &x, &y);

		fprintf(out, "Case #%d: ", it);
		if (x < 0)
		{
			for (int i = 0; i < abs(x); i++)
			{
				fprintf(out, "EW");
			}
		}
		else if (x > 0)
		{
			for (int i = 0; i < x; i++)
			{
				fprintf(out, "WE");
			}
		}
		if (y < 0)
		{
			for (int i = 0; i < abs(y); i++)
			{
				fprintf(out, "NS");
			}
		}
		else if (y > 0)
		{
			for (int i = 0; i < y; i++)
			{
				fprintf(out, "SN");
			}
		}
		//print(x, y, out);
		fprintf(out, "\n");
	}

	return 0;
}