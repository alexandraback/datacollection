#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

typedef vector<int> VI;

const int N = 1005;

VI adj[N];
bool vis[N];
int q[1000002];
int n, spt, front, rear, u, v;

bool Found(int st){
	memset(vis, false, sizeof(vis));
	spt = 1; vis[st] = 1;
	q[1] = st;
	front = rear = 1;
	while (front <= rear){
		u = q[front];
		for(int i = 0; i < adj[u].size(); i++){
			v = adj[u][i];
			if (vis[v] && v != st) return true;
			q[++rear] = v;
			vis[v] = 1;
		}
		front++;
	}
	return false;
}

void Solve(){
	scanf("%d", &n);
	int m;
	for(int i = 0; i < n; i++){
		adj[i].clear();
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
			scanf("%d", &v);
			adj[i].push_back(v-1);
		}
	}
	bool ok = false;
	for(int i = 0; i < n; i++)
		if (Found(i)){
			ok = 1;
			break;
		}
	if (ok) printf(" Yes\n");
	else printf(" No\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ntest;
	cin >> ntest;
	for(int test = 1; test <= ntest; test++){
		printf("Case #%d:", test);
		Solve();
	}

	return 0;
}
