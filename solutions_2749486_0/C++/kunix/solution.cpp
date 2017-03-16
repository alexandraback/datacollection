#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned uint;
typedef unsigned __int64 uint64;

#define BRK {__asm int 3}

int X, Y;

string solve()
{
	string LX = (X>=0) ? "WE" : "EW";
	string LY = (Y>=0) ? "SN" : "NS";
	if(X<0) X = -X;
	if(Y<0) Y = -Y;
	string ret;
	for(int i=0; i<X; i++)
		ret += LX;
	for(int i=0; i<Y; i++)
		ret += LY;
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint cTask, iTask;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(iTask=1; iTask<=cTask; iTask++)
	{
		fscanf(fin, "%d %d", &X, &Y);
		string ret = solve();
		fprintf(fout, "Case #%u: %s\n", iTask, ret.c_str());
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
}
