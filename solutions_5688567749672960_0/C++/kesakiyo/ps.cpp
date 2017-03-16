#include <stdio.h>
#include <queue>
#include <string.h>
#define MAX	1000010

using namespace std;

typedef long long ll;

int T;
ll n, dist[MAX];

ll getReverse(ll num) {
	ll ret=0;
	while(num) {
		ret*=10;
		ret+=num%10;
		num/=10;
	}
	return ret;
}

void bfs() {
	memset(dist, -1, sizeof(dist));
	dist[1]=1;
	queue<ll> q;
	q.push(1);

	while(q.size()) {
		ll here=q.front();
		q.pop();

		ll x=here+1, y=getReverse(here);
		if(x<MAX && dist[x]==-1) {
			dist[x]=dist[here]+1;
			q.push(x);
		}
		if(y<MAX && dist[y]==-1) {
			dist[y]=dist[here]+1;
			q.push(y);
		}
	}
}

int main() {
	bfs();
	scanf("%d", &T);
	for(int t=1 ; t<=T ; t++) {
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", t, dist[n]);
	}
}