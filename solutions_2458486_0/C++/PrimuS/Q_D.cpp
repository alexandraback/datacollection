#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE = 1 << 20;

struct actions
{
	int chests[20];
	int cur_size;
	bool calculated;
};

actions d[SIZE];

int keys_to_open[20];
int start_keys[202];
int cur_keys[SIZE][202];
vector<int> rewards[20];

int n;

void calc_keys()
{
	memset(cur_keys, 0, sizeof(cur_keys));

	int m = 1 << n;
	for (int i = 0; i < m; ++i)
	{
		memcpy(cur_keys[i], start_keys, sizeof(start_keys));

			for (int j = 0; j < n; ++j)
			{
				if ((1 << j) & i)
				{
					for (int u = 0; u < rewards[j].size(); ++u)
						cur_keys[i][rewards[j][u]]++;

					cur_keys[i][keys_to_open[j]]--;
				}
			}
	}
}

bool is_better(actions & a1, actions & a2)
{
	for (int i = 0; i < a1.cur_size; ++i)
	{
		if (a1.chests[i] < a2.chests[i])
			return true;

		if (a1.chests[i] > a2.chests[i])
			return false;
	}

	return false;
}

void f(int m)
{
	//printf("mask %x\n", m);
	if (m == 0)
		return;

	if (d[m].calculated == true)
		return;

	for (int i = 0; i < n; ++i)
	{
		if ((1 << i & m))
		{
			int mm = (~(1 << i)) & m;
			//memcpy(cur_keys, start_keys, sizeof(cur_keys));

			//for (int j = 0; j < n; ++j)
			//{
			//	if ((1 << j) & mm)
			//	{
			//		for (int u = 0; u < rewards[j].size(); ++u)
			//			cur_keys[rewards[j][u]]++;

			//		cur_keys[keys_to_open[j]]--;
			//	}
			//}

			if (cur_keys[mm][keys_to_open[i]] > 0)
			{

				/*if (m == 3)
				{
				printf("trying to come from mask %x\n", mm);

					for (int p = 0; p < d[m].cur_size; ++p)
						printf("%d ", d[m].chests[p]);
					printf("\n");
				}*/
				
				f(mm);
				if (mm == 0)
				{
					d[m].chests[0] = i;
					d[m].cur_size = 1;
				}
				else if (d[mm].cur_size > 0)
				{
					actions ttt = d[mm];
					ttt.chests[ttt.cur_size] = i;
					ttt.cur_size++;

					if (d[m].cur_size == 0)
					{
						d[m] = ttt;
					}
					else
					{
						if (is_better(ttt, d[m]))
							d[m] = ttt;
					}
				}
				//if (m == 3)
				//{
				//	for (int p = 0; p < d[m].cur_size; ++p)
				//		printf("%d ", d[m].chests[p]);
				//	printf("\n");
				//}
			}

		}
	}
				//if (m == 3)
				//{
				//	for (int p = 0; p < d[m].cur_size; ++p)
				//		printf("%d ", d[m].chests[p]);
				//	printf("\n");
				//}
	//printf("finish mask %x\n", m);
	d[m].calculated = true;
}

int main()
{
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-result.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		int k;

		memset(d, 0, sizeof(d));
		memset(keys_to_open, 0, sizeof(keys_to_open));
		memset(start_keys, 0, sizeof(start_keys));
		for (int i = 0; i < 20; ++i)
			rewards[i].clear();

		scanf("%d%d", &k, &n);

		for (int i = 0; i < k; ++i)
		{
			int a;
			scanf("%d", &a);
			start_keys[a]++;
		}

		for (int i = 0; i < n; ++i)
		{
			int kk;
			scanf("%d%d", &keys_to_open[i], &kk);
			rewards[i].reserve(kk);
			for (int j = 0; j < kk; ++j)
			{
				int y;
				scanf("%d", &y);
				rewards[i].push_back(y);
			}
		}

		calc_keys();
		int m = (1 << n) - 1;
		f(m);

		printf("Case #%d: ", t + 1);

		if (d[m].cur_size == 0)
			printf("IMPOSSIBLE");
		else
		{
			for (int i = 0; i < n; ++i)
				printf("%d ", d[m].chests[i] + 1);
		}

		printf("\n");
		fflush(stdout);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}