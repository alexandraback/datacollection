#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string arr[100];
vector<int> o;

bool check() {
	bool k[27];
	char last = 0;
	fill(k, k+27, false);
	for (int co = 0; co < o.size(); co++) {
		int t = o[co];
		for (int i = 0; i < arr[t].length(); i++) {
			char C = arr[t][i];
			if (last != C && k[C-'a']) return false;
			k[C-'a'] = true;
			last = C;
		}
	}
	return true;
}

void solve(int testcase) {
	int n, w = 0; cin >> n;
	o.clear();
	for (int i = 1; i <= n; i++) cin >> arr[i], o.push_back(i);
	if (check()) w++;
	while (next_permutation(o.begin(), o.end())) if (check()) w++;
	printf("Case #%d: %d\n", testcase, w);
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}