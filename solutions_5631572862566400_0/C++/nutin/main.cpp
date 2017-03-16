#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool vis[1001];
int friends[1001];
int N;
int max_len = -1;

int path_len(int ver, int max_path)
{
	bool is_found = false;
	for (int i = 1; i <= N; ++i)
	{
		if (friends[i] == ver && !vis[i])
		{
			is_found = true;
			vis[i] = true;
			path_len(friends[i], max_path + 1);
			vis[i] = false;
		}
	}
	if (!is_found)
	{
		max_len = max(max_len, max_path);
	}
	return 0;
}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
//	ofstream fB-large.inout("out.txt");
	freopen("out1.txt","w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		for (int j = 1; j <= N; ++j)
		{
			int t;
			cin >> t;
			friends[j] = t;
		}
		int max_cir = -1;
		for (int j = 1; j <= N; ++j)
		{
			for (int k = 1; k <= N; ++k)
			{
				vis[k] = false;
			}
			int cur_count = 0;
			int cur_kid = j;
			bool find_ans = false;
			vis[j] = true;
			while(!find_ans)
			{
				if (vis[friends[cur_kid]])
				{
					find_ans = true;
				}
				else
				{
					++cur_count;
					cur_kid = friends[cur_kid];
					vis[cur_kid]  = true;
				}
			}
			if (friends[cur_kid] == j)
			{
				max_cir = max(max_cir, cur_count + 1);
			}
			else if (vis[friends[cur_kid]] && friends[friends[cur_kid]] == cur_kid)
			{
				max_len = 0;
				path_len(cur_kid, 0);
				max_cir = max(max_cir, cur_count + 1 + max_len);
//				cout << i + 1 << " " << j << " " << cur_kid << " " << max_len << endl;
			}
		}
		printf("Case #%d: %d\n", i + 1, max_cir);

	}
	return 0;
}
