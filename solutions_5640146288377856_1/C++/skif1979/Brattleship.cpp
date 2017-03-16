
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int calc(int R, int C, int W)
{
	if (W == 1)
		return R * C;

	int parts = C / W;

	int find_the_row = (R - 1) * parts;

	if (W == C)
		return find_the_row + W;

	int res = parts + W - 1;
	if ((C - W * (parts - 1)) > W)
		res++;

	return find_the_row + res;
}

int main()
{
	FILE *in;
	if (fopen_s(&in, "A-large.in", "r+") != 0)
		printf("The in file was not opened\n");

	fstream out("A-large.out", ios::out);
	if (out.bad())
		printf("The out file was not opened\n");

	int T;
	fscanf_s(in, "%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int R, C, W;
		fscanf_s(in, "%d %d %d", &R, &C, &W);

		int res = calc(R, C, W);

		cout << "Case #" << tc << ": " << res << " R, C, W = " << R << " " << C << " " << W << endl;
		out << "Case #" << tc << ": " << res << endl;
	}

	_ASSERT(calc(1, 4, 2) == 3);
	_ASSERT(calc(1, 7, 7) == 7);
	_ASSERT(calc(2, 5, 1) == 10);
	_ASSERT(calc(1, 9, 3) == 5);
	_ASSERT(calc(1, 10, 3) == 6);
	_ASSERT(calc(1, 11, 3) == 6);
	_ASSERT(calc(1, 9, 4) == 6);
	cout << "Unit tests are OK" << endl;

	out.close();
	fclose(in);
	getchar();
}