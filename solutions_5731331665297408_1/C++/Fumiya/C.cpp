#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

typedef vector< vector<int> > Graph;

bool isValid(const Graph& g, const vector<int>& order){
	stack<int> st;
	st.push(order[0]);
	for(int i=1;i<order.size();i++){
		while(true){
			if(st.empty()) return false;
			int pos = st.top();
			bool ok = false;
			for(int j=0;j<g[pos].size();j++){
				if(g[pos][j] == order[i]) ok = true;
			}
			if(ok){ st.push(order[i]); break; }
			else st.pop();
		}
	}

	int n = g.size();
	vector<int> visit(n, 0);
	for(int i=0;i<order.size();i++) visit[order[i]] = 1;
	queue<int> qu;
	while(!st.empty()){ qu.push(st.top()); st.pop(); }
	while(!qu.empty()){
		int p = qu.front(); qu.pop();
		for(int i=0;i<g[p].size();i++){
			if(visit[g[p][i]]) continue;
			visit[g[p][i]] = 1;
			qu.push(g[p][i]);
		}
	}
	for(int i=0;i<n;i++)
		if(visit[i]==0) return false;
	return true;
}

int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int N, M; cin >> N >> M;
		Graph g(N);
		vector<string> vs(N);
		vector<int> state(N, 0);
		for(int i=0;i<N;i++) cin >> vs[i];
		for(int i=0;i<M;i++){
			int a, b; cin >> a >> b;
			g[a-1].push_back(b-1);
			g[b-1].push_back(a-1);
		}
		string res;
		int idx = 0;
		for(int i=0;i<N;i++)
			if(vs[idx] > vs[i]) idx = i;
		res = vs[idx];
		vector<int> order; order.push_back(idx);
		vector<int> visit(N, 0);
		visit[idx] = 2;
		for(int i=0;i<g[idx].size();i++) visit[g[idx][i]] = 1;
		for(int i=1;i<N;i++){
			idx = -1;
			order.push_back(0);
			for(int j=0;j<N;j++){
				if(visit[j]!=1) continue;
				order.back() = j;
				if(isValid(g, order) && (idx==-1 || vs[idx] > vs[j])) idx = j;
			}
			order.back() = idx;
			res += vs[idx];
			visit[idx] = 2;
			for(int i=0;i<g[idx].size();i++) visit[g[idx][i]] = max(1, visit[g[idx][i]]);
		}
		printf("Case #%d: %s\n", test, res.c_str());
	}
}
