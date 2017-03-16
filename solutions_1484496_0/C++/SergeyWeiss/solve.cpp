#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef long long lint;

int A[2 << 20];
int B[22];

void print(int mask) {
	for(int i = 0; i < 22; i++) {
		if(mask & (1 << i)) {
			printf("%d ", B[i]);
		}
	}
	printf("\n");
}

bool Solve(int test) {
	printf("Case #%d:\n", test);
	int n;
	cin >> n;
	for(int i = 0; i <= n * 100 * 1000; i++) A[i] = 0;
	for(int i = 0; i < n; i++) {
		cin >> B[i];
	}
	for(int mask = 1; mask < 1 << n; ++mask) {
		int sum = 0;
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) sum += B[i];
		}
		if(A[sum]) {
			print(A[sum]);
			print(mask);
			return true;
		}
		A[sum] = mask;
	}
	puts("Impossible");
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 0;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
		Solve(i);
	//*/while(Solve(++t));
	return 0;
}