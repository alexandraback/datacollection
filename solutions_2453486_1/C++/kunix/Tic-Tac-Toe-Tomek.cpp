#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>
using namespace std;
typedef unsigned uint;

vector<char> board(16);

char get(int i, int j)
{
	if(0<=i && i<=3 && 0<=j && j<=3)
		return board[i*4+j];
	throw "get(): invalid coordinates";
}
void set(int i, int j, char c)
{
	if(0<=i && i<=3 && 0<=j && j<=3)
	{
		board[i*4+j] = c;
		return;
	}
	throw "set(): invalid coordinates";
}
char checkwin(int i0, int j0, int di, int dj)
{
	char c, q;
	for(int i=i0, j=j0, k=0; k<4; k++, i+=di, j+=dj)
	{
		c = get(i, j);
		if(c == '.') return 0;
		if(c != 'T') break;
	}
	if(c=='T') return 0;
	for(int i=i0, j=j0, k=0; k<4; k++, i+=di, j+=dj)
	{
		q = get(i, j);
		if(q!=c && q!='T') return 0;
	}
	return c;
}
string solve()
{
	struct CHK
	{
		int i; int j; int di; int dj;
	} chk[] = {
		{0, 0, 0, 1}, {1, 0, 0, 1}, {2, 0, 0, 1}, {3, 0, 0, 1},
		{0, 0, 1, 0}, {0, 1, 1, 0}, {0, 2, 1, 0}, {0, 3, 1, 0}, 
		{0, 0, 1, 1}, {3, 0, -1, 1}, 
	};
	for(int t=0; t<10; t++)
	{
		char c = checkwin(chk[t].i, chk[t].j, chk[t].di, chk[t].dj);
		if(c != 0)
			return string(1, toupper(c)) + string(" won");
	}
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(get(i,j)=='.')
				return "Game has not completed";
	return "Draw";
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint cTask, t, i, j;
	char line[256];
	string ret;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(t=1; t<=cTask; t++)
	{
		for(i=0; i<4; i++)
		{
			fscanf(fin, "%4s\n", line);
			for(j=0; j<4; j++)
			{
				set(i, j, toupper(line[j]));
			}
		}
		fscanf(fin, "\n");

		ret = solve();

		fprintf(fout, "Case #%u: %s\n", t, ret.c_str());
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
	return 0;
}

