
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void printArray(vector<int> &DD)
{
	for (auto i : DD)
		cout << i << " "; 
	cout << endl;
}

int calc(int C, int D, int V, vector<int> &DD)
{
	int D_added = 0;

	if (DD[0] != 1)
	{
		DD.emplace_back(1);
		D_added++;		
		sort(DD.begin(), DD.end());
		printArray(DD);   // DEBUG
	}
	
	if (V == 1)
		return D_added;

	int curD = 1;
	int nextD = 1 * C + 1;

	while (V >= nextD)
	{
		if (curD >= DD.size() || nextD < DD[curD])
		{
			DD.emplace_back(nextD);
			D_added++;
			sort(DD.begin(), DD.end());
			printArray(DD);   // DEBUG
		}
		
		nextD = 0;
		for (int i = 0; i <= curD; i++)
			nextD += DD[i] * C;
		nextD++;
		curD++;
	}

	return D_added;
}

int main()
{
	FILE *in;
	if (fopen_s(&in, "C-large.in", "r+") != 0)
		printf("The in file was not opened\n");

	fstream out("C-large.out", ios::out);
	if (out.bad())
		printf("The out file was not opened\n");

	int T;
	fscanf_s(in, "%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int C, D, V;
		vector<int> DD;

		fscanf_s(in, "%d %d %d", &C, &D, &V);

		int temp;
		for (int i = 0; i < D; i++)
		{
			fscanf_s(in, "%d ", &temp);
			DD.emplace_back(temp);
		}

		int res = calc(C, D, V, DD);

		cout << "Case #" << tc << ": " << res << " C, D, V = " << C << " " << D << " " << V << endl;
		out << "Case #" << tc << ": " << res << endl;
	}

	vector<int> AA(6);
	AA[0] = 1;
	AA[1] = 5;
	AA[2] = 10;
	AA[3] = 25;
	AA[4] = 50;
	AA[5] = 100;

	_ASSERT(calc(1, 6, 100, AA) == 3);
	cout << "Unit tests are OK" << endl;

	out.close();
	fclose(in);
	getchar();
}