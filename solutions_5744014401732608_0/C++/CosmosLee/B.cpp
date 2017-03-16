#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> maxNum(51, 0);

void init()
{
	long long int inc = 0;
	for (int i = 2; i < maxNum.size(); i++)
		maxNum[i] = 2 * maxNum[i - 1] + 1;
}

long long int count(const vector<vector<int>>& matrix)
{
	vector<long long int> res(matrix.size(), 0);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = i + 1; j < matrix.size(); j++)
		{
			if (matrix[i][j] == 1)
				res[j] += res[i] + 1;
		}
	}

	return res.back();
}

void buildMatrix(const int M, vector<vector<int>>& matrix, const int N)
{
	if (N < 0) return;

	for (int i = N; i < matrix.size(); i++)
	{
		matrix[N][i] = 0;
		auto resOff = count(matrix);
		if (resOff < M)
			matrix[N][i] = 1;

		cout << N << " " << i << " " << resOff << endl;
	}
	buildMatrix(M, matrix, N - 1);
}

void solve()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		long long int B, M;
		in >> B >> M;
		auto canBe = maxNum[B] >= M;
		out << "Case #" << t << ": " << (canBe ? "POSSIBLE" : "IMPOSSIBLE") << endl;
		if (canBe)
		{
			vector<vector<int>> matrix(B, vector<int>(B, 0));
			for (auto i = 0; i < matrix.size(); i++)
			{
				for (auto j = i + 1; j < matrix.size(); j++)
				{
					matrix[i][j] = 1;
				}
			}

			buildMatrix(M, matrix, B - 1);
			
			for (auto i = 0; i < matrix.size(); i++)
			{
				for (auto j = 0; j < matrix.size(); j++)
				{
					out << matrix[i][j];
				}
				out << endl;
			}
		}
	}

	in.close();
	out.close();
}

int main(int argc, char**argv)
{
	init();
	solve();
	return 0;
}