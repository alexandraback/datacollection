#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
using namespace std;

#define rep(i,N) for((i) = 0; (i) < (N); (i)++)
#define rab(i,a,b) for((i) = (a); (i) <= (b); (i)++)
#define Fi(N) rep(i,N)
#define Fj(N) rep(j,N)
#define Fk(N) rep(k,N)
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()

map<int, int> c;

int reverse(int x) {
	int u = 0;

	while(x) {
		u = u * 10 + x % 10;
		x /= 10;
	}
	return u;
}

int bfs(int start, int end) {
	queue <int> Q;
	c.clear();

	c[start] = 1;
	Q.push(start);

	if(start == end) return 1;

	int u,v;

	while(!Q.empty()) {
		u = Q.front();
		Q.pop();

		v = u + 1;
		if (c.find(v) == c.end()) {
			c[v] = c[u] + 1;
			Q.push(v);
			if(v == end) return c[v];
		}

		v = reverse(u);
		if (c.find(v) == c.end()) {
			c[v] = c[u] + 1;
			Q.push(v);
			if(v == end) return c[v];
		}
	}
	return -1;
}

int main() {
	int T,cs;
	int N;

	scanf("%d",&T);

	rab(cs,1,T) {
		scanf("%d",&N);

		printf("Case #%d: %d\n",cs,bfs(1,N));
	}
	return 0;
}
