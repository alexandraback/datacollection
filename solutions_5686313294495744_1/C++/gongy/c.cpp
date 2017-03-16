#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define PB push_back
typedef long long ll;

int T, N, A, B, ans, t, c[1100];
map<string, int> ma, mb;
string a, b;
vector<int> adj[1100];
bool s[1100];

bool d (int x) {
	fo(i, (int) adj[x].size()) {
		int y = adj[x][i];
		if(!s[y]) {
			s[y] = 1;
			if(c[y]<0 || d(c[y])) return 1 + (c[y]=x);
		}
	}
	return false;
}

int main () {
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		t = A = B = ans = 0; ma.clear(), mb.clear();
		fo(i, 1100) adj[i].clear();
		cin >> N;
		fo(i, N) {
			cin >> a >> b;
			if (!ma.count(a)) ma[a] = A++;
			if (!mb.count(b)) mb[b] = B++;
			adj[ma[a]].PB(mb[b]);
		}

		fill(c, c+B, -1);
		fo(i, A) fill(s, s+B, 0), t += d(i);
		//t is how many edges matched
		//2*t is how many nodes matched
		ans = N - (A+B - 2*t + t);

		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
