#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long num;
long long msk[20];
int arr[20], digits = 0;

void initMsk() {
	msk[0] = 1;
	for (int i = 1; i < 16; i++)
		msk[i] = msk[i - 1] * 10;
}

int reverse(int x) {
	int ret = 0;
	while (x) {
		int v = x % 10;
		ret = ret * 10 + v;
		x /= 10;
	}
	return ret;
}

int dist[2000000];
int queue[2000000];
int qs, qe;

void bfs() {
	memset(dist, 0x0a, sizeof dist);
	qs = qe = 0;
	queue[qe++] = 0;
	dist[0] = 0;
	while (qs < qe) {
		int cur = queue[qs++];
		int val = dist[cur];
		int nxt = cur + 1;
		int rev = reverse(cur);
		if (nxt <= 1000000 && val + 1 < dist[nxt]) {
			dist[nxt] = val + 1;
			queue[qe++] = nxt;
		}
		if (rev <= 1000000 && val + 1 < dist[rev]) {
			dist[rev] = val + 1;
			queue[qe++] = rev;
		}
	}
	return;
}

int solve() {
	cin >> num;
	return dist[num];
}

int main() {
	int t, cas;
	initMsk();
	bfs();
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++) {
		int ret = solve();
		cout << "Case #" << cas << ": " << ret << endl;
	}
	return 0;
}