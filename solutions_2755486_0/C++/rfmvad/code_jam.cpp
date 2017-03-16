#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void func(ifstream& in, ofstream& out)
{
	long long N, di[1000], ni[1000], wi[1000], ei[1000], si[1000], ddi[1000], dpi[1000], dsi[1000];
	in >> N;
	for (int i = 0; i < N; i++)
		in >> di[i] >> ni[i] >> wi[i] >> ei[i] >> si[i] >> ddi[i] >> dpi[i] >> dsi[i];

	long long res = 0;
	long long wall[1000];
	long long new_wall[1000];
	memset(wall, 0, sizeof(wall));
	memset(new_wall, 0, sizeof(new_wall));
	while (true)
	{
		long long min_d = INT_MAX;
		for (int i = 0; i < N; i++)
			if (ni[i] > 0)
				min_d = min(min_d, di[i]);

		if (min_d == INT_MAX)
			break;

		for (int i = 0; i < N; i++)
			if (ni[i] > 0 && di[i] == min_d)
			{
				bool succ = false;
				for (long long j = wi[i] + 500; j < ei[i] + 500; j++)
					if (wall[j] < si[i])
					{
						succ = true;
						new_wall[j] = max(new_wall[j], si[i]);
					}
				if (succ)
					res++;

				di[i] += ddi[i];
				ni[i]--;
				wi[i] += dpi[i];
				ei[i] += dpi[i];
				si[i] += dsi[i];
			}

		memcpy(wall, new_wall, sizeof(wall));
	}

	out << res << endl;
}

int main()
{
	ifstream in;
	in.open("D:\\code_jam_in.txt");

	ofstream out;
	out.open ("D:\\code_jam_out.txt");
	out << fixed << showpoint << setprecision(7);

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		//cout << "Case #" << t << endl;
		out << "Case #" << t << ": ";
		func(in, out);
	}

	in.close();
	out.close();
	
	return 0;
}