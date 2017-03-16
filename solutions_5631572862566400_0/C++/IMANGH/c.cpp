#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;

int nxt[N], in[N], num[N];
queue<int> q;
bool mark[N];


#define X first
#define Y second

int main()
{
	ios::sync_with_stdio(false);

	int __;
	cin >>  __;
	for (int _=0; _<__; _++)
	{
		memset(in, 0, sizeof in);
		memset(num, 0, sizeof num);
		memset(mark, 0, sizeof mark);
		cout << "Case #" << _+1 << ": ";
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
		{
			cin >> nxt[i];
			nxt[i]--;
			in[nxt[i]]++;
		}
		for (int i=0; i<n; i++)
			if (in[i] == 0)
			{
				q.push(i);
				mark[i] = 1;
			}
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			num[nxt[v]] = max(num[nxt[v]], num[v] + 1);
			in[nxt[v]]--;
			if (in[nxt[v]] == 0)
			{
				q.push(nxt[v]);
				mark[nxt[v]] = 1;
			}
		}
		int sum2 = 0;
		int mxc = 0;
		for (int i=0; i<n; i++)
			if (!mark[i])
			{
				int v = i;
				int path = 0;
				int cnt = 0;
				while (!mark[v])
				{
					cnt++;
					path += num[v];
					mark[v] = 1;
					v = nxt[v];
				}
				if (cnt == 2)
					sum2 += path + 2;
				mxc = max(mxc, cnt);
			}
		cout << max(mxc, sum2) << "\n";
	}

	return 0;
}
