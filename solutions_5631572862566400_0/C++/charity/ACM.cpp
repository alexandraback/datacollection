#include <bits/stdc++.h>
using namespace std;
#define maxn 1001

int f[maxn], ord[maxn];
vector<int> rf[maxn];
vector<pair<int, int> > v;
bool vit[maxn];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t, tn = 1, n, i, k, ret, cnt, h;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			rf[i].clear();
		for(i = 1; i <= n; i++)
		{
			scanf("%d", f + i);
			rf[f[i]].push_back(i);
		}
		v.clear();
		memset(vit, false, sizeof(vit));
		for(i = 1; i <= n; i++)
			if(!vit[i] && f[f[i]] == i)
			{
				v.push_back(make_pair(i, f[i]));
				vit[i] = vit[f[i]] = true;
			}
		ret = 0;		
		for(i = 1; i <= n; i++)
		{
			k = i;
			memset(ord, 0, sizeof(ord));
			cnt = 1;
			ord[k] = cnt++;
			while(ord[f[k]] == 0)
			{
				ord[f[k]] = cnt++;
				k = f[k];
			}
			ret = max(ret, cnt - ord[f[k]]);
		}
		h = 0;
		for(i = 0; i < v.size(); i++)
		{
			queue<pair<int, int> > qe;
			qe.push(make_pair(v[i].first, 1));
			while(!qe.empty())
			{
				pair<int, int> p = qe.front(); qe.pop();
				cnt = p.second;
				for(k = 0; k < rf[p.first].size(); k++)
				{
					int u = rf[p.first][k];
					if(!vit[u])
					{
						vit[u] = true;
						qe.push(make_pair(u, p.second + 1));
					}
				}
			}
			h += cnt;
			qe.push(make_pair(v[i].second, 1));
			while(!qe.empty())
			{
				pair<int, int> p = qe.front(); qe.pop();
				cnt = p.second;
				for(k = 0; k < rf[p.first].size(); k++)
				{
					int u = rf[p.first][k];
					if(!vit[u])
					{
						vit[u] = true;
						qe.push(make_pair(u, p.second + 1));
					}
				}
			}
			h += cnt;
		}
		ret = max(ret, h);
		printf("Case #%d: %d\n", tn++, ret);
	}
	return 0;
}
