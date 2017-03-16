#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int mat[52][52];

bool solve(int B, ll M) {
	memset(mat, 0, sizeof(mat));
	ll b = 1LL << (B-2);
	if (b < M)
		return false;
	for (int y = 1; y < B-1; y++) {
		for (int x = y+1; x < B; x++) {
			mat[y][x] = 1;
		}
	}
	if (b == M) {
		for (int i = 1; i < B; i++)
			mat[0][i] = 1;
	} else {
		mat[0][B-1] = 0;
		ll c = M;
		for (int i = B-2; i >= 1; i--) {
			mat[0][i] = (c&1 ? 1 : 0);
			c >>= 1;
		}
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int B;
		ll M;
		cin >> B >> M;
		bool ans = solve(B, M);
		cout << "Case #" << i+1 << ": " << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
		if (ans) {
			for (int y = 0; y < B; y++) {
				for (int x = 0; x < B; x++) {
					cout << mat[y][x];
				}
				cout << endl;
			}
		}
	}
}
