#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> e[1001];
bool inCircle[1001];
int deg[1001];
int treeFromMax[1001], treeMax[1001];
int maxVal, fromWhere;
bool v[1001];

void dfs(int cur, int from, int len)
{
	if(inCircle[cur]) return;

	if(len > maxVal)
	{
		maxVal = len;
		fromWhere = cur;
	}
	for(int i = 0; i < e[cur].size(); i++)
	{
		if(e[cur][i] == from) continue;
		dfs(e[cur][i], cur, len + 1);
	}
}

int getMax(int from)
{
	int ret = 0;
	for(int i = 0; i < e[from].size(); i++)
		if(!inCircle[e[from][i]])
			ret = max(ret, treeFromMax[e[from][i]]);
	return ret;
}

void solve()
{
	cin >> n;
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i <= n; i++)
		e[i].clear();
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		e[i].push_back(x);
		e[x].push_back(i);
		deg[i] ++;
		deg[x] ++;
	}
	memset(inCircle, true, sizeof(inCircle));
	while(true)
	{
		int which = 0;
		for(int i = 1; i <= n; i++)
			if((deg[i] <= 1) && inCircle[i])
			{
				which = i;
				break;
			}
		if(!which) break;
		inCircle[which] = false;
		for(int i = 0; i < e[which].size(); i++)
			deg[e[which][i]] --;
	}
	int ans = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++)
		if(!inCircle[i])
		{
			maxVal = -1;
			dfs(i, -1, 1);
			treeFromMax[i] = maxVal;
			maxVal = -1;
			dfs(fromWhere, -1, 1);
			treeMax[i] = maxVal;
		}
	memset(v, false, sizeof(v));

	for(int i = 1; i <= n; i++)
		if(inCircle[i] && !v[i])
		{
			vector <int> lis;
			int x = i;
			while(!v[x])
			{
				v[x] = true;
				lis.push_back(getMax(x));
				for(int j = 0; j < e[x].size(); j++)
					if(!v[e[x][j]] && inCircle[e[x][j]])
					{
						x = e[x][j];
						break;
					}
			}
			if(lis.size() == 2)
			{
				sum += 2 + lis[0] + lis[1];
			}
			ans = max(ans, (int)lis.size());
		}
	ans = max(ans, sum);
	cout << ans << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	int start = clock();
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int ret = MAIN();
	#ifdef LOCAL_TEST
		//cout << "[Finished in " << clock() - start << " ms]" << endl;
	#endif
	return ret;
}
