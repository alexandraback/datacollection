#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int N;
string res;

struct Node{
	int next;
	int prev;
	Node(){}
	Node(int n, int p) :next(n), prev(p){}
};

bool canReach(int start, int end, const vector<int> &canUse, vector<vector<int> > &graph, const vector<int> &canUseMultiple){
	queue<Node> que;
	que.push(Node(start,-1));
	vector<int> used(N, 0);
	vector<int> prevUsed(N, 0);
	while (!que.empty()){
		Node n = que.front(); que.pop();
		int v = n.next;
		int p = n.prev;
		if (used[v])continue;
		if (p != -1 && canUseMultiple[p] == 0 && prevUsed[p] > 0)continue;
		used[v] = 1;
		if (p != -1)prevUsed[p]++;
		if (v == end)return true;
		REP(i, N){
			if (canUse[i] && graph[v][i] && used[i]==0){
				que.push(Node(i,v));
			}
		}
	}
	return false;
}



int main(){
	int T;
	cin >> T;
	REP(testCase, T){
		int M;
		cin >> N >> M;
		vector<string> zipcodes(N);
		REP(i, N)cin >> zipcodes[i];
		vector<vector<int> > graph(N, vector<int>(N, 0));
		REP(i, M){
			int u, v;
			cin >> u >> v;
			u--, v--;
			graph[u][v] = graph[v][u] = 1;
		}
		res = "a";
		vector<int> perm;
		REP(i, N)perm.push_back(i);
		do{
			REP(hub, N){
				bool canConcat = true;
				bool canUseHub = false;
				if (perm[0] == hub)canUseHub = true;
				REP(i, N - 1){
					int p = perm[i];
					int v = perm[i + 1];
					if (graph[p][v] == 0){
						if (!canUseHub) canConcat = false;
						else if (graph[hub][v] == 0)canConcat = false;
					}
					if (v == hub)canUseHub = true;
				}
				if (canConcat){
					string tmp = "";
					REP(i, N)tmp += zipcodes[perm[i]];
					res = min(res, tmp);
				}
			}
		}while(next_permutation(ALL(perm)));
		
		cout << "Case #" << testCase + 1 << ": " << res << endl;
	}
}