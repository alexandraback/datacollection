#include <iostream>

using namespace std;

int a[400], b[400];
int c, d, v;
int out;

bool check(int depth) {
	memset(b,0,sizeof(b));
	int x = (1<<(d+depth));
	for (int i=0; i<x; i++) {
		int cnt = 0;
		for (int j=0; j<d+depth; j++) {
			if (i & (1<<j)) cnt += a[j];
		}
		b[cnt] = 1;
	}
	for (int i=1; i<=v; i++) 
		if (b[i] == 0) return false;
	return true;
}

void search(int depth, int last) {
	if (out <= depth) return;
	if (depth == 10) return; // INF;
	for (int i=last+1; i<=v; i++) {
		for (int j=0; j<d; j++) if (i == a[j]) continue;
		// add coin
		a[d+depth] = i;
		if (check(depth)) {
			if (out > depth) out = depth;
			return;
		}
		search(depth+1, i);
	}
}

void run() {
	out = 100;
	memset(a,0,sizeof(a));
	cin >> c >> d >> v;
	for (int i=0; i<d; i++) cin >> a[i];
	if (check(0)) {
		cout << 0 << endl;
		return;
	}
	search(0, 0);
	cout << out << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}
