#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <limits>
#include <set>

using namespace std;

string new_str;

map <int, int> cnt;
vector <int> ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cnt.clear();
		for (int i = 0; i < N * 2 - 1; i++)
		{
			for (int q = 0; q < N; q++)
			{
				int val;
				cin >> val;
				cnt[val]++;
			}
		}
		ans.clear();
		for (int i = 0; i <= 2500; i++)
		{
			if (cnt[i] % 2 == 1)
				ans.push_back(i);
		}
		sort(ans.begin(), ans.end());
		cout << "Case #" << i + 1 << ": ";
		for (int i = 0; i < N; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}

}