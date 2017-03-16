#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

int solve(int R, int C, int W)
{
	int ans = C / W * R;
	ans += (0 == C % W) ? (W - 1) : (W);
	return ans;
}

int main()
{
	FILE * infile = fopen("A-small-attempt0.in", "r");
	FILE * outfile = fopen("out.txt", "w");

	int T;
	fscanf(infile, "%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		int R, C, W;
		fscanf(infile, "%d %d %d", &R, &C, &W);
		int ans = solve(R, C, W);
		fprintf(outfile, "Case #%d: %d\n", i, ans);
	}

	fclose(infile);
	fclose(outfile);
	return 0;
}

