#include <cstdio>
#include <cstring>
int T, N, MOD = 1000000007;

char a[105][105];
int cntc[30];
int inside[30];
int outside[30];
int nt[30];
bool start[30];
bool ok;

bool v[30];

void dfs(int u) {
	v[u] = true;
	if (nt[u] == -1) return;
	if (v[nt[u]]) {
		ok = false;
		return;
	}
	dfs(nt[u]);
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		
		for (int i = 0;i < 26;++i) {
			cntc[i] = 0;
			inside[i] = 0;
			outside[i] = 0;
			nt[i] = -1;
			start[i] = true;
			ok = true;
		}
		
		for (int i=0;i<N;++i) {
			scanf("%s", a[i]);
			int j = 0;
			int l = strlen(a[i]);
			
			bool iii = false;
			
			while (a[i][j+1] && a[i][j] == a[i][j+1]) {
				++j;
			}
			outside[a[i][j] - 'a']++;
			++j;
			while (a[i][j]) {
				while (a[i][j+1] && a[i][j] == a[i][j+1]) {
					++j;
				}
				if (a[i][j+1]) {
					inside[a[i][j] - 'a'] ++;
					iii = true;
				} else {
					outside[a[i][j] - 'a'] ++;
				}
				++j;
			}
			
			
			if (a[i][0] == a[i][l-1]) {
				if (iii) ok = false;
				else cntc[a[i][0] - 'a'] ++;
			} else if (nt[ a[i][0] - 'a'] == -1) {
				nt[a[i][0] - 'a'] = a[i][l-1] - 'a';
				start[ a[i][l-1] - 'a'] = false;
			} else {
				ok = false;
			}
		}
		
		for (int i = 0; i < 26; ++i) {
			if (inside[i] >= 2) ok = false;
			if (inside[i] >= 1 && outside[i] >= 1) ok = false; 
		}
		
		long long ans = 1;
		for (int i=0;i<26;++i) {
			for (int j=1;ok && j<=cntc[i];++j) {
				ans = (ans * j) % MOD;
				// printf("aa %d %lld\n", i, ans);
			}
		}
		
		int f = 1;
		for (int i=0;i<26;++i) {
			// printf("%d %d %d %d\n", i, start[i], nt[i], cntc[i]);
			if (ok && start[i] && (nt[i] != -1|| cntc[i])) {
				memset(v, 0, sizeof(v));
				dfs(i);
				ans = (ans * (f++)) % MOD;
			}
		}
		
		printf("Case #%d: ", tc);
		if (ok && f > 1) printf("%lld\n", ans);
		else printf("0\n");
	}
	return 0;
}