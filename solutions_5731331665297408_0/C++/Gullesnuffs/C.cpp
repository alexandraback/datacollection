#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int zip[55];
int f[5005], t[5005], used[5005];
vector<int> adj[55];
bool done[55];
bool visited[55];
int parent[55], parentEdge[55];
bool tried[55];
int N;

void dfs(int node){
	if(visited[node])
		return;
	visited[node]=1;
	for(int i=0; i < adj[node].size(); ++i){
		int e=adj[node][i];
		int to=f[e]+t[e]-node;
		if(done[to] && to != parent[node])
			continue;
		dfs(to);
	}
}

bool connected(int node){
	for(int i=0; i < N; ++i){
		visited[i]=0;
	}
	dfs(node);
	for(int i=0; i < N; ++i){
		if(!visited[i] && !done[i])
			return false;
	}
	return 1;
}

vector<int> ans;

int main(){
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.out", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int test=1; test <= T; ++test){
		int M;
		fscanf(fin, "%d%d", &N, &M);
		for(int i=0; i < N; ++i){
			fscanf(fin, "%d", zip+i);
			adj[i].clear();
			done[i]=0;
			parent[i]=-1;
		}
		for(int i=0; i < M; ++i){
			fscanf(fin, "%d%d", f+i, t+i);
			--f[i];
			--t[i];
			adj[f[i]].push_back(i);
			adj[t[i]].push_back(i);
			used[i]=0;
		}
		ans.clear();
		int cur=0;
		for(int i=1; i < N; ++i){
			if(zip[i] < zip[cur])
				cur=i;
		}
		ans.push_back(cur);
		done[cur]=1;
		parent[cur]=-1;
		for(int i=1; i < N; ++i){
			for(int j=0; j < N; ++j){
				tried[j]=0;
			}
			int tmp=cur;
			int best=-1, bestParent;
			while(tmp != -1){
				for(int j=0; j < adj[tmp].size(); ++j){
					int e=adj[tmp][j];
					int to=f[e]+t[e]-tmp;
					if(tried[to] || done[to])
						continue;
					tried[to]=1;
					//++used[e];
					parent[to]=tmp;
					if(connected(to) && (best == -1 || zip[to] < zip[best])){
						best=to;
						bestParent=tmp;
					}
					parent[to]=-1;
				}
				tmp=parent[tmp];
			}
			done[best]=1;
			parent[best]=bestParent;
			ans.push_back(best);
			cur=best;
		}
		fprintf(fout, "Case #%d: ", test);
		for(int i=0; i < ans.size(); ++i)
			fprintf(fout, "%d", zip[ans[i]]);
		fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
