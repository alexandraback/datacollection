#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 22, MAXV = 1005;

int t;
map<string, int> word[2];
char s[MAXN];

vector<int> graph[MAXV];
int inv_edge[MAXV];
bool used[MAXV];

int dfs(int v) {
	//cerr << v << endl;
	used[v] = true;
	for (int to: graph[v]) {
	 	if (inv_edge[to] == -1) {
	 	 	inv_edge[to] = v;
	 	 	used[v] = 1;
	 	 	return 1;
	 	}
	 	if (!used[inv_edge[to]] && dfs(inv_edge[to])) {
	 	 	inv_edge[to] = v;
	 	 	used[v] = 1;
	 	 	return 1;
	 	}
	}
	return 0;
}

int main() {
	//freopen("inp", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &t);

	for (int tn = 0; tn < t; ++tn) {
		word[0].clear();
		word[1].clear();
		int c[2] = {0, 0};
	 	int n;
	 	scanf("%d", &n);

	 	for (int i = 0; i < MAXV; ++i) {
	 	 	graph[i].clear();
	 	 	inv_edge[i] = -1;
	 	}

	 	vector<pii> inp;
	 	for (int i = 0; i < n; ++i) {
	 	 	scanf("%s", s);
	 	 	int l = strlen(s);
	 	 	string w;
	 	 	for (int j = 0; j < l; ++j) {
	 	 	 	w += s[j];
	 	 	}
	 	 	if (!word[0].count(w)) {
	 	 	 	word[0][w] = c[0]++;
	 	 	}
	 	 	int a = word[0][w];

	 	 	scanf("%s", s);
	 	 	w = "";
	 	 	l = strlen(s);
	 	 	for (int j = 0; j < l; ++j) {
	 	 	 	w += s[j];
	 	 	}
	 	 	if (!word[1].count(w)) {
	 	 	 	word[1][w] = c[1]++;
	 	 	}
	 	 	int b = word[1][w];

	 	 	graph[a].puba(b);
	 	 	//cerr << a << " " << b << endl;
	 	}

	 	
	 	for (int i = 0; i < szof(word[0]); ++i) {
	 		//cerr << "i: " << i << endl;
	 		memset(used, 0, sizeof used);
	 	 	dfs(i);      
       	}
       	int ans = szof(word[0]);          
       	for (int i = 0; i < szof(word[1]); ++i) {
       	 	if (inv_edge[i] == -1) {
       	 	 	++ans;
       	 	}
       	}
       	cout << "Case #" << tn + 1 << ": " << n - ans << "\n";
	}

	return 0;
}