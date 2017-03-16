#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <cmath>

using namespace std;
typedef long long ll;

string filename = "D-large";

ll intpow(ll b, ll e) {
	ll result = 1;
	for (ll i = 0; i < e; i++)
		result *= b;
	return result;
}

int main() {
	ll t, cs, k, c, s;
	ifstream fin((filename + ".in").c_str());
	FILE *fout = fopen((filename + ".out").c_str(), "w");
	fin >> t;
	cs = 0;
	while (cs++ < t) {
		fin >> k >> c >> s;
		fprintf(fout, "Case #%lld:", cs);
		c = c > k ? k : c;
		if (ceil((k + 0.0) / c) > s) {
			fprintf(fout, " IMPOSSIBLE\n");
			continue;
		}
		if (c == 1) {
			for (ll i = 0; i < k; i++)
				fprintf(fout, " %lld", i + 1);
			fprintf(fout, "\n");
			continue;
		}
		ll level = 0;
		ll endIndex;
		for (ll i = 0; i < k / c; i++) {
			ll index = 0;
			for (ll j = c - 1; j >= 0; j--) {
				index += intpow(k, j) * level;
				level++;
			}
			if (i == 0)
				endIndex = intpow(k, c) - 1 - index;
			fprintf(fout, " %lld", index + 1);
		}
		if (level < k)
			fprintf(fout, " %lld", endIndex + 1);
		fprintf(fout, "\n");
	}
	fin.close();
	fclose(fout);
	exit(0);
}