#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 100;
const int maxlen = 100;
const int MOD = 1000000007;

int n;
char word[maxn][maxlen + 1];

bool valid(const char s[])
{
	set<char> occ;
	for (int i = 0; s[i]; ++ i) {
		if (occ.count(s[i]) && s[i] != s[i - 1]) {
			return false;
		}
		occ.insert(s[i]);
	}
	return true;
}

int brute()
{
	int perm[n];
	for (int i = 0; i < n; ++ i) {
		perm[i] = i;
	}
	int answer = 0;
	do {
		string s = "";
		for (int i = 0; i < n; ++ i) {
			s += word[perm[i]];
		}
		if (valid(s.c_str())) {
			++ answer;
		}
	} while(next_permutation(perm, perm + n));
	return answer;
}

int solve()
{
	set<int> has[26];
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; word[i][j]; ++ j) {
			has[word[i][j] - 'a'].insert(i);
		}
	}
	int adj[26][26];
	memset(adj, 0, sizeof(adj));
	for (int i = 0; i < n; ++ i) {
		int len = strlen(word[i]);
		
		if (!valid(word[i])) {
			return 0;
		}
		
		int st = word[i][0] - 'a';
		int ed = word[i][len - 1] - 'a';
		
		++ adj[st][ed];
		
		int left = 0;
		while (left < len && word[i][left] == st + 'a') ++ left;
		int right = len - 1;
		while (right >= left && word[i][right] == ed + 'a') -- right;
		if (left <= right) {
			for (int j = left; j <= right; ++ j) {
				if (word[i][j] == st + 'a' || word[i][j] == ed + 'a') {
					return 0;
				} else {
					if (st == ed) {
						return 0;
					}
					if (has[word[i][j] - 'a'].size() != 1) {
						return 0;
					}
				}
			}
		}
	}
	
	long long answer = 1;
	int cnt = 0;
	for (int i = 0; i < 26; ++ i) {
		int in = 0, out = 0;
		for (int j = 1; j <= adj[i][i] ;++ j) {
			answer = answer * j % MOD;
		}
		for (int j = 0; j < 26; ++ j) {
			if (i != j) {
				in += adj[j][i];
				out += adj[i][j];
			}
		}
		if (in > 1 || out > 1) {
			return 0;
		}
		cnt += in == 1 && out == 0;
		
		if (in == 0 && out == 0 && adj[i][i] > 0) {
			cnt += 1;
		}
	}
	
//	printf("cnt = %d\n", cnt);
	
	bool d[26][26];
	memset(d, false, sizeof(d));
	for (int i = 0; i < 26; ++ i) {
		for (int j = 0; j < 26; ++ j) {
			if (i != j) {
				d[i][j] = adj[i][j] > 0;
			}
		}
	}
	for (int k = 0; k < 26; ++ k) {
		for (int i = 0; i < 26; ++ i) {
			for (int j = 0; j < 26; ++ j) {
				d[i][j] |= d[i][k] && d[k][j];
			}
		}
	}
	for (int i = 0; i < 26; ++ i) {
		for (int j = 0; j < 26; ++ j) {
			if (d[i][j] && d[j][i]) {
				return 0;
			}
		}
	}
	
	for (int i = 1; i <= cnt; ++ i) {
		answer = answer * i % MOD;
	}
	
	return answer;
	
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int no = 1; no <= T; ++ no) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%s", word[i]);
		}
		
		int answer = solve();
		//int answer = brute();
		printf("Case #%d: %d\n", no, answer);
	}
	return 0;
}

