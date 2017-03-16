#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <cstdlib>
#include <set>
#include <stdio.h>
using namespace std;

const int INF = 1001;

struct Data
{
	int value;
	int num;
	bool operator<(const Data& d) const
	{
		return value > d.value;
	}
};

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("data.in");
	outFile.open("data.out");

	
	int T;
	inFile >> T;

	for (int ca = 1; ca <= T; ++ca)
	{
		int n;
		inFile >> n;
		
		unordered_map<int, int> mp;
		int maxV = -1;
		for (int i = 0; i < n; ++i)
		{
			int p;
			inFile >> p;
			maxV = max(maxV, p);

			auto iter = mp.find(p);
			if (iter == mp.end())
			{
				mp[p] = 1;
			}
			else
			{
				iter->second++;
			}
		}
		
		vector<Data> data(mp.size());
		int id = 0;
		for (auto &x : mp)
		{
			data[id].value = x.first;
			data[id].num = x.second;
			id++;
		}
		sort(data.begin(), data.end());
		
		int ans = maxV;

		
		for (int i = 1; i < maxV; ++i)
		{
			int t = i;
			for (int j = 0; j < data.size(); ++j)
			{
				if (data[j].value <= i)
					break;

				int sigleMove = data[j].value / i;
				if (data[j].value % i == 0)
					sigleMove--;

				t += data[j].num * sigleMove;
			}
			ans = min(ans, t);
		}

		outFile << "Case #" << ca << ": " << ans << endl;
		//cout << ans << endl;
	}


	inFile.close();
	outFile.close();

	return 0;
}
