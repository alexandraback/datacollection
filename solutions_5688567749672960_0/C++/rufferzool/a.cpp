#include <cstdio>
#include <queue>

using namespace std;

int a[1000001], dist[1000001];

int rev(int a) {
	int ret = 0;
	while(a) {
		ret = (ret * 10) + (a % 10);
		a = a / 10;
	}
	return ret;
}

void bfs() {
	queue <int> q;
	q.push(1);
	dist[1] = 1;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(x < 1000000)
			if(dist[x + 1] == 0) {
				q.push(x + 1);
				dist[x + 1] = dist[x] + 1;
			}
		if(rev(x) <= 1000000)
			if(dist[rev(x)] == 0) {
				q.push(rev(x));
				dist[rev(x)] = dist[x] + 1;
			}
	}
}

int main() {
	bfs();
/*	printf("%d\n", rev(19));
	for(int i = 1; i < 20; i ++) {
		printf("%d\n", rev(i));
	}*/
	int T;
	scanf(" %d", &T);
	for(int i = 0; i < T; i ++) {
		int n;
		scanf( "%d", &n );
		printf("Case #%d: %d\n", i + 1, dist[n]);
	}
	return 0;
}
