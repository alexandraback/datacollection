#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string car[101];

typedef long long ll;
const ll Mod = ll (1e9) + 7;

int whole[30], occ[30];
bool g[30][30], vis[30], gg[30], ggg[30], fail;

int cnt(string s) {
	int ret = 1; 
	for (int i = 1; i < s.size(); ++ i)
		if (s[i] != s[i - 1]) ret ++;  
	return ret; 
}
void dfs(int x) {
	bool one = false; 
	vis[x] = true;
	for (int i = 0; i < 26; ++ i)
		if (g[x][i]) {
			if (vis[i]) {fail = true; return; }
			else if (one) {fail = true; return; }
			else one = true, dfs(i); 
		}
}

bool no(int x) {
	for (int i = 0; i < 26; ++ i)
		if (g[i][x]) return false;
	return true; 
}
ll fac[200];

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	fac[0] = 1ll;
	for (ll i = 1; i < 200; ++ i)
		fac[i] = fac[i - 1] * i % Mod;

	int _; cin >> _;
	for (int __ = 1; __ <= _; ++ __) {
		printf("Case #%d: ", __);
		int n; cin >> n;

		memset(whole, 0, sizeof whole); 
		memset(g, 0, sizeof g); 
		memset(occ, 0, sizeof occ); 
		memset(vis, 0, sizeof vis);
		memset(gg, 0, sizeof gg);
		memset(ggg, 0, sizeof ggg); 

		fail = false;

		long long ans = 1ll, way = 0;

		for (int i = 0; i < n; ++ i) {
			cin >> car[i]; 
			int Cnt = cnt(car[i]); 
			if (Cnt == 1) ++ whole[car[i][0] - 'a'], occ[car[i][0] - 'a'] = 1; 
			else {
				int x = car[i][0] - 'a';
				occ[x] = 1; 
				int pre = x; 
				for (int j = 1; j < car[i].size(); ++ j)
					if (car[i][j] - 'a' != pre) {
						int z = car[i][j] - 'a'; 
						if (g[pre][z]) {fail = true; break; } 
						if (gg[pre] || ggg[z]) {fail = true; break;}
						gg[pre] = ggg[z] = 1; 
						occ[z] = 1, g[pre][z] = 1, pre = z; 
					}
					
			}
		}

		for (int i = 0; i < 26; ++ i)
			ans = ans * fac[whole[i]] % Mod;

		for (int i = 0; i < 26; ++ i)
			if (occ[i] && ! vis[i] && no(i)) {
				dfs(i); 
				if (fail) break; 
				++ way; 
			} 


		ans = ans * fac[way] % Mod; 

		if (! fail && way) printf("%lld\n", ans); 
		else printf("0\n"); 

	}	

	return 0; 
}