#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int h, w;
		cin >> h >> w;
		int a[w][h];
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				cin >> a[x][y];
		int maxw[w], maxh[h];
		for (int y = 0; y < h; y++)
			maxh[y] = 0;
		for (int x = 0; x < w; x++)
			maxw[x] = 0;

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				maxw[x] = max(maxw[x], a[x][y]);
				maxh[y] = max(maxh[y], a[x][y]);
			}
		bool yes = true;
		for (int y = 0; y < h && yes; y++)
			for (int x = 0; x < w && yes; x++)
				if (a[x][y] < min(maxw[x], maxh[y]))
					yes = false;

		cout << "Case #" << (i+1) << ": " << (yes ? "YES" : "NO") << "\n";
	}
}
