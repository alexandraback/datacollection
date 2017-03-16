#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

#pragma comment(linker, "/STACK:260777216")
int pred[1100000];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int K, N;
		cin >> K >> N;
		int k0[21];
		for (int i = 0; i < 21; i++)
			k0[i] = 0;

		for (int i = 0; i < K; i++)
		{
			int tt; cin >> tt;
			k0[tt] ++;
		}

		int Ti[20], Ki[20];
		int cont[20][21];
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 21; j++)
				cont[i][j] = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> Ti[i] >> Ki[i];
			for (int j = 0; j < Ki[i]; j++)
			{
				int tt;
				cin >> tt;
				cont[i][tt]++;
			}
		}
		
		for (int i = 0; i < 1100000; i++)
			pred[i] = -1;

		queue<int> Q;
		Q.push(0);

		while (!Q.empty())
		{
			int v = Q.front();
			Q.pop();

			int curkey[21];
			for (int i = 0; i < 21; i++)
				curkey[i] = k0[i];
			for (int j = 0; j < N; j++)
			{
				if (v & (1 << j))
				{
					curkey[Ti[j]] --;
					for (int i = 0; i < 21; i++)
						curkey[i] += cont[j][i];
				}
			}

			for (int i = 0; i < N; i++)
			{
				int u = v;
				u = v | (1 << i);
				if (pred[u] != -1)
					continue;
				
				if (pred[u] == -1 && curkey[Ti[i]] > 0)
				{
					pred[u] = i;
					Q.push(u);
				}
			}
		}

		cout << "Case #" << t + 1 << ": ";

		if (pred[(1 << N) - 1] == -1)
			cout << "IMPOSSIBLE";
		else
		{
			vector<int> ans;
			int cur = (1 << N) - 1;
			while(pred[cur] != -1)
			{
				ans.push_back(pred[cur]);
				cur ^= (1 << pred[cur]);
			}

			for (int i = ans.size() - 1; i >= 0; i--)
				cout << ans[i] + 1 << " ";
		}
		
		cout << endl;
	}
}
































