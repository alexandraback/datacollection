#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <sstream> 
#include <set> 
#include <map> 
#include <queue> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <bitset> 
#include <unordered_map> 
#include <unordered_set> 

using namespace std;
typedef long long ll;



vector<int> v;

int cycle()
{
	int mx = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		int cnt = 0;
		int cur = i;
		vector<int> used(v.size(), false);
		while (!used[cur])
		{
			used[cur] = true;
			cur = v[cur];
			cnt++;
		}
		if (cur == i)
		{
			mx = max(cnt, mx);
		}
	}
	return mx;
}

int main(){
#ifdef _CONSOLE 
	freopen("C-small-attempt0 (1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	
	int test;
	cin >> test;
	
	for (int t = 1; t <= test; ++t)
	{
		int n;
		cin >> n;
		v.assign(n, 0);
		vector<vector<int> > gr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			v[i]--;
			gr[v[i]].push_back(i);
			
		}

		vector<int> bamb(n);
		for (int i = 0; i < n; ++i)
		{
			queue<int> q;
			q.push(i);
			vector<vector<int> > tmpgr(n);
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				for (int j = 0; j < gr[cur].size(); ++j)
				{
					int to = gr[cur][j];
					if (to == i)
						continue;
					if (v[cur] == to)
					{
						continue;
					}
					tmpgr[cur].push_back(to);
					tmpgr[to].push_back(cur);	
					q.push(to);
				}
			}
			vector<int> len(n, -1);
			len[i] = 0;
			q.push(i);
			int mxlen = 0;
			while (!q.empty())
			{
				int cur = q.front();
				mxlen = len[cur];
				q.pop();
				for (int i = 0; i < tmpgr[cur].size(); ++i)
				{
					int to = tmpgr[cur][i];
					if (len[to] == -1)
					{
						q.push(to);
						len[to] = len[cur] + 1;
					}
				}
			}
			bamb[i] = mxlen;
		}

		int ans = 0;
		vector<int> pars;
		for (int i = 0; i < n; ++i)
		{
			int next = v[i];
			if (v[next] == i)
			{
				pars.push_back(i);
				ans++;
			}
		}
		for (int i = 0; i < pars.size(); ++i)
		{
			int to = pars[i];
			ans += bamb[to];
		}
		ans = max(ans, cycle());

		cout << "Case #" << t << ": "<<ans<<"\n";

	}


	return 0;
}

