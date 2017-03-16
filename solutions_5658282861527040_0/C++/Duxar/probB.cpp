#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

void solve();

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, i;
	scanf("%d\n", &T);
	for (i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}

void solve() {
	int A, B, K, i, j;
	scanf("%d %d %d\n", &A, &B, &K);
	int ans =0;
	for (i = 0; i < A; ++i) {
		for (j = 0; j < B; ++j) {
			if ((i & j) < K) {
				++ans;
			}
		}
	}
	
	printf("%d\n", ans);
	
}
