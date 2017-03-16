#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int
	MAXN = 2016;

int curMark;
int mark[MAXN];
int from[MAXN];
unordered_map<string, int> L, R;
vector<int> G[MAXN];

int index1(string& s) {	
	int r = L[s];
	if (r == 0)
		L[s] = r = L.size();
	return r;
}

int index2(string& s) {	
	int r = R[s];
	if (r == 0)
		R[s] = r = R.size();
	return r;
}

bool augment(int u) {	
	if (mark[u] == curMark)
            return 0;
	mark[u] = curMark;
	for (int v : G[u])
		if (from[v] < 0 || augment(from[v])) {
			from[v] = u;
			return 1;
		}
	return 0;
}
	
int main() {
	ios_base::sync_with_stdio(0);
	
	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; ++test) {
		
		memset(from, -1, sizeof(from));
		memset(mark, 0, sizeof(mark));
		
		for (int i = 0; i < MAXN; ++i)
			G[i].clear();		
		curMark = 0;
		L.clear();
		R.clear();
		
		int N; cin >> N;
		for (int i = 0; i < N; ++i) {
			string su, sv;
			cin >> su >> sv;
			int u = index1(su);
			int v = index2(sv);		
			G[u].push_back(v);
		}
		
		int ans = 0;
		for (int i = 1; i <= (int)L.size(); ++i) {
			++curMark;
			if (augment(i))
				ans++;
		}
		
		cout << "Case #" << test << ": " << N - (L.size() + R.size() - ans) << endl;
	}
	
	return 0;
}
