#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

fstream in, out;

int t, n, x, y;

double probs[2000][2000];

int tri_size(int layer) {
	return (2 * layer + 1) * (layer + 1);
}

int main() {
	in.open("B-small-attempt3.in", fstream::in);
	out.open("probb-small3.out", fstream::out);

	in >> t;
    for (int i = 0; i < t; i++) {
		in >> n >> x >> y;
		if (x < 0) {
			x = -x;
		}
		
		int layer = (x + y) / 2;
		double ans;
		if (n >= tri_size(layer)) {
			ans = 1.0;
		} else if (n <= tri_size(layer - 1)) {
			ans = 0.0;
		} else if (x == 0 && n < tri_size(layer)) {
			ans = 0.0;
		} else {
			int left = n - tri_size(layer - 1);
			int size = 2 * layer;

			probs[0][0] = 1.0;
			for (int j = 0; j <= size; j++) {
				for (int k = 0; k <= size; k++) {
					if (j == 0 && k > 0) {
						probs[j][k] = 0.5 * probs[j][k - 1];
					} else if (k == 0 && j > 0) {
						probs[j][k] = 0.5 * probs[j-1][k];
					} else if (k == size && j == size) {
						probs[j][k] = probs[j - 1][k] + probs[j][k - 1];
					} else if (k == size) {
						probs[j][k] = probs[j - 1][k] + 0.5 * probs[j][k - 1];
					} else if (j == size) {
						probs[j][k] = probs[j][k - 1] + 0.5 * probs[j - 1][k]; 
					} else if (k > 0 && j > 0) {
						probs[j][k] = 0.5 * probs[j - 1][k] + 0.5 * probs[j][k - 1];
					}
					cout << j << " " << k << " " << probs[j][k] << endl;
				}
			}

			ans = 0.0;
			for (int j = y + 1; j <= left; j++) {
				if (left - j <= size && j <= size) {
					ans += probs[j][left - j];
				}
				cout << i << " || " << left << " " << j << " " << y << " " << ans << endl;
			}
		}
		out << std::fixed;
		out << setprecision(9);
		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
