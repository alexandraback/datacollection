#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector < ll > vll;
typedef pair < ll, ll > pll;
typedef pair < int , int > pii;
typedef vector < int > vii;

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define reps(i, a, n) for (int i = a; i < n; ++i)
#define l(x) (((x) << 1) | 1)
#define r(x) ((l(x)) + 1)
#define fst first
#define snd second
#define ajd adj
#define prev fsdklfjalsdflsdafjl

const int N = 3e6 + 500;
const ll mod = 1e9 + 7;
ll INF = 1LL << 57LL;

ll n, u, v, c, d, t, l, r, q, m, x, k;
queue < int > Q;
bool vis[N];
int dist[N];
int reverse(int x) {
	int y = 0;
	while (x % 10 == 0) x /= 10;
	while (x) {
		y *= 10;
		y += (x % 10);
		x /= 10;
	}
	return y;
}
void bfs() {
	Q.push(1);
	dist[1] = 1;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		if (vis[x]) continue;
		vis[x] = true;
		if (x >= N - 1) continue;
		if (dist[x + 1] > dist[x] + 1 || dist[x + 1] == -1) { 
			Q.push(x + 1);
			dist[x + 1] = dist[x] + 1;
			}
		int y = reverse(x);
		if (y >= N) continue;
		if (dist[y] > dist[x] + 1 || dist[y] == -1) {
				dist[y] = dist[x] + 1;
				Q.push(y);
			}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	rep (i, N) dist[i] = -1;
	bfs();
	for (int xx = 1; xx <= t; ++xx) {
		cout << "Case #" << xx << ": ";
		cin >> n;
		cout << dist[n] << '\n';
	}
	return 0;
}
