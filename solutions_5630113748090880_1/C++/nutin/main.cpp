#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	freopen("B-large.in", "r", stdin);
//	ofstream fB-large.inout("out.txt");
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		int freq[2501];
		for (int j = 0; j <= 2500; ++j)
		{
			freq[j] = 0;
		}
		for(int j = 0; j < (2 * N - 1) * N; ++j)
		{
			int t;
			cin >> t;
			++freq[t];
		}
		vector <int> ans;
		for (int j = 0; j <= 2500; ++j)
		{
			if (freq[j] % 2 != 0)
			{
				ans.push_back(j);
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", i + 1);
		for (int j = 0; j < ans.size(); ++j)
		{
			cout << ans[j] << " ";
		}
		cout << endl;
	}
	return 0;
}
