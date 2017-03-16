#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
char s[100][1000];
bool seen[26];
int c[26][26];
long long f[100];
int n;

#define MOD 1000000007

bool bad(int v)
{
	int start = v;
	while(1)
	{
		int next = -1;
		for(int i = 0; i < 26; i++) if (i != v && c[v][i]) { next = i; break;}
		if (next == -1) break;
		v = next;
		if (v == start) return true;
	}		
	return false;
}

int main()
{
	f[0] = 1;
	for(int i = 1; i < 100; i++) f[i] = (f[i - 1] * i) % MOD;

	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%s", s[i]);

		bool ok = true;
		for(int i = 0; i < n; i++)
		{
			fill(seen, seen + 26, false);
			seen[s[i][0] - 'a'] = true;
			for(int j = 1; s[i][j]; j++)
				if (s[i][j] != s[i][j - 1] && seen[s[i][j] - 'a'])
					ok = false;
				else
					seen[s[i][j] - 'a'] = true;

			for(int ch = 0; ch < 26; ch++)
			if (seen[ch])
			{
				if (s[i][0] == 'a' + ch) continue;
				if (s[i][strlen(s[i]) - 1] == 'a' + ch) continue;
				for(int j = 0; j < n; j++)
					if (j != i && strchr(s[j], 'a' + ch)) ok = false;
			}
		}

		if (!ok) { puts("0"); continue; }

		memset(c, 0, sizeof c);
		for(int i = 0; i < n; i++) c[s[i][0] - 'a'][s[i][strlen(s[i]) - 1] - 'a']++;

		long long res = 1;
		int cnt = 0;
		for(int i = 0; i < 26; i++)
		{
			res = (res * f[c[i][i]]) % MOD;

			int din = 0, dout = 0;
			for(int j = 0; j < 26; j++)
				if (i != j)
				{
					if (c[i][j] > 1 || c[j][i] > 1) ok = false;
					if (c[i][j]) dout++;
					if (c[j][i]) din++;
				}
			if (din > 1 || dout > 1) ok = false;
			if (din == 0 && (dout > 0 || c[i][i] > 0)) cnt++;
		}

		if (!ok) { puts("0"); continue; }

		for(int i = 0; i < 26; i++) if (bad(i)) ok = false;

		if (!ok) { puts("0"); continue; }

		res = (res * f[cnt]) % MOD;

		printf("%lld\n", res);
	}
	return 0;
}