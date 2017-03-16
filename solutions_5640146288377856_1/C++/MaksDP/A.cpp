#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <queue>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
	FILE* inf=fopen("input.txt", "r");
	FILE* outf=fopen("output.txt", "w");

	int T;
	fscanf(inf, "%d", &T);

	for(int t=1; t<=T; t++)
	{
		int R, C, W;

		fscanf(inf, "%d%d%d", &R, &C, &W);

		int res=R*(C/W)+W;
		if(C%W==0) res--;

		fprintf(outf, "Case #%d: %d\n", t, res);
	}


	fclose(inf);
	fclose(outf);
	return 0;
}

