#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MOD 1000000007
#define MAXN 15

int T, tt = 0;
int n;
string s[MAXN];
int ans;
bool b[MAXN];
bool v[26];

void dfs(int x, char lc)
{
	if (x >= n){
		ans ++;
		return;
		}
	bool nv[26];
	memcpy(nv, v, sizeof(nv));
	for (int i = 0; i < n; ++i)
		if (!b[i]){
			b[i] = true;
			int len = s[i].size();
			bool can = true;
			for (int j = 0; j < len; ++j)
				if (!v[s[i][j]-97]) v[s[i][j]-97] = true;
					else if (j == 0){ if (lc != s[i][j]) can = false; }
							else if (s[i][j] != s[i][j-1]) can = false;
			if (can) dfs(x+1, s[i][len-1]);
			memcpy(v, nv, sizeof(nv));
			b[i] =false;
			}
	}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) cin >> s[i];
		ans = 0;
		memset(b, false, sizeof(b));
		memset(v, false, sizeof(v));
		dfs(0, ' ');
		printf("Case #%d: ", (++tt));
		printf("%d\n", ans);
		}
	return 0;
	}
