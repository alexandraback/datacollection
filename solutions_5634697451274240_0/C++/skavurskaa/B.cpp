#include <bits/stdc++.h>
using namespace std;

map<string,long long> vis;
long long bfs(string &s)
{
	queue<string> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty())
	{
		s = q.front(); q.pop();
		//cout << s << vis[s] << endl;		
		int flag = 1;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '-')
			{
				flag = 0;
				break;
			}
		if (flag) return vis[s] - 1;

		for (int i = 1; i <= s.size(); i++)
		{
			string aux;
			aux.append(s,0,i);
			reverse(aux.begin(),aux.end());
			aux.append(s,i,999);
			for (int j = 0; j < i; j++)
			{
				if (aux[j] == '+') aux[j] = '-';
				else aux[j] = '+';
			}
			if (!vis[aux])
			{
				vis[aux] = vis[s] + 1;
				q.push(aux);
			}
		}
	}
	return 42;
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vis.clear();
		string s; cin >> s;
		printf("Case #%d: %lld\n", t, bfs(s));
	}
}
