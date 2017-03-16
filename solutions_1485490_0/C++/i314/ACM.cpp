#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#define MAXN 103
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
typedef long long LL;
typedef pair<int, int> pii;

struct Data {
	LL cnt;
	int type;
	Data(LL _cnt, int _type):cnt(_cnt), type(_type) {}
	Data(){}
}data[2][MAXN];
int n, m;
LL key;

void dfs(int a, int b, LL cnt) {
	if(a == n || b == m) {
		key = max(key, cnt);
		return ;
	}

	if(data[0][a].type == data[1][b].type) {
		if(data[0][a].cnt > data[1][b].cnt) {
			data[0][a].cnt -= data[1][b].cnt;
			dfs(a, b+1, cnt + data[1][b].cnt);
			data[0][a].cnt += data[1][b].cnt;

		} else if(data[0][a].cnt < data[1][b].cnt) {
			data[1][b].cnt -= data[0][a].cnt;
			dfs(a+1, b, cnt+data[0][a].cnt);
			data[1][b].cnt += data[0][a].cnt;

		} else {
			dfs(a+1, b+1, cnt + data[0][a].cnt);
		}
	} else {
		dfs(a+1, b, cnt);
		dfs(a, b+1, cnt);
	}
}

LL hack() {
	key = 0;
	dfs(0, 0, 0);
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif

	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) {
			scanf("%lld %d", &data[0][i].cnt, &data[0][i].type);
		}
		for(int i=0; i<m; ++i) {
			scanf("%lld %d", &data[1][i].cnt, &data[1][i].type);
		}
		printf("Case #%d: %lld\n", cas, hack());
	}

	return 0;
}
