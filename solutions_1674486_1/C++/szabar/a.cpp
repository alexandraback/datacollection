#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<double> vd;

bool visit(const vi * graph, int n, int * vis, int w){
//	printf("visit %d\n", w);
	if (vis[w] == 1){
		return false;
	}
//	printf("dupa\n");
	vis[w] = 1;
	for (int i = 0; i < graph[w].size(); ++i){
		int v = graph[w][i];
		if (!visit(graph, n, vis, v)){
			return false;
		}
	}
	return true;
}

bool not_has_diamond(const vi * graph, int n){
	int vis[n];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			vis[j] = 0;
		}
//		for (int j = 0; j < n; ++j){
			if(!visit(graph, n, vis, i)){
				return false;
			}
//		}
	}
	return true;
}

void run() {
	vi graph[2000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int in;
			scanf("%d", &in);
			graph[i].push_back(in - 1);
		}
	}
	if (not_has_diamond(graph, n)){
		printf("No\n");
	}else {
		printf("Yes\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		run();
	}
}
