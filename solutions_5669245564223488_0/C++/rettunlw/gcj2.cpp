#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const long long MOD = 1e9+7;
char s[111][111];
int g[26], t, l[111], used[26],visit[111], n , c[26];
long long ans, tl;

bool isall(int id, int ch){
	for (int i = 0; i < l[id]; i++)
		if (s[id][i] - 'a' != ch)
			return false;
	return true;
}


long long cal(int id){
	long long as = 1, ct = 0;
	for (int i = 0; i < n; i++)
		if (!visit[i] && isall(i, id)){
			visit[i] = 1;
			ct++;
			as = as * ct % MOD;
			used[id] = 1;
		}
	for (int i = 0; i < n; i++)
		if (!visit[i] && s[i][0] - 'a' == id){
			used[id] = 1;
			visit[i] = 1;
			for (int j = 0; j < l[i]; j++)
				if (s[i][j] - 'a' != id){
					id = s[i][j] - 'a';
					if (used[id]){
						return 0;
					}
					else{
						used[id] = 1;
					}
				}
			as = as * cal(id) % MOD;
			break;
		}
	return as % MOD;
}


int main(){
	freopen("B0.in","r",stdin);
	freopen("B0.out","w",stdout);
	scanf("%d", &t);
	for (int cs = 1; cs <= t; cs++){
		memset(g, 0, sizeof(g));
		memset(c, 0, sizeof(c));
		memset(used, 0, sizeof(used));
		memset(visit, 0, sizeof(visit));
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%s", s[i]);
			c[s[i][0] - 'a' ] = 1;
			l[i] = strlen(s[i]);
			if (s[i][0] != s[i][l[i] - 1])
				g[s[i][l[i] - 1] - 'a'] = 1;
		}
		ans = 1;
		tl = 0;
		for (int i = 0; i < 26; i++)
			if (!g[i]){
				ans *= cal(i);
				ans %= MOD;
			}
		for (int i = 0; i < n; i++)
			if (!visit[i]) 
				ans = 0;
		for (int i = 0; i < 26; i++)
			if (c[i] && !g[i])
				tl++;
		for (int i = 1; i <= tl; i++)
			ans = ans * i % MOD;
		printf("Case #%d: %lld\n", cs, ans);
	}
	return 0;
}
