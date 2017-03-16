#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>
#include <queue>
#include <assert.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

int A, B, K, LEN = 50;
vector<int> a, b, k;
ll D[55][2][2][2];

ll solve(int n, int smallerA, int smallerB, int smallerK) {
	if(n == LEN) {
		return 1;
	}
	if(D[n][smallerA][smallerB][smallerK] != -1)
		return D[n][smallerA][smallerB][smallerK];
	ll res = 0;
	for(int i = 0;i<2;i++) {
		if(!smallerA && i > a[n]) continue;
		for(int j = 0;j<2;j++) {
			if(!smallerB && j > b[n])
				continue;
			int bit = i & j;
			if(!smallerK && bit > k[n]) {
				continue;
			}
			ll ans = solve(n + 1, smallerA || (i < a[n]), smallerB || (j < b[n]), smallerK || (bit < k[n]));
			res += ans;
		}
	}
	return D[n][smallerA][smallerB][smallerK] = res;
}

vector<int> toBinary(int n) {
	vector<int> res;
	while(n) {
		res.push_back(n%2);
		n /= 2;
	}
	int sz = res.size();
	for(int i = 0;i<LEN - sz;i++)
		res.push_back(0);
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	freopen("B-large.in.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d",&T);
	for(int t = 1;t<=T;t++) {
		scanf("%d %d %d", &A, &B, &K);
		A--;
		B--;
		K--;
		a = toBinary(A);
		b = toBinary(B);
		k = toBinary(K);
		for(int i = 0;i<LEN;i++)
			for(int a = 0;a<2;a++)
				for(int b = 0;b<2;b++)
					for(int c = 0;c<2;c++)
						D[i][a][b][c] = -1;
		printf("Case #%d: %lld\n", t, solve(0, 0, 0, 0));
	}
    return 0;
}
