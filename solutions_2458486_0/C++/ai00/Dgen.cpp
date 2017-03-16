#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
#define MAXN 200
map<int, int> keys[MAXN], keyget;
int f[MAXN];
int type[MAXN];
int g[MAXN];
int indegree[MAXN], outdegree[MAXN];
vector<int> edge[MAXN];
void ai00(map<int, int> &a, map<int, int> &b, int c){
	map<int, int>::iterator it;
	for (it = b.begin(); it != b.end(); ++it){
		a[it->first] += it->second * c;
	}
}
bool ai00(int n, int r, map<int, int> &key){
	//cout<<"  hehe  "<<n<<' '<<r<<endl;
	//return true;
	vector<int >v;
	for (int i = 0; i < n; ++i)
		if (!f[i]) v.push_back(i);
	for (int i = 0; i < r; ++i){
		indegree[i] = 0;
		outdegree[i] = 0;
		edge[i].clear();
		g[i] = 0;
	}
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < r; ++j)
			if (i != j){
				int x = v[i], y = type[v[j]];
				if (keys[x].find(y) != keys[x].end()){
					edge[i].push_back(j);
					++indegree[j];
					++outdegree[i];
				}
			
			}
	int get = 0;
	//cout<<"ai00"<<endl;
	while (true){
		if (get == r) break;
		int f = 0;
		for (int i = 0; i < r; ++i)
			if ((!g[i])&&(indegree[i] == 0)&&(outdegree[i]))
				if (key[type[v[i]]]){
					//cout<<v[i]<<endl;
					--key[type[v[i]]];
					g[i] = 1;
					++get;
					ai00(key, keys[v[i]], 1);
					f = 1;
					for (int j = 0; j < edge[i].size(); ++j)
						--indegree[edge[i][j]];
				}else{
					//cout<<"eai"<<v[i]<<endl;
					f = -1;
					break;
				}
		if (f == -1) break;
		if (f) continue;
		for (int i = 0; i < r; ++i)
			if ((!g[i])&&(key[type[v[i]]])&&(indegree[i])&&(outdegree[i])){
				//cout<<v[i]<<endl;
				--key[type[v[i]]];
				g[i] = 1;
				++get;
				ai00(key, keys[v[i]], 1);
				f = 1;
				for (int j = 0; j < edge[i].size(); ++j)
					--indegree[edge[i][j]];
			}
		if (f) continue;
		
		for (int i = 0; i < r; ++i)
			if ((!g[i])&&(key[type[v[i]]])){
				//cout<<v[i]<<endl;
				--key[type[v[i]]];
				g[i] = 1;
				++get;
				ai00(key, keys[v[i]], 1);
				f = 1;
				for (int j = 0; j < edge[i].size(); ++j)
					--indegree[edge[i][j]];
			}
		if (!f) break;
	}
	for (int i = 0; i < r; ++i){
		++key[type[v[i]]];
		ai00(key, keys[v[i]], -1);
	}
	//cout<<r<<' '<<get<<endl;
	return get == r;
}
void ai00(){
	int n, m;
	keyget.clear();
	scanf("%d %d ", &m, &n);
	for (int i = 0; i < m; ++i){
		int x;
		scanf("%d ", &x);
		//cout<<x<<' ';
		if (keyget.find(x) == keyget.end()) keyget[x] = 1;
		else ++keyget[x];
	}
	//cout<<endl;
	for (int i = 0; i < n; ++i){
		f[i] = 0;
		scanf("%d ", &type[i]);
		keys[i].clear();
		int m;
		scanf("%d ", &m);
		for (int j = 0; j < m; ++j){
			int x;
			scanf("%d ", &x);
			//cout<<x<<' ';
			if (keyget.find(x) == keyget.end()) keyget[x] = 0;
			if (keys[i].find(x) == keys[i].end()) keys[i][x] = 1;
			else ++keys[i][x];
		}
		//cout<<endl;
	}
	if (!ai00(n, n, keyget)){
		printf(" IMPOSSIBLE");
		return ;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if ((!f[j])&&(keyget[type[j]]!= 0)){
				--keyget[type[j]];
				f[j] = true;
				ai00(keyget, keys[j], 1);
				if (ai00(n, n - i - 1, keyget)){
					printf(" %d", j + 1);
					break;
				}else{
					++keyget[type[j]];
					f[j] = false;
					ai00(keyget, keys[j], -1);
				}
			}
}
int main(){
	int t, tt;
	for (scanf("%d ", &tt), t = 0; t < tt; ++t){
		printf("Case #%d:", t + 1);
		ai00();
		printf("\n");
	}
}
