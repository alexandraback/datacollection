#include <iostream>

using namespace std;

int b[100][100];
int a[100][100][100];

int bs2(int c, int w, int p) {
	if (p > w) {
		c -= p-w;
		p = w;
	}
	if (c > p+w-1) c = p+w-1;
	if (p*2 > c) p = c-p+1;
	
	if (c == w) return c;
	if (c < w) return 100; // INF
	if (a[c][w][p] != 0) return a[c][w][p];
	
	int mx = c;
	
	for (int i=1; i<p; i++) {
		int t = 1+bs2(c-i, w, p-i), t2 = bs2(c, w, i);
		int r;
		if (t >= 100) r = t2;
		else if (t2 >= 100) r = t;
		else r = max(t, t2);
		mx = min(mx, r);
	}
	a[c][w][p] = mx;
	return mx;
}

int bs(int c, int w) {
	if (b[c][w] != 0) return b[c][w];
	if (c == w) return c;
	if (c < w) return 100; // INF
	int mx = c;
	for (int i=1; i<=c; i++) {
		int t = max(1+bs(c-i, w)+(i-1)/w, bs2(c, w, i));
		if (mx > t) mx = t;
	}
	b[c][w] = mx;
	return mx;
}

void run() {
	int r, c, w;
	cin >> r >> c >> w;
	if (r == 1) {
		cout << bs(c, w) << endl;
	} else {
		cout << bs(c, w)+(r-1)*(c/w) << endl;
	}
	return;
}

int main() {
	int n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin >> n;
	for (int i=1; i<=n; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}
