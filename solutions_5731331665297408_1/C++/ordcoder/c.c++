#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')

int n, m;
struct Flight {
	int to;
};
struct City {
	vector<Flight> out;
	int zip;
	bool vis, was;
};
vector<City> cities;

void dfs(int v) {
	if (cities[v].vis) return;
	cities[v].vis = true;
	for (auto &f: cities[v].out)
		dfs(f.to);
}

bool allreachable(int v){
	for (int i = 0; i < n; ++i) cities[i].vis = false;
	dfs(v);
	for (int i = 0; i < n; ++i) if (!cities[i].vis) return false;
	return true;
}

vector<int> visstack;

bool stackreachable(int cur) {
	for (int i = 0; i < n; ++i) cities[i].vis = cities[i].was;
	for (int i = 0; i < cur; ++i) {
		int v = visstack[i];
		cities[v].vis = false;
		dfs(v);
	}
	for (int i = 0; i < n; ++i) if (!cities[i].vis) return false;
	return true;
}

void visit(int v) {
	assert(!cities[v].was);
	cities[v].was = true;
	visstack.push_back(v);
	printf("%d", cities[v].zip);
}

void solve(int v) {
	visit(v);
	int bestcur = -1, bestto = -1, bestzip = 1e9;
	for (int cur = visstack.size(); cur > 0; --cur) {
		if (!stackreachable(cur)) break;
		for (auto f: cities[visstack[cur-1]].out) if (!cities[f.to].was && cities[f.to].zip < bestzip) {
			bestcur = cur;
			bestto = f.to;
			bestzip = cities[f.to].zip;
		}
	}
	//E(v, bestcur, bestto, bestzip); for (auto vs: visstack) E(vs);
	if (bestcur == -1) return;
	while (int(visstack.size()) > bestcur) visstack.pop_back();
	solve(bestto);
}

void process() {
	scanf("%d%d", &n, &m);
	cities.resize(n);
	for (int i = 0; i < n; ++i) {
		cities[i].out.clear();
		scanf("%d", &cities[i].zip);
		cities[i].was = false;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		cities[a].out.push_back(Flight{b});
		cities[b].out.push_back(Flight{a});
	}
	visstack.clear();

	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [](int a, int b){return cities[a].zip < cities[b].zip;});
	for (int start: ord) if (allreachable(start)) {
		solve(start);
		puts("");
		for (int i = 0; i < n; ++i) assert(cities[i].was);
		return;
	}
	assert(!"no way");
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcases;
	scanf("%d", &tcases);
	for (int tcase = 1; tcase <= tcases; ++tcase) {
		printf("Case #%d: ", tcase);
		process();
	}
	return 0;
}
