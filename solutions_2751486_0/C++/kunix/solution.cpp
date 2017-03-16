#include <tchar.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned uint;
typedef unsigned __int64 uint64;

const int maxcnt = 1000010;
uint64 nval[maxcnt];
uint64 crun[maxcnt];
uint64 csub[maxcnt];
char str[maxcnt];
int len, n;

bool is_vowel(char c)
{
	return strchr("aeiou", c)!=0;
}

int solve()
{
	memset(nval, 0, sizeof(nval));
	memset(crun, 0, sizeof(crun));
	memset(csub, 0, sizeof(csub));
	for(int i=1; i<=len; i++)
	{
		crun[i] = is_vowel(str[i-1]) ? 0 : (crun[i-1]+1);
		if(crun[i]>=n)
			csub[i] = 1+i-n;
		else
			csub[i] = csub[i-1];
		nval[i] = nval[i-1] + csub[i];
	}
	return nval[len];
}

int _tmain(int argc, _TCHAR* argv[])
{
	uint cTask, iTask;
	uint ret, ret1;

	FILE* fin  = fopen("task.in", "rt");
	FILE* fout = fopen("task.out", "wt");

	fscanf(fin, "%u", &cTask);
	for(iTask=1; iTask<=cTask; iTask++)
	{
		fscanf(fin, "%s %d", str, &n);
		len = strlen(str);
		ret = solve();
		fprintf(fout, "Case #%u: %d\n", iTask, ret);
	}
	fclose(fin);
	fclose(fout);
	printf("done\n");
	getch();
}
