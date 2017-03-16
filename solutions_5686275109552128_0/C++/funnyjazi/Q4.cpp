#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;


int main()
{
	int t = 0;
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	if (fin.good())
	{
		fin >> t;

		for (size_t i = 0; i < t; i++)
		{
			int D = 0;
			int Count, ans;
			Count = ans = 0;
			vector<int> P;
			fin >> D;
			for (size_t j = 0; j < D; j++)
			{
				int temp = 0;
				fin >> temp;
				P.push_back(temp);
			}
			ans = *max_element(P.begin(), P.end());
			Count = 2;
			while (Count < ans)
			{
				int sum = 0;
				for (size_t k = 0; k < P.size(); k++)
				{
					sum += (P[k] - 1) / Count;
				}
				ans = min(ans, sum+ Count);
				Count += 1;
			}

			fout << "Case #" << i + 1 << ": " << ans<< endl;

		}
		fin.close();
		fout.close();
	}

	return 0;
}