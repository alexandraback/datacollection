#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int solve(int R, int W)
{
	if(R==W)
	{
		return W;
	}
	if(R<=(2*W))
	{
		return W+1;
	}
	return 1+solve(R-W,W);
}

int main()
{
	FILE *in,*out;
	char line[1000];
	int T, t;
	int i, j;
	in = fopen("A.in","r");
	out = fopen("A.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		int R,C,W;
		fscanf(in,"%d %d %d ",&R, &C, &W);
//		fgets(line,999,in);//empty line
		fprintf(out, "Case #%d: %d\n",t, ((C/W)*(R-1))+solve(C,W));
	}
	fclose(in);
	fclose(out);
}
