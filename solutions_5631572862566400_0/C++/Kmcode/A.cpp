#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
using namespace std;



int t;

#define MAX 1002


vector<int> v[MAX];
vector<int> r[MAX];

bool use[MAX];
bool belong[MAX];
bool searched[MAX];

inline int D(int b){
	if (searched[b]){
		puts("Error");
	}
	searched[b] = true;
	int mt = 0;
	for (int i = 0; i < r[b].size(); i++){
		if (belong[r[b][i]]){
			continue;
		}
		mt = max(mt, D(r[b][i]));
	}
	mt++;
	return mt;
}

int ord[MAX];
int rr = 0;

vector<pair<int, int> > V;

inline void dfs(int b){
	use[b] = true;
	for (int i = 0; i < v[b].size(); i++){
		if (use[v[b][i]] == false){
			dfs(v[b][i]);
		}
	}
	ord[b] = rr;
	rr++;
	V.push_back(make_pair(ord[b], b));
	return;
}

vector<int> vis;

inline int ddfs(int b){
	use[b] = false;
	int cc = 0;
	vis.push_back(b);
	for (int i = 0; i < r[b].size(); i++){
		if (use[r[b][i]]){
			cc += ddfs(r[b][i]);
		}
		use[r[b][i]] = false;
	}
	return cc + 1;
}

struct UF{
	vector<int> belong;
	vector<int> size;
	void resize(int n){
		belong.assign(n + 1, -1);
		size.assign(n + 1, 1);
	}
	inline int root(int b){
		if (belong[b] == -1){
			return b;
		}
		belong[b] = root(belong[b]);
		return belong[b];
	}
	void merge(int a, int b){
		a = root(a);
		b = root(b);
		if (a == b)return;
		belong[a] = b;
		size[b] += size[a];
	}
};
UF ff;
set<int> sss;

int main(){
	cin >> t;
	int tt = 0;
	while (t--){
		tt++;
		sss.clear();
		ff.resize(MAX);
		int n;
		V.clear();
		rr = 0;
		scanf("%d", &n);
		memset(searched, false, sizeof(searched));
		for (int i = 0; i < n; i++){
			v[i].clear();
			r[i].clear();
		}
		for (int i = 0; i < n; i++){
			int f;
			scanf("%d", &f);
			f--;
			v[i].push_back(f);
			r[f].push_back(i);
			ff.merge(i, f);
		}
		memset(use, false, sizeof(use));
		memset(belong, false, sizeof(belong));
		for (int i = 0; i < n; i++){
			if (use[i] == false){
				dfs(i);
			}
		}
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		int ccc = 0;
		int ans = 1;
		int AAA = 0;
		for (int i = 0; i < V.size(); i++){
			if (use[V[i].second] == false)continue;
			vis.clear();
			int f = ddfs(V[i].second);
			if (f > 1){
				if (sss.count(ff.root(V[i].second))){
					puts("Error");
				}
				else{
					sss.insert(ff.root(V[i].second));
				}
				int tmp = 0;
				for (int j = 0; j < vis.size(); j++){
					belong[vis[j]] = true;
				}
				if (f == 2){
					for (int j = 0; j < vis.size(); j++){
						tmp += D(vis[j]);
					}
					AAA += tmp;
				}
				else{
					tmp = f;
				}
				for (int j = 0; j < vis.size(); j++){
					belong[vis[j]] = false;
				}
				ans = max(ans, tmp);
			}
		}
		ans = max(ans, AAA);
		printf("Case #%d: ", tt);
		printf("%d", ans);
		puts("");
	}
	return 0;
}