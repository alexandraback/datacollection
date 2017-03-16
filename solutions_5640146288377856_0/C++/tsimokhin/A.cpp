#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-1.out", "w", stdout);
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++) {
		int r, c, w;
		cin >> r >> c >> w;
		int preans = (r - 1) * (c / w);
		int lastans1 = (c-w) / w + w + c % w;
		int lastans2 = w + 1 + (c - w - 1) / w;
		cout <<"Case #"<<q<<": "<<preans + min(lastans1, lastans2)<<endl;
	}
}