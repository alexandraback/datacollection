#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

set<int> adj[2123];
int N, n, rm[2123];
void go() {
	int i;
	for(i = 0; i < N && (rm[i] || adj[i].size() >= 2); i++);
	if(i < N && adj[i].empty()){ rm[i] = 1; n--;  return; }
	if(i == N) for(i = 0; rm[i]; i++);
	int j = *adj[i].begin();
	for(int v : adj[i])
		adj[v].erase(i);
	for(int v : adj[j])
		adj[v].erase(j);
	adj[i].clear(); adj[j].clear();
	n -= 2; rm[i] = rm[j] = 1;
}

map<string, int> mp;
int get(string s) {
	if(!mp.count(s)) mp[s] = mp.size() - 1;
	return mp[s];
}


char s1[100], s2[100];
int main() {
	int i;
	for_tests(t, tt) {
		mp.clear();
		memset(rm, 0, sizeof rm);
		scanf("%d", &n);
		N = n;
		for(i = 0; i < n; i++) {
			string S1, S2;
			scanf("%s %s", s1, s2);
			S1 = s1; S2 = s2;
			S1 += '1'; S2 += '2';
			int a = get(S1), b = get(S2);
			adj[a].insert(b);
			adj[b].insert(a);
		}
		int all = n;
		n = N = mp.size();
		while(n) go(), all--;
		printf("Case #%d: %d\n", tt, all);
	}
}
