#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream in;
	in.open("D:\\code_jam_in.txt");
	ofstream out;
	out.open ("D:\\code_jam_out.txt");

	int T, N, M;

	in >> T;

	int f[100][100];
	bool maxel[100][100];

	for (int t = 1; t <= T; t++)
	{
		in >> N >> M;

		memset(maxel, 0, sizeof(maxel));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				in >> f[i][j];
		}

		for (int i = 0; i < N; i++)
		{
			int cur_max = 0;
			for (int j = 0; j < M; j++)
				cur_max = max(cur_max, f[i][j]);
			for (int j = 0; j < M; j++)
				maxel[i][j] |= f[i][j] == cur_max;
		}

		for (int j = 0; j < M; j++)
		{
			int cur_max = 0;
			for (int i = 0; i < N; i++)
				cur_max = max(cur_max, f[i][j]);
			for (int i = 0; i < N; i++)
				maxel[i][j] |= f[i][j] == cur_max;
		}

		string res = "YES";
		for (int i = 0; i < N && res == "YES"; i++)
			for (int j = 0; j < M; j++)
				if (!maxel[i][j])
					res = "NO";

		out << "Case #" << t << ": " << res << endl;
	}

	in.close();
	out.close();
	
	return 0;
}