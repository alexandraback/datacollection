#include <bits/stdc++.h>

#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define SIZE(a) ((int)a.size())
#define pb push_back
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int n, m;
char buff[13];
string code[53];
int color[53];
vector<int> E[53];
vector<int> ord;

bool connected(){
	bool vis[53];
	queue<int> Q;
	FWD(i,1,n+1){
		vis[i] = 0;
		if(color[i] == 1)
			Q.push(i);
	}
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v : E[u])
			if(color[v] != 2)
				Q.push(v);
	}
	FWD(i,1,n+1)
		if(color[i] == 0 && vis[i] == 0)
			return false;
	return true;
}

struct cmp{
	bool operator()(int u, int v){
		return code[u] < code[v];
	}
};

int getbest(set<int, cmp> &pos){
	while(true){
		if(pos.empty())
			return -1;
		int v = *pos.begin();
		if(color[v] == 0)
			return v;
		pos.erase(pos.begin());
	}
}

vector<int> st;
set<int, cmp> pos[53];

void dfs(int u){
	color[u] = 1;
	assert(connected());
	ord.push_back(u);
	for(int v : E[u])
		if(color[v] == 0)
			pos[u].insert(v);
	while(true){
		int v = getbest(pos[u]);
		if(v == -1)
			return;
		color[u] = 2;
		bool out = 0;
		for(int w : st)
			color[w] = 2;
		for(int w : st){
			color[w] = 1;
			if(connected() && getbest(pos[w]) != -1 && code[getbest(pos[w])] < code[v]){
				out = 1;
			}
		}
		if(out)
			return;
		color[u] = 1;
		pos[u].erase(v);
		st.push_back(u);
		dfs(v);
		st.pop_back();
	}
}

int main(){
	int Z; scanf("%d", &Z); FWD(z,1,Z+1){
		scanf("%d %d", &n, &m);
		FWD(i,1,n+1){
			scanf("%s", buff);
			code[i] = string(buff);
			E[i].clear();
			color[i] = 0;
			pos[i].clear();
		}
		FWD(i,0,m){
			int a, b;	
			scanf("%d %d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		int u = 1;
		FWD(i,2,n+1)
			if(code[i] < code[u])
				u = i;
		ord.clear();
		st.clear();
		st.push_back(u);
		dfs(u);
		printf("Case #%d: ", z);
		for(int u : ord) printf("%s", code[u].c_str());
		printf("\n");
	}
	return 0;
}
