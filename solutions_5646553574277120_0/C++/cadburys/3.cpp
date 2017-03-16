#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int T, C, D, V;

int den;
bool arr[31];

int rec(bool a[], int prev = 0) {
	int ret = 0;
	for(int i = 1; i <= V; ++i) {
		if(a[i] == false) {
			ret = 1;
			break;
		}
	}
	if(ret == 0)
		return 0;
	if(prev == V)
		return 100;
	bool a2[31];
	int ans = 100;
	for(int p = prev + 1; p <= V; ++p) {
		memcpy(a2, a, sizeof(a2));
		for(int j = V; j >= p; --j)
			a2[j] = a2[j] || a2[j - p];
		ans = min(ans, rec(a2, p));
	}
	return 1 + ans;
}

int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		scanf("%d%d%d", &C, &D, &V);
		memset(arr, 0, sizeof(arr));
		arr[0] = true;
		for(int i = 0; i < D; ++i) {
			scanf("%d", &den);
			for(int j = V; j >= den; --j)
				arr[j] = arr[j] || arr[j - den];
		}
		printf("Case #%d: %d\n", t, rec(arr));
	}
}
