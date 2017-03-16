#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007LL

int l[26], r[26], f[26], x[26], lft[26], rght[26];
long long facs[101];
string s[101];
bool visited[26];

bool bfs(int u, int type) {
	//printf("BFSing with %d, %d\n", u, type);
	if(u == -1)
		return true;
	if(visited[u])
		return false;
	visited[u] = true;
	if(type == 0 && l[u] != 0 && r[u] != 0) {
		return (bfs(lft[u], 1) & bfs(rght[u], 2));
	}
	if(l[u] != 0 && (type == 1 || type == 0))
		return bfs(lft[u], 1);
	if(r[u] != 0 && (type == 2 || type == 0))
		return bfs(rght[u], 2);
	return true;
}

void fix(string s) {
	char lf = s[0], rt = s[s.length() - 1];
	int cnt = 0;
	for(int i = 0; i < s.length(); i ++)
		if(s[i] == lf)
			cnt ++;
	if(cnt == s.length()) {
		f[lf - 'a'] ++;
		return;
	}
	string tmp;
	for(int i = 0; i < s.length(); i ++) {
		if(tmp.length() == 0) {
			tmp.push_back(s[i]);
		}
		if(s[i] != tmp[tmp.length() - 1])
			tmp.push_back(s[i]);
	}
	l[tmp[0] - 'a'] ++;
	r[tmp[tmp.length() - 1] - 'a'] ++;
	for(int i = 1; i < tmp.length() - 1; i ++) {
		x[tmp[i] - 'a'] ++;
	}
	lft[lf - 'a'] = rt - 'a';
	rght[rt - 'a'] = lf - 'a';
}

int main() {
	facs[0] = 1;
	for(long long i = 1LL; i <= 100LL; i ++) {
		facs[i] = (facs[i - 1] * i) % MOD;
	}
	int T;
	scanf(" %d", &T);
	for(int z = 1; z <= T; z ++) {
		for(int i = 0; i < 26; i ++) {
			l[i] = r[i] = x[i] = f[i] = lft[i] = rght[i] = 0;
			visited[i] = false;
			lft[i] = -1;
			rght[i] = -1;
		}
		int n;
		scanf(" %d", &n);
		for(int i = 0; i < n; i ++) {
			cin >> s[i];
			fix(s[i]);
		}
		bool zero = false;
		int nums = 0;
		for(int i = 0; i < 26; i ++) {
			if(x[i] > 1) {
				zero = true;
			}
			if(x[i] != 0 && (f[i] + l[i] + r[i] != 0))
				zero = true;
			if(l[i] > 1 || r[i] > 1)
				zero = true;
		}
		/*if(zero)
			printf("Init zero\n");*/
		if(!zero) {
			for(int i = 0; i < 26; i ++) {
				if(l[i] + r[i] != 0 && !visited[i]) {
					zero = !bfs(i, 0);
					nums ++;
				}
				else if(f[i] != 0 && !visited[i]) {
					nums ++;
				}
			}
		}
		/*if(zero)
			printf("BECAME ZERO\n");
		for(int i = 0; i < 26; i ++) {
			printf("l: %d, r: %d, f: %d, x: %d, left: %d, right: %d\n", l[i], r[i], f[i], x[i], lft[i], rght[i]);
		}*/
		//printf("Numbs: %d\n", nums);
		if(zero) {
			printf("Case #%d: 0\n", z);
			continue;
		}
		long long ans = facs[nums];
		for(int i = 0; i < 26; i ++) {
			if(f[i] != 0) {
				ans = (ans * facs[f[i]]) % MOD;
			}
		}
		printf("Case #%d: %lld\n", z, ans);
	}
	return 0;
}
