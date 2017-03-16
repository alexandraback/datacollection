#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int t, k;
int n, l, tt, a, b, kk;
int i, j, p, q;
int ans;


//string PROG = "A-Large";
string PROG = "B-small-attempt0";
FILE *fin, *fout;


int main()
{
	fin = fopen((PROG + ".in").c_str(), "r");
	fout = fopen((PROG + ".out").c_str(), "w");
	
	fscanf(fin, "%d", &t);
	for (k = 1; k <= t; k++)
	{
		fscanf(fin, "%d %d %d", &a, &b, &kk);
		ans = 0;
		for (i = 0; i < a; i++)
			for (j = 0; j < b; j++)
				if ((i & j) < kk)
					ans++;
		
		fprintf(fout, "Case #%d: %d\n", k, ans);
		
	}
	return 0;
}