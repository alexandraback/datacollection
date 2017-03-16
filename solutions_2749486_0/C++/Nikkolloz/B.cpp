#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int tc, x, y, X, Y;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int tn = 0; tn < tc; tn++) {
		scanf("%d%d", &X, &Y);
		x = abs(X); y = abs(Y);
		string res = "";
		if (x < y) {
			int k = 0, i = 1;
			while (k+i <= x) {
				k += i;
				i++;
				if (X > 0)
					res += 'E';
				else
					res += 'W';
			}
			while (k < x) {
				k++;
				i+=2;
				if (X > 0)
					res += "WE";
				else
					res += "EW";
			}
			k = 0;
			while (k+i <= y) {
				k += i;
				i++;
				if (Y > 0)
					res += 'N';
				else
					res += 'S';
			}
			while (k < y) {
				k++;
				i+=2;
				if (Y > 0)
					res += "SN";
				else
					res += "NS";
			}
		} else {
			int k = 0, i = 1;
			while (k+i <= y) {
				k += i;
				i++;
				if (Y > 0)
					res += 'N';
				else
					res += 'S';
			}
			while (k < y) {
				k++;
				i+=2;
				if (Y > 0)
					res += "SN";
				else
					res += "NS";
			}
			k = 0;
			while (k+i <= x) {
				k += i;
				i++;
				if (X > 0)
					res += 'E';
				else
					res += 'W';
			}
			while (k < x) {
				k++;
				i+=2;
				if (X > 0)
					res += "WE";
				else
					res += "EW";
			}
		}
		printf("Case #%d: %s\n", tn+1, res.c_str());
	}
	return 0;
}