#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


long long get(vector<int> & v, int k) {
	long long deg = 1;
	long long ans = 0;
	for(int i = v.size() - 1; i >= 0; i--) {
		ans += v[i] * deg;
		deg *= k;
	}
	return ans;
}


void solve(int tc) {
	printf("Case #%d: ", tc);
	int k, c, s;
	scanf("%d%d%d", &k, &c, &s);
	int need = (k + c - 1) / c;
	if(need > s) {
		printf("IMPOSSIBLE\n");
		return;
	}
	int current = 0;
	for(int i = 0; i < need; i++) {
		vector<int> v;
		for(int j = 0; j < c; j++) {
			v.push_back(current);
			current++;
			current = min(current, k - 1);
		}
		printf("%lld ", get(v, k) + 1);
	}
	printf("\n");
}


int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		solve(i + 1);
	}
	return 0;
}