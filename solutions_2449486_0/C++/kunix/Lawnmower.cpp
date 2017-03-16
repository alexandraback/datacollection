#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
using namespace std;
typedef unsigned uint;

uint X, Y;
vector<uint> lawn;
vector<uint> Xcut, Ycut;

uint get(int i, int j)
{
	if(0<=i && i<X && 0<=j && j<Y)
		return lawn[i*Y+j];
	throw "get(): invalid coordinates";
}
void set(int i, int j, uint c)
{
	if(0<=i && i<X && 0<=j && j<Y)
	{
		lawn[i*Y+j] = c;
		return;
	}
	throw "set(): invalid coordinates";
}
string solve()
{
	uint x, y, m;
	for(x=0; x<X; x++)
	{
		m = 0;
		for(y=0; y<Y; y++)
			m = max(m, get(x, y));
		Xcut[x] = m;
	}
	for(y=0; y<Y; y++)
	{
		m = 0;
		for(x=0; x<X; x++)
			m = max(m, get(x, y));
		Ycut[y] = m;
	}
	for(x=0; x<X; x++)
	{
		for(y=0; y<Y; y++)
		{
			if(get(x,y) != min(Xcut[x], Ycut[y])) return "NO";
		}
	}
	return "YES";
}
int _tmain(int argc, _TCHAR* argv[])
{
	uint cTask, t, i, j, val;
	string ret;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(t=1; t<=cTask; t++)
	{
		fscanf(fin, "%u %u", &X, &Y);
		lawn.resize(X*Y);
		Xcut.resize(X);
		Ycut.resize(Y);
		for(i=0; i<X; i++)
		{
			for(j=0; j<Y; j++)
			{
				fscanf(fin, "%u", &val);
				set(i, j, val);
			}
		}

		ret = solve();

		fprintf(fout, "Case #%u: %s\n", t, ret.c_str());
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
	return 0;
}