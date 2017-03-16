#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

vector<string> a;
int v[20];
int ans;
int n;

int check(string s) {
	int b[130] = {0};
	for (int i = 0; i < s.size(); i++) {
		if (b[s[i]] > 0 && b[s[i]] != i) {
			return 0;
		}
		b[s[i]] = i + 1;
	}
	return 1;
}

string gao(string s) {
	string ret;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			ret = ret + s[i];
		}
	}
	return ret;
}

void dfs(int m, string s) {
	if (m == n) {
		ans += check(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			v[i] = 1;
			dfs(m + 1, s + a[i]);
			v[i] = 0;
		}
	}
}

int main() {
	int T;
	freopen("x.txt", "r", stdin); freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &n);
		
		a.clear();
		memset(v, 0, sizeof(v));
		
		for (int i = 0; i < n; i++) {
			char s[200];
			scanf("%s", s);
			a.push_back(gao(s));
		}
		
		ans = 0;
		
		dfs(0, "");
		
		//printf("%d %d\n", cas, n);
		
		printf("Case #%d: %d\n", cas, ans);
	}
}
