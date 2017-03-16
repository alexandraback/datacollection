#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

istream &in = ifstream("input.txt");
ostream &out = ofstream("output.txt");

int main()
{
	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		int N;
		in >> N;
		auto strList = vector<string>(N);
		auto compactList = vector<string>(N);
		for (int i = 0; i < N; i++) in >> strList[i];
		for (int i = 0; i < N; i++)
		{
			for (auto k = 0; k < strList[i].size(); k++)
				if (compactList[i].size() == 0 || compactList[i].back() != strList[i][k])
					compactList[i].push_back(strList[i][k]);
		}

		bool canBe = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (compactList[i] != compactList[j]) canBe = false;
			}
		}

		if (!canBe)
		{
			out << "Case #" << t << ": " << "Fegla Won" << endl;
			cout << "Case #" << t << ": " << "Fegla Won" << endl;
			continue;
		}

		// 각 위치별로 최소값 계산
		int cost = 0;
		auto strPos = vector<int>(N, 0);
		for (auto i = 0; i < compactList[0].size(); i++)
		{
			int minSize = 99999, maxSize = 0;
			auto sizeList = vector<int>(N, 0);
			for (auto k = 0; k < N; k++)
			{
				while (strPos[k] < strList[k].size() && strList[k][strPos[k]] == compactList[0][i])
				{
					strPos[k]++;
					sizeList[k]++;
				}

				minSize = (sizeList[k] < minSize) ? sizeList[k] : minSize;
				maxSize = (sizeList[k] > maxSize) ? sizeList[k] : maxSize;
			}

			int minCost = 99999;
			for (int op = minSize; op <= maxSize; op++)
			{
				int tempCost = 0;
				for (int k = 0; k < N; k++)
					tempCost += abs(sizeList[k] - op);
				minCost = (tempCost < minCost) ? tempCost : minCost;
			}

			cost += minCost;
		}
		
		out << "Case #" << t << ": " << cost << endl;
		cout << "Case #" << t << ": " << cost << endl;
	}
	return 0;
}