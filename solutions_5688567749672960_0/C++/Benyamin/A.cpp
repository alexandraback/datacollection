#include <bits/stdc++.h>
#include <fstream>
#define X first
#define Y second
#define pb push_back
#define popb pop_back
#define mp make_pair
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> point;

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

const ll MAXN = 1000 * 1000 + 100;
ll t, n;
queue<ll>BFS;
bool mark[MAXN];
ll dis[MAXN];

void output(ll level, ll ans) {
	cout << "Case #" << level << ": " << ans << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(ll index = 1; index <= t; ++index) {
		cin >> n;
		fill(mark, mark + n + 1, false);
		BFS.push(1);
		dis[1] = 1;
		mark[1] = true;
		while(!BFS.empty()) {
			ll node = BFS.front();
			BFS.pop();
			if(node + 1 <= n && !mark[node + 1]) {
				mark[node + 1] = true;
				BFS.push(node + 1);
				dis[node + 1] = dis[node] + 1;
			}
			ll tmp = 0, node2 = node;
			while(node) {
				tmp = 10 * tmp + (node % 10);
				node /= 10;
			}
			if(tmp <= n && !mark[tmp]) {
				mark[tmp] = true;
				BFS.push(tmp);
				dis[tmp] = dis[node2] + 1;
			}
			if(mark[n]) {
				while(!BFS.empty())
					BFS.pop();
				break;
			}
		}
		output(index, dis[n]);
	}
	return 0;
}