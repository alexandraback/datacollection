#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 12;
const int MAXK = 12;

int R, N, M, K;
int a[MAXK], b[MAXN];
vector<vector<int> > c;

int totAdd;
void Gao(int now, int num, int last)
{
	if (num == 1)
	{
		vector<int> _b;
		for (int i = 0; i < now; i++)
			_b.push_back(b[i]);
		c.push_back(_b);
		totAdd++;
		return;
	}
	if (now == N)
		return;
	for (b[now] = last; b[now] <= M; b[now]++)
		if (num % b[now] == 0)
			Gao(now + 1, num / b[now], b[now]);
}

bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a.size() > b.size();
}

bool findAns;
int cnt[9];
int _cnt[9];
vector<int> _tot;
int ans[MAXN];

bool check(int now, int num)
{
	if (now == N)
		return num == 1;
	if (check(now + 1, num))	return true;
	if (num % b[now] == 0)
		if (check(now + 1, num / b[now]))	return true;
	return false;
}

void DFS(int now, int last)
{
	if (findAns)
		return;
	if (now == N)
	{
		bool flag = true;
		for (int i = 0; i < K && flag; i++)
			if (!check(0, a[i]))
				flag = false;
		if (flag)
		{
			for (int i = 0; i < N; i++)
				ans[i] = b[i];
			findAns = true;
		}
		return;
	}
	for (b[now] = last; b[now] <= M; b[now]++)
		DFS(now + 1, b[now]);
}

int totfail;

void solve()
{
	sort(c.begin(), c.end(), cmp);
	int tot = 0;
	for (int i = 2; i <= M; i++)
	{
		//		printf("%d ", cnt[i]);
		tot += cnt[i];
	}
	//	printf("\n");
	//	printf("%5d maxsize = %5d minsize = %5d N = %5d\n", (int)c.size(), (int)c[0].size(), (int)c[c.size() - 1].size(), N);
	_tot.push_back(tot);
//	if (tot < 2)
//	{
//		for (int i = 0; i < N; i++)
//			ans[i] = 2;
//		totfail++;
//	}
//	else
	{
		findAns = false;

		/*for (int i = 0; i < (int)c.size(); i++)
		{
			memset(_cnt, 0, sizeof(_cnt));
			for (int j = 0; j < (int)c[i].size(); j++)
				_cnt[c[i][j]]++;
			int totCnt = 0;
			for (int j = 2; j <= M; j++)
			{
				_cnt[j] = max(_cnt[j], cnt[j]);
				totCnt += _cnt[j];
			}
			if (totCnt > N)	continue;
			int bnow = 0;
			for (int j = 2; j <= M; j++)
				for (int k = 0; k < _cnt[j]; k++)
					b[bnow++] = j;
			DFS(bnow, 2);
			if (findAns)
				break;
		}*/
		int bnow = 0;
		for (int i = 2; i <= M; i++)
			for (int j = 0; j < cnt[i]; j++)
				b[bnow++] = i;
		DFS(bnow, 2);
		if (!findAns)
		{
			for (int i = 0; i < N; i++)
				ans[i] = 2;
			totfail++;
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d", ans[i]);
	printf("\n");
}

int main()
{
	int totCase;
	scanf("%d", &totCase);
	for (int cas = 1; cas <= totCase; cas++)
	{
		scanf("%d%d%d%d", &R, &N, &M, &K);
		printf("Case #%d:\n", cas);
		totfail = 0;
		for (int r = 0; r < R; r++)
		{
			c.clear();
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < K; i++)
			{
				scanf("%d", &a[i]);
				if (a[i] != 1)
				{
					totAdd = 0;
					Gao(0, a[i], 2);
					//5和7可以先预处理掉
					int cnt5 = 0, cnt7 = 0;
					int ta = a[i];
					while (a[i] % 5 == 0)
					{
						a[i] /= 5;
						cnt5++;
					}
					while (a[i] % 7 == 0)
					{
						a[i] /= 7;
						cnt7++;
					}
					cnt[5] = max(cnt[5], cnt5);
					cnt[7] = max(cnt[7], cnt7);
					a[i] = ta;
					//存在唯一分解方式
					if (totAdd == 1)
					{
						memset(_cnt, 0, sizeof(_cnt));
						for (int i = 0; i < (int)c[c.size() - 1].size(); i++)
							_cnt[c[c.size() - 1][i]]++;
						for (int i = 2; i <= M; i++)
							cnt[i] = max(cnt[i], _cnt[i]);
					}
				}
			}
			solve();
		}
//		printf("fail = %d\n", totfail);
//		sort(_tot.begin(), _tot.end());
//		printf("%d\n", _tot[1120]);
	}
	return 0;
}


