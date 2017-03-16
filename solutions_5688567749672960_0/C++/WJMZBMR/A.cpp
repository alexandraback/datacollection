#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
const int MAX_N = int(1e6) + 10;
int que[MAX_N], qh, qt;
int dist[MAX_N];

int main() {
	qh = qt = 0;
	memset(dist, -1, sizeof dist);
	dist[1] = 1;
	que[qt++] = 1;

	while (qh < qt) {
		int u = que[qh++];
		int d = dist[u];
		if (u + 1 < MAX_N && dist[u + 1] == -1) {
			dist[u + 1] = d + 1;
			que[qt++] = u + 1;
		}
		ostringstream oss;
		oss << u;
		string U = oss.str();
		reverse(U.begin(), U.end());
		int ru = atoi(U.c_str());
		if (ru < MAX_N && dist[ru] == -1) {
			dist[ru] = d + 1;
			que[qt++] = ru;
		}
	}

	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int n;
		cin >> n;
		printf("Case #%d: %d\n", nc, dist[n]);
	}
}
