#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <bitset>

using namespace std;

#define ll long long

const int N = 1000011;
int mem[N];
int b[N];

int flip(int j) {
	int ans = 0;
	while (j > 0) {
		ans *= 10;
		ans += j % 10;
		j /= 10;
	}
	return ans;
}

void doit() {
	b[0] = 1;
	mem[1] = 1;
	int kn = 1, i = 0;
	while (i < kn) {
		int cur = b[i++];
		if (cur + 1 < N && mem[cur + 1] == -1) {
			mem[cur + 1] = mem[cur] + 1;
			b[kn++] = cur + 1;
		}
		int fl = flip(cur);
		if (fl < N && mem[fl] == -1) {
			mem[fl] = mem[cur] + 1;
			b[kn++] = fl;
		}
	}
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	int t;
	cin >> t;
	fill(mem, mem + N, -1);
	doit();
	for (int jj = 0; jj < t; jj++) {
		int n;
		cin >> n;
		cout << "Case #" << jj + 1 << ": " <<  mem[n] << endl; 
	}

	return 0;
}