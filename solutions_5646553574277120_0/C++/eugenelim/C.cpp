#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int C, D, V;
bool vals[110], deno[110];

bool check() {
	for (int i=0; i<=V; i++) {
		if (!vals[i]) return false;
	}
	return true;
}

int main() {
	int T, tc=1, d, i, j, res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &C, &D, &V);
		memset(vals, false, sizeof vals);
		memset(deno, false, sizeof deno);
		res = 0;
		vals[0] = true;
		for (i=0; i<D; i++) {
			scanf("%d", &d);
			deno[d] = true;
			for (j=V-d; j>=0; j--) {
				if (vals[j]) vals[j+d] = true;
			}
		}
		for (i=1; i<=V; i++) {
			if (deno[i] || vals[i]) continue;
			if (check()) break;
			for (j=V-i; j>=0; j--) {
				if (vals[j]) vals[j+i] = true;
			}
			res++;
		}
		printf("Case #%d: %d\n", tc++, res);
	}
	return 0;
}