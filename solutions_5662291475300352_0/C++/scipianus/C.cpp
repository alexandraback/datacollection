#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define EPS 0.000001
using namespace std;
int T, n, D, H, M, sol, start[2], viteza[2];
double t1, t2, sstart[2];

int main()
{
	int i, j;
	ifstream fin("C.in");
	ofstream fout("C.out");
	fin >> T;
	for(int t = 1; t <= T; ++t)
	{
		sol = 1;
		j = 0;
		fin >> n;
		for(i = 1; i <= n; ++i)
		{
			fin >> D >> H >> M;
			start[j] = D;
			viteza[j] = M;
			j++;
			if(H == 2)
			{
				start[j] = D;
				viteza[j] = M + 1;
				j++;
			}
		}
		if(j == 1 || viteza[0] == viteza[1])
		{
			fout << "Case #" << t << ": 0\n";
			continue;
		}
		if(start[0] > start[1])
		{
			swap(start[0], start[1]);
			swap(viteza[0], viteza[1]);
		}
		if(start[0] == start[1] && viteza[0] < viteza[1])
			swap(viteza[0], viteza[1]);
		t1 = (1.0 * (360.0 - 1.0 * start[0]) * (1.0 * viteza[0])) / 360.0;
		t2 = (1.0 * (360.0 - 1.0 * start[1]) * (1.0 * viteza[1])) / 360.0;
		if(fabs(t1 - t2) <= EPS)
		{
			fout << "Case #" << t << ": 0\n";
			continue;
		}
		if(t2 - t1 > EPS)
		{
			sstart[0] = 0.0;
			sstart[1] = 1.0 * start[1] + ((t1 * 360.0) / (1.0 * viteza[1]));
			t1 = (1.0 * (360.0 - sstart[0]) * (1.0 * viteza[0])) / 360.0;
			t2 = (1.0 * (360.0 - sstart[1]) * (1.0 * viteza[1])) / 360.0;
			if(fabs(t1 - t2) <= EPS)
			{
				fout << "Case #" << t << ": 1\n";
				continue;
			}
			if(t2 - t1 > EPS)
				sol = 1;
			else
				sol = 0;
		}
		else
		{
			sstart[0] = 1.0 * start[0] + ((t2 * 360.0) / (1.0 * viteza[0]));
			sstart[1] = 0.0;
			t1 = (1.0 * (360.0 - sstart[0]) * (1.0 * viteza[0])) / 360.0;
			t2 = (1.0 * (360.0 - sstart[1]) * (1.0 * viteza[1])) / 360.0;
			if(fabs(t1 - t2) <= EPS)
			{
				fout << "Case #" << t << ": 1\n";
				continue;
			}
			if(t2 - t1 > EPS)
				sol = 0;
			else
				sol = 1;
		}
		fout << "Case #" << t << ": " << sol << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
