#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int main()
{
	int T;
	fin >> T;
	int count[10000];
	vector<int> ans;	
	for (int ca = 1; ca <= T; ca++)
	{
		fout << "Case #" << ca << ":";
		memset(count, 0, sizeof(count));
		ans.clear();
		int n;
		fin >> n;
		for (int i = 0; i < 2 * n - 1; i++)
			for (int j = 0; j < n; j++)
			{
				int a;
				fin >> a;
				count[a]++;
			}

		for (int i = 0; i < 10000; i++)
		{
			if (count[i] % 2 == 1) ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			fout << " " << ans[i];
		fout << endl;
	}
	return 0;
}