#include <bits/stdc++.h>
using namespace std;

int main() {
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		string a, b;
		cin >> a >> b;
		int ans = 100000;
		string ansa, ansb;
		for (int i = 0; i < pow(10, a.length()); i++) {
			for (int j = 0; j < pow(10, b.length()); j++) {
				string genA = "", genB = "";
				for (int k = 0; k < a.length(); k++) {
					genA += (i / (int)pow(10, k)) % 10 + '0';
					genB += (j / (int)pow(10, k)) % 10 + '0';
				}
				reverse(genA.begin(), genA.end());
				reverse(genB.begin(), genB.end());
				bool fail = 0;
				for (int k = 0; k < a.length(); k++) {
					if (genA[k] != a[k] && a[k] != '?') fail = 1;
					if (genB[k] != b[k] && b[k] != '?') fail = 1;
				}
				if (fail) continue;
				int newans = abs(i - j);
				if (newans < ans) {
					ans = newans;
					ansa = genA;
					ansb = genB;
				}
			}
		}
		printf("Case #%d: %s %s\n", tc, ansa.c_str(), ansb.c_str());
	}
}
