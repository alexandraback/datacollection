#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

#define INF (1ll << 60)

typedef pair<int,int> ii;
vector<long long> dist;

int flip(int u){
	char str[10];
	sprintf(str, "%d", u);
	reverse(str, str+strlen(str));
	return atoi(str);
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output", "w", stdout);
	int tcase = 0;

	dist.assign(1000001, -1);
	queue<int> q;

	dist[1] = 0;
	q.push(1);

	while(!q.empty()){		
		int u = q.front(); q.pop();

		int v = u + 1;

		if(v <= 1000000 and dist[v] == -1){
			dist[v] = dist[u] + 1;
			q.push(v);
		}

		v = flip(u);

		if(v <= 1000000 and dist[v] == -1){
			dist[v] = dist[u] + 1;
			q.push(v);
		}

		v = flip(v);

		if(v <= 1000000 and dist[v] == -1){
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}

	int T;
	scanf("%d", &T);

	while(T--){
		int N;
		scanf("%d", &N);
		printf("Case #%d: %lld\n", ++tcase, N == 1 ? 1 : dist[N]+1);
	}
}