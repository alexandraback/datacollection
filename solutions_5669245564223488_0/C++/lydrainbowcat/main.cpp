#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int fa[110], c[110], v[200], st[200], ed[200], sig[200], s[200];
string a[110];
int n;

int get(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		memset(v, 0xcf, sizeof(v));
		memset(st, 0, sizeof(st));
		memset(ed, 0, sizeof(ed));
		memset(sig, 0, sizeof(sig));
		memset(s, 0 , sizeof(s));
		bool no = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			int l = 0, r = a[i].size() - 1;
			while (l < a[i].size() && a[i][l] == a[i][0]) l++;
			while (r >= 0 && a[i][r] == a[i][a[i].size() - 1]) r--;
			if (l>r&&a[i][0] == a[i][a[i].size() - 1])
			{
				sig[a[i][0]]++; s[i] = 1;
				continue;
			}
			if (a[i][0] == a[i][a[i].size()-1]) no = 1;
			int tst = ++st[a[i][0]];
			int ted = ++ed[a[i][a[i].size() - 1]];
			if (tst > 1 || ted > 1) no = 1;
			for (int j = l,k; j <= r; j=k)
			{
				if (v[a[i][j]] < 0) v[a[i][j]] = 0; else no = 1;
				for (k = j; k <= r&&a[i][k] == a[i][j]; k++) v[a[i][j]]++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				if (v[a[i][j]] >= 0) v[a[i][j]]--;
			}
		}
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (v[i]>0xcfcfcfcf && v[i] < 0) no = 1;
		}
		printf("Case #%d: ", t);
		if (no)
		{
			puts("0");
			continue;
		}
		for (int i = 1; i <= n; i++) fa[i] = i, c[i] = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (s[i] && s[j] && a[i][0] == a[j][0])
				{
					fa[get(i)] = get(j);
				}
				if (s[i] || s[j]) continue;
				if (a[i][0] == a[j][a[j].size() - 1])
				{
					if (get(j) == get(i)) no = 1;
					fa[get(j)] = get(i);
				}
				if (a[i][a[i].size() - 1] == a[j][0])
				{
					if (get(j) == get(i)) no = 1;
					fa[get(j)] = get(i);
				}
			}
		}
		if (no)
		{
			puts("0");
			continue;
		}
		int cnt = 0, mod = 1000000007;
		long long ans = 1;
		int jc[110] = { 1 };
		for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i;
		memset(v, 0 , sizeof(v));
		for (int i = 1; i <= n; i++)
		{
			if (s[i] && get(i) == i && !st[a[i][0]] && !ed[a[i][0]])
			{
				ans = ans * jc[sig[a[i][0]]] % mod;
				cnt++;
			}
			if (s[i]) continue;
			if (!v[a[i][0]])
			{
				v[a[i][0]] = 1;
				c[get(i)] = c[get(i)] * jc[sig[a[i][0]]] % mod;
			}
			if (!v[a[i][a[i].size() - 1]])
			{
				v[a[i][a[i].size() - 1]] = 1;
				c[get(i)] = c[get(i)] * jc[sig[a[i][a[i].size() - 1]]] % mod;
			}
			if (get(i) == i) cnt++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (s[i]) continue;
			if (get(i) == i) ans = ans*c[i] % mod;
		}
		ans = ans * jc[cnt] % mod;
		cout << ans << endl;
	}
}
