#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	//freopen("B-small-attempt0.in.txt", "r", stdin);
	freopen("B-large.in.txt", "r", stdin);
	freopen("large.out", "w", stdout);
	int T;
	cin >> T;
	string line;
	getline(cin, line);
	for (int i = 1; i <= T; i++) {
		vector<bool> v;
		getline(cin, line);
		for (int j = 0; j < line.length(); j++) {
			if (line[j] == '+') v.push_back(true);
			if (line[j] == '-') v.push_back(false);
		}
		int sol = 0;
		/*printf("S: ");
		for (int j = 0; j < line.length(); j++) {
			printf("%d ", (int)v[j]);
		}*/
		for (int j = v.size()-1; j >= 0; j--) {
			if (!v[j]) {
				if (v[0]) {
					sol++;
					for (int m = 0; m <= j; m++) {
						if (!v[m]) break;
						v[m] = false;
					}
					/*printf("T: ");
					for (int j = 0; j < line.length(); j++) {
						printf("%d ", (int)v[j]);
					}*/
				}
				sol++;
				int p1 = 0, p2 = j;
				while (p1 <= p2) {
					bool aux = v[p1];
					v[p1] = !v[p2];
					v[p2] = !aux;
					p1++; p2--;
				}
				/*printf("B: ");
				for (int j = 0; j < line.length(); j++) {
					printf("%d ", (int)v[j]);
				}*/
			}
		}
		printf("Case #%d: %d\n", i, sol);
	}
	return 0;
}