#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#define _CRT_SECURE_NO_WARNINGS
using namespace std;


int solve( int r, int c, int w)
{
	int remain = 0;
	int ret = 0;

	remain = c / w-1;
	int other = max(c%w-1, 0);

	ret = r*c - remain*(w - 1) - other;
	return ret;
}

int sovle2(int r, int c, int w)
{
	int ret = 0;
	if ((c+1)%w==0)
	{
		ret = (c + 1) / w - 1;
	}
	else
	{
		ret = (c + 1) / w;
	}
	return ret;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	//freopen("A-small-attempt2.in", "r", stdin);
	//freopen("A-small-attempt3.in", "r", stdin);
	//freopen("sample.txt", "r", stdin);

	int N;
	cin >> N;

	FILE * p; p = fopen("result.txt", "w");
	
	for (int i = 0; i < N; ++i)
	{
		int r, c, w;
		cin >> r>>c>>w;
		int ret = solve(r, c, w);
		int ret2 = solve(r, c, w);
		int ret3 = ret2*(r - 1) + ret;
		fprintf(p, "Case #%d: %d\n", i + 1, ret3);
	}
	fclose(p);
	return 0;
}