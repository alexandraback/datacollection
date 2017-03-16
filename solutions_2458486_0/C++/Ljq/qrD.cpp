#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

const int MAXN = 20;
const int MAXK = 45;

int K, n;
int kys[MAXK], skys[MAXK];
int chs[MAXN], chz[MAXN], chg[MAXN][MAXK];
int env[1<<MAXN], enu[1<<MAXN];
int ev[1<<MAXN][MAXN], eu[1<<MAXN][MAXN];
int f[1<<MAXN];
vector <int> ans;

void Dfs(int s)
{
	f[s] = 2;
	for (int i = 0; i < enu[s]; i ++)
	{
		int es = s - (1 << eu[s][i]);
		if (f[es] != 2)  Dfs(es);
	} 
}

bool Work()
{
	cin >> K >> n;
	memset(skys, 0, sizeof(skys));
	for (int i = 0, x; i < K; i ++)
	{
		cin >> x;  x --;
		skys[x] ++;
	}

	memset(chg, 0, sizeof(chg));
	for (int i = 0; i < n; i ++)
	{
		cin >> chs[i] >> chz[i];  chs[i] --;
		for (int j = 0; j < chz[i]; j ++)
		{
			cin >> chg[i][j];  chg[i][j] --;
		}
	}

	memset(f, 0xff, sizeof(f));
	f[0] = 1;
	int mst = 1 << n;
	memset(enu, 0, sizeof(enu));
	memset(env, 0, sizeof(env));
	for (int st = 0; st < mst; st++)  if (f[st] != -1)
	{
		memcpy(kys, skys, sizeof(kys));
		for (int i = 0; i < n; i++)  
			if ((1 << i) & st)
			{
				kys[chs[i]]--;
				for (int j = 0; j < chz[i]; j ++)
					kys[chg[i][j]]++;
			}
		for (int i = 0; i < n; i ++)
			if (!((1 << i) & st) && kys[chs[i]] > 0)
			{
				int ns = st | (1 << i);
				f[ns] = 1;
				ev[st][env[st]++] = i;
				eu[ns][enu[ns]++] = i;
			}
	}
	if (f[mst-1] == -1)
		return false;

	Dfs(mst - 1);
	
	ans.clear();
	int st = 0;
	while (st + 1 != mst)
	{
		for (int i = 0; i < env[st]; i ++)
		{
			int ns = st | (1 << ev[st][i]);
			if (f[ns] == 2)
			{
				ans.push_back(ev[st][i]);
				st = ns;
				break;
			}
		}
	}

	for (int i = 0; i < ans.size(); i ++)
		cout << " " << ans[i] + 1;

	return true;
}

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt ++)
	{
		cout << "Case #" << tt << ":";
		if (!Work())  cout << " IMPOSSIBLE";
		cout << endl;
	}

	return 0;
}