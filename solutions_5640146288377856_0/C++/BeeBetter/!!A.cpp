#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	//FILE *in = fopen("input.txt", "r");
	FILE *in = fopen("A-small-attempt0.in", "r");
	FILE *out = fopen("output.txt", "w");
	int t;
    fscanf(in, "%d", &t);
  	for (int q=1;q<=t; q++) 
	{
		int n, c, w, res=0;
		fscanf(in, "%d %d %d", &n, &c, &w);
			int part=(c/w);
			if (c%w==0) res=n*part+w-1;
			else
			res=n*part+w;//one time miss
		fprintf(out, "Case #%d: %d\n", q, res);
  	}
	fclose(in);
    fclose(out);
return(0);
}
