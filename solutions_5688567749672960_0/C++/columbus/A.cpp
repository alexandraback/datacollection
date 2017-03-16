#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 1000000
using namespace std;

typedef long long lint;

lint flip(lint num) {
	if(num == 0LL) return 0;
	lint aux = num, pot = 1LL, res = 0LL;
	while(aux != 0) {
		pot *= 10LL;
		aux /= 10;
	}
	pot /= 10LL;
	aux = num;
	while(aux != 0) {
		res += (aux % 10) * pot;
		aux /= 10;
		pot /= 10;
	}
	return res;
}

map<lint, lint> dist;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		dist.clear();
		lint n;
		scanf("%lld", &n);
		queue<lint> q;
		q.push(1);
		dist[1] = 1;
		while(!q.empty()) {
			lint v = q.front();
			q.pop();
			if(v == n) break;
			if(dist.find(v + 1) == dist.end()) {
				dist[v+1] = dist[v] + 1;
				q.push(v+1);
			}
			int u = flip(v);
			if(dist.find(u) == dist.end()) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
		while(!q.empty()) q.pop();
		printf("Case #%d: %lld\n", i, dist[n]);
	}
	return 0;
}